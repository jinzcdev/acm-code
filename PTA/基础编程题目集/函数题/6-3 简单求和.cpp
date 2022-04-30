// https://pintia.cn/problem-sets/14/problems/735
int Sum ( int List[], int N ){
    if (N == 1) return List[0];
    return List[N - 1] + Sum(List, N - 1);
}