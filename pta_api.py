import requests
import json
import time
import os
import os.path as osp
import math

ptype2detail = {
    "PROGRAMMING": "programmingSubmissionDetail",
    "CODE_COMPLETION": "codeCompletionSubmissionDetail"
}
ptype2name = {
    "PROGRAMMING": "编程题",
    "CODE_COMPLETION": "函数题"
}
compiler2suffix = {
    "GCC": "c",
    "GXX": "cpp",
    "CLANG": "c",
    "CLANGXX": "cpp",
    "JAVAC": "java",
    "PYTHON2": "py",
    "PYTHON3": "py",
    "NODE": "js"
}


def requestData2Json(method="GET", url=None, headers={'Accept': 'application/json;charset=UTF-8'}, data=None):
    """Get the response in text"""
    response = requests.request(method, url, headers=headers, data=data)
    return json.loads(response.text)

def get_problem_summary(psID):
    data = requestData2Json(
        url=f"https://pintia.cn/api/problem-sets/{psID}/problem-summaries")
    return data["summaries"]

def get_problem_type(psID):
    """Get the type of problem corresponding problem sets"""
    return tuple(get_problem_summary().keys())


def get_problem_set_name(psID):
    data = requestData2Json(
        url=f"https://pintia.cn/api/problem-sets/{psID}/exams")
    return data["problemSet"]["name"]


def get_problem_sets():
    problem_sets: list = requestData2Json(
        url="https://pintia.cn/api/problem-sets/always-available")["problemSets"]
    ids = []
    for x in problem_sets:
        ids.append(x["id"])
        if x["id"] in ('994805260223102976', '994805342720868352', '17', '15', '14'):
            print(x["id"], x["name"])
    return ids


def get_problem_exam_status(psID, headers):
    data = requestData2Json(
        url=f"https://pintia.cn/api/problem-sets/{psID}/exam-problem-status", headers=headers)
    data = data["problemStatus"]
    d = dict()
    for x in data:
        d[x["id"]] = x
    return d


def checkLoginToken(pta_session):
    data = requestData2Json(url="https://pintia.cn/api/u/current", headers={
        'Accept': 'application/json;charset=UTF-8',
        'Cookie': f'PTASession={pta_session};'
    })
    return "user" in data


def formatCode(s):
    i = 0
    while i < len(s) and s[i] in (' ', '\n'):
        i = i + 1
    return s[i:]


def export_all_problem_list():
    ps_ids = get_problem_sets()
    d = dict()
    for psID in ps_ids:
        problem_list = []
        ps_name = get_problem_set_name(psID)
        summaries = get_problem_summary(psID)
        ptypes = summaries.keys()
        for ptype in ptypes:
            total_problems = summaries[ptype]["total"]
            data = []
            for i in range(math.ceil(total_problems / 200)):
                time.sleep(0.1)
                data += requestData2Json(
                    url=f"https://pintia.cn/api/problem-sets/{psID}/problem-list?problem_type={ptype}&page={i}&limit=200")["problemSetProblems"]
            for item in data:
                problem_list.append({
                    "psID": psID,
                    "pID": item["id"],
                    "title": item["title"],
                    "label": item["label"],
                    "score": item["score"],
                    "type": item["type"]
                })
        d[ps_name] = problem_list
        print(ps_name)
        print(len(problem_list))
    # with open('data.json', 'w') as f:
    #     f.write(json.dumps(d, ensure_ascii=False))
        


def exportSolution(pta_session, psID, root_path="./exported"):
    """
    Args:
        pta_session (str): PTASession to login in PTA.
        root_path (str): Path to save the exported solutions.
        psid (str): The ID of problem set.

    Return (list): Problems with wrong answer.
    """
    if not checkLoginToken(pta_session):
        print("PTASession is expired!!")
        return

    headers = {
        'Accept': 'application/json;charset=UTF-8',
        'Cookie': f'PTASession={pta_session};'
    }

    problem_types = get_problem_type(psID)
    root_path = osp.join(root_path, get_problem_set_name(psID))
    print(f"Problem Set: {root_path.split('/')[-1]}")

    exam_status = get_problem_exam_status(psID, headers)
    wrong_problems = []
    for ptype in problem_types:
        assert ptype in ptype2detail
        detail_type = ptype2detail[ptype]

        save_path = osp.join(root_path, ptype2name[ptype]) if len(
            problem_types) > 1 else root_path
        os.makedirs(save_path, exist_ok=True)

        url_problem_list = f"https://pintia.cn/api/problem-sets/{psID}/problem-list?problem_type={ptype}"
        url_api_problem = "https://pintia.cn/api/problem-sets/" + \
            str(psID) + "/problems/{}"
        url_problem = "https://pintia.cn/problem-sets/" + \
            str(psID) + "/problems/{}"

        problems = requestData2Json(
            url=url_problem_list, headers=headers)['problemSetProblems']
        cntExported = 0
        for problem in problems:
            time.sleep(0.2)
            problem_data = requestData2Json(
                url=url_api_problem.format(problem["id"]), headers=headers)
            status = exam_status[problem["id"]]
            if status["problemSubmissionStatus"] == "PROBLEM_WRONG_ANSWER":
                wrong_problems.append(
                    f"[{problem['title']}]({url_problem.format(problem['id'])})")
            if status["problemSubmissionStatus"] != "PROBLEM_ACCEPTED":
                continue
            try:
                submission_detail = problem_data['problemSetProblem']['lastSubmissionDetail'][detail_type]
                # Only one compiler is allowed, so get the type of that compiler in 'problemSetProblem'
                compiler = problem_data['problemSetProblem']['compiler'] \
                    if ptype == 'CODE_COMPLETION' else submission_detail["compiler"]
                filename = osp.join(
                    save_path, f'{problem["label"]} {problem["title"]}.{compiler2suffix[compiler]}')
                # print(filename, url_problem.format(problem["id"]))
                program = submission_detail['program']
                with open(filename, 'w') as f:
                    if program.lstrip()[:30].find('https') == -1:
                        f.write(
                            f"{'#' if compiler2suffix[compiler] == 'py' else '//'} {url_problem.format(problem['id'])}\n")
                    f.write(formatCode(program))
                cntExported += 1
            except Exception as e:
                print(e)
                print(f'{problem["id"]} failed')
        print(f"{ptype}: {cntExported}/{len(problems)}")
    print("Wrong Answered Problems:")
    for i, item in enumerate(wrong_problems):
        print(f"{i + 1}.{item}")
    print()


if __name__ == '__main__':
    # problem_sets = get_problem_sets()
    # for psID in ('994805260223102976', '994805342720868352', '17', '15', '14'):
    #     exportSolution("65f19a32-1de8-4f26-a6f2-c87d16e939b4",
    #                    psID, root_path="./exportProblems321")
    # export_all_problem_list()
    get_problem_sets()
