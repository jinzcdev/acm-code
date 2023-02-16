import requests
import json
import time
import os
import os.path as osp
import math
from urllib import parse
import logging
from tqdm import tqdm
import re


logging.basicConfig(
    level=logging.INFO,
    filename="pta.log",
    filemode="a",
    format=""
    # format="%(asctime)s - %(pathname)s[line:%(lineno)d] - %(levelname)s: %(message)s",
)

ptype2detail = {
    "PROGRAMMING": "programmingSubmissionDetail",
    "CODE_COMPLETION": "codeCompletionSubmissionDetail",
    "MULTIPLE_FILE": "multipleFileSubmissionDetail",
}
pbtype2name = {
    "PROGRAMMING": "编程题",
    "CODE_COMPLETION": "函数题",
    "MULTIPLE_FILE": "多文件编程题",
}
compiler2suffix = {
    "GCC": "c",
    "GXX": "cpp",
    "CLANG": "c",
    "CLANGXX": "cpp",
    "JAVAC": "java",
    "PYTHON2": "py",
    "PYTHON3": "py",
    "NODE": "js",
}


def requestData2Json(
    method="GET",
    url=None,
    headers={"Accept": "application/json;charset=UTF-8"},
    data=None,
):
    """Get the response in text"""
    response = requests.request(method, url, headers=headers, data=data)
    return json.loads(response.text)


def get_problem_summary(psID):
    data = requestData2Json(
        url=f"https://pintia.cn/api/problem-sets/{psID}/problem-summaries"
    )
    return data["summaries"]


def get_problem_type(psID):
    """Get the type of problem corresponding problem sets"""
    return tuple(get_problem_summary(psID).keys())


def get_problem_set_name(psID):
    data = requestData2Json(
        url=f"https://pintia.cn/api/problem-sets/{psID}/exams")
    return data["problemSet"]["name"]


def get_problem_set_exam_status(psID, pta_session):
    data = requestData2Json(
        url=f"https://pintia.cn/api/problem-sets/{psID}/exam-problem-status",
        headers={
            "Accept": "application/json;charset=UTF-8",
            "Cookie": f"PTASession={pta_session};",
        },
    )
    return data["problemStatus"]


def get_problem_sets():
    pb_sets: list = requestData2Json(
        url="https://pintia.cn/api/problem-sets/always-available"
    )["problemSets"]
    ids = []
    for x in pb_sets:
        ids.append(x["id"])
        print(x["id"], x["name"])
    return ids


def get_problem_exam_status(psID, headers):
    data = requestData2Json(
        url=f"https://pintia.cn/api/problem-sets/{psID}/exam-problem-status",
        headers=headers,
    )
    data = filter(
        lambda x: x["problemSubmissionStatus"] != "PROBLEM_NO_ANSWER",
        data["problemStatus"],
    )
    d = dict()
    for x in data:
        d[x["id"]] = x
    return d


def checkLoginToken(pta_session):
    data = requestData2Json(
        url="https://pintia.cn/api/u/current",
        headers={
            "Accept": "application/json;charset=UTF-8",
            "Cookie": f"PTASession={pta_session};",
        },
    )
    return "user" in data


def formatCode(s):
    i = 0
    while i < len(s) and s[i] in (" ", "\n"):
        i = i + 1
    lines = s[i:].split("\n")
    i = 0
    while i < len(lines) and lines[i].find("http") != -1:
        i += 1
    return "\n".join(lines[i:])


def export_all_problem_list():
    ps_ids = get_problem_sets()
    d = dict()
    for psID in ps_ids:
        problem_list = []
        pb_set_name = get_problem_set_name(psID)
        summaries = get_problem_summary(psID)
        pb_types = summaries.keys()
        for ptype in pb_types:
            total_problems = summaries[ptype]["total"]
            data = []
            for i in range(math.ceil(total_problems / 200)):
                time.sleep(0.1)
                data += requestData2Json(
                    url=f"https://pintia.cn/api/problem-sets/{psID}/problem-list?problem_type={ptype}&page={i}&limit=200"
                )["problemSetProblems"]
            for item in data:
                problem_list.append(
                    {
                        "psID": psID,
                        "pID": item["id"],
                        "title": item["title"],
                        "label": item["label"],
                        "score": item["score"],
                        "type": item["type"],
                    }
                )
        d[pb_set_name] = problem_list
    with open("data.json", "w") as f:
        f.write(json.dumps(d, ensure_ascii=False))


def format_problem_set_name(name: str) -> str:
    name = re.sub(r"\uFF08|\uFF09",
                  lambda x: "(" if x.group() == "\uFF08" else ")", name)
    # "《》—、：" -> "\uFF1A\u300A\u300B\u2014\u3001"
    name = re.sub(
        r"[\u3000-\u303F\s\-\uFF1A\u300A\u300B\u2014\u3001]", "_", name)
    name = re.sub(r"^_+|_+$", "", name)
    name = re.sub(r"_+", "_", name)
    return name


def get_dashboard():
    data = requestData2Json(
        url="https://pintia.cn/api/content/dashboard")["content"]
    return data


def exportExamStatus(pta_session, file_path="./exam.md"):
    """export all examination status by `list`& `table` in markdown"""
    cnt = 1
    problem_sets = get_problem_sets()
    data = dict()
    for psID in problem_sets:
        time.sleep(0.05)
        summaries = get_problem_summary(psID)
        ps_name = get_problem_set_name(psID)
        d = dict()
        for ptype in summaries.keys():
            d[ptype] = {"sum": 0, "right": 0}
        status = get_problem_set_exam_status(psID, pta_session)
        for item in status:
            d[item["problemType"]]["sum"] += 1
            if item["problemSubmissionStatus"] == "PROBLEM_ACCEPTED":
                d[item["problemType"]]["right"] += 1
        # logging.info(d)
        data[ps_name] = d
    # print in list
    for ps_name in data:
        logging.info(f"{cnt}. {ps_name}")
        cnt += 1
        for ptype in data[ps_name]:
            logging.info(
                f"    - {pbtype2name.get(ptype, 'unknown')}: {data[ps_name][ptype]['right']}/{data[ps_name][ptype]['sum']}"
            )
    # print in table
    logging.info("| 题集 | 函数题 | 编程题 | 多文件编程题 |")
    logging.info("| :-: | :-: | :-: | :-: |")
    for ps_name in data:
        problem_set = data[ps_name]
        d = {
            "CODE_COMPLETION": "\\\\",
            "PROGRAMMING": "\\\\",
            "MULTIPLE_FILE": "\\\\",
        }
        for ptype in problem_set:
            d[ptype] = f"{problem_set[ptype]['right']}/{problem_set[ptype]['sum']}"
        logging.info(f"| {' | '.join([ps_name] + list(d.values()))} |")


def exportSolution(pta_session, psID, root_path="./exported"):
    """
    Args:
        pta_session (str): PTASession to login in PTA.
        root_path (str): Path to save the exported solutions.
        psid (str): The ID of problem set.

    Return (list): Problems with wrong answer.
    """
    if not checkLoginToken(pta_session):
        logging.info("PTASession is expired!!")
        return

    headers = {
        "Accept": "application/json;charset=UTF-8",
        "Cookie": f"PTASession={pta_session};",
    }

    exportedIDs = []

    problem_types = get_problem_type(psID)
    ps_name = format_problem_set_name(get_problem_set_name(psID))
    root_path = osp.join(root_path, ps_name)
    os.makedirs(root_path, exist_ok=True)

    logging.info(f"Problem Set: {root_path.split('/')[-1]}")

    exam_status = get_problem_exam_status(psID, headers)
    summaries = get_problem_summary(psID)

    wrong_problems = []
    d_summary = dict()

    # make problem type directory
    for ptype in problem_types:
        assert ptype in ptype2detail
        d_summary[ptype] = []
        pb_type = pbtype2name[ptype]
        save_dir = osp.join(root_path, pb_type)
        # if len(problem_types) > 1 else root_path
        os.makedirs(save_dir, exist_ok=True)

    # url_problem_list = f"https://pintia.cn/api/problem-sets/{psID}/problem-list?problem_type={ptype}"
    url_api_problem = "https://pintia.cn/api/problem-sets/" + \
        str(psID) + "/problems/{}"
    url_problem = "https://pintia.cn/problem-sets/" + \
        str(psID) + "/exam/problems/{}"

    print(ps_name)
    for pID in tqdm(exam_status.keys()):
        time.sleep(0.15)
        problem_data = requestData2Json(
            url=url_api_problem.format(pID), headers=headers
        )["problemSetProblem"]
        status = exam_status[pID]
        if status["problemSubmissionStatus"] == "PROBLEM_WRONG_ANSWER":
            wrong_problems.append(
                f"[{problem_data['title']}]({url_problem.format(pID)})"
            )

        if status["problemSubmissionStatus"] != "PROBLEM_ACCEPTED":
            continue
        try:
            ptype = problem_data["type"]
            pb_type = pbtype2name[ptype]
            submission_detail = problem_data["lastSubmissionDetail"][
                ptype2detail[ptype]
            ]
            # Only one compiler is allowed, so get the type of that compiler in 'problemSetProblem'
            compiler = (
                problem_data["compiler"]
                if ptype == "CODE_COMPLETION"
                else submission_detail["compiler"]
            )
            filename = f'{problem_data["label"]} {problem_data["title"]}.{compiler2suffix[compiler]}'
            save_path = osp.join(osp.join(root_path, pb_type), filename)
            # logging.info(save_path, url_problem.format(pID))
            program = submission_detail["program"]
            with open(save_path, "w") as f:
                program = formatCode(program)
                f.write(
                    f"{'#' if compiler2suffix[compiler] == 'py' else '//'} {url_problem.format(pID)}\n"
                )
                f.write(formatCode(program))

            exportedIDs.append((pID, problem_data["lastSubmissionId"]))

            # export README.md
            source_code_path = f"{ps_name}/{pb_type}/{filename}"
            # if len(problem_types) > 1 else f"{ps_name}/{filename}"
            url = f"https://github.com/jinzcdev/PTA/blob/main/{parse.quote(source_code_path)}"
            # logging.info(f"[{problem['label']}. {problem['title']}]({url})\n")
            if d_summary.get(ptype, None) == None:
                d_summary[ptype] = []
            d_summary[ptype].append(
                f"- [{problem_data['label']}. {problem_data['title']}]({url})\n"
            )

        except Exception as e:
            logging.info(e)
            logging.info(f"{pID} failed")

    with open(osp.join(root_path, "README.md"), "w") as readme:
        for ptype in d_summary:
            readme.write(
                f"\n## {pbtype2name[ptype]} ({len(d_summary[ptype])}/{summaries[ptype]['total']})\n\n"
            )
            for md_item in d_summary[ptype]:
                readme.write(md_item)

    if len(wrong_problems) > 0:
        logging.info("Wrong Answered Problems:")
        for i, item in enumerate(wrong_problems):
            logging.info(f"{i + 1}.{item}")

    return exportedIDs


def rename():
    for root, dirs, files in os.walk("./"):
        for f in files:
            if f.endswith(".md"):
                file_path = os.path.join(root, f)
                logging.info(file_path)
                data = []
                with open(file_path, "r") as readme:
                    data = readme.readlines()
                logging.info(data)
                for i in range(len(data)):
                    data[i] = data[i].replace(
                        "https://github.com/jinzcdev/PTA",
                        "https://github.com/jinzcdev/PTA/blob/main",
                    )
                with open("./data.md", "w") as ff:
                    ff.write("\n".join(data))
                break


if __name__ == "__main__":
    root_path = "./"
    pta_session = "{Your_session}"
    d = dict()
    pb_sets = get_problem_sets()
    for psID in pb_sets:
        exportedIDs = exportSolution(
            pta_session,
            psID,
            root_path=root_path,
        )
        d[psID] = exportedIDs
    with open(osp.join(root_path, "./finished.txt"), "w") as finished_file:
        for psID in d:
            for pID, submissionID in d[psID]:
                finished_file.write(f"{psID} {pID} {submissionID}\n")
