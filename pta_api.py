from tkinter import E
import requests
import json
import time
import os

payload = {}
headers = {
    'Accept': 'application/json;charset=UTF-8',
    'Cookie': 'PTASession=xxxxxxxxxxxxxxxxxxxxxx;'
}


problem_set_id = 994805046380707840

root_path = "./团体程序设计天梯赛-练习集"

# in ('CODE_COMPLETION', 'PROGRAMMING')
problem_type = "PROGRAMMING"

# in ('programmingSubmissionDetail', 'codeCompletionSubmissionDetail')
submission_detail = "programmingSubmissionDetail"

url_problem_list = f"https://pintia.cn/api/problem-sets/{problem_set_id}/problem-list?problem_type={problem_type}"
url_api_problem = "https://pintia.cn/api/problem-sets/" + \
    str(problem_set_id) + "/problems/{}"
url_problem = "https://pintia.cn/problem-sets/" + \
    str(problem_set_id) + "/problems/{}"

response_problem_list = requests.request(
    "GET", url_problem_list, headers=headers, data=payload)
j_problem_list = json.loads(response_problem_list.text)
for problem in j_problem_list['problemSetProblems']:
    if not os.path.exists(root_path):
        os.mkdir(root_path)
    filename = os.path.join(
        root_path, f'{problem["label"]} {problem["title"]}.cpp')
    time.sleep(0.2)
    response_problem = requests.request(
        "GET", url_api_problem.format(problem["id"]), headers=headers)
    problem_data = json.loads(response_problem.text)
    if int(problem_data['problemSetProblem']['lastSubmissionId']) == 0:
        continue
    print(filename, url_problem.format(problem["id"]))
    try:
        with open(filename, 'w') as f:
            program: str = problem_data['problemSetProblem']['lastSubmissionDetail'][submission_detail]['program']
            if program.lstrip()[:30].find('https') == -1:
                f.write(f'// {url_problem.format(problem["id"])}\n')
            f.write(problem_data['problemSetProblem']
                    ['lastSubmissionDetail'][submission_detail]['program'])
    except Exception as e:
        print(e)
        print(f'{problem["id"]} failed')
        # print(response.text)
