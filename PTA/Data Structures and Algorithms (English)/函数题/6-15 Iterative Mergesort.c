// https://pintia.cn/problem-sets/16/problems/1046
#include <stdio.h>

#define ElementType int
#define MAXN 100

void merge_pass(ElementType list[], ElementType sorted[], int N, int length);

void output(ElementType list[], int N) {
    int i;
    for (i = 0; i < N; i++) printf("%d ", list[i]);
    printf("\n");
}

void merge_sort(ElementType list[], int N) {
    ElementType extra[MAXN]; /* the extra space required */
    int length = 1;          /* current length of sublist being merged */
    while (length < N) {
        merge_pass(list, extra, N, length); /* merge list into extra */
        output(extra, N);
        length *= 2;
        merge_pass(extra, list, N, length); /* merge extra back to list */
        output(list, N);
        length *= 2;
    }
}

// #include <stdlib.h>
int main() {
    int N, i;
    ElementType A[MAXN];

    scanf("%d", &N);
    for (i = 0; i < N; i++) scanf("%d", &A[i]);
    merge_sort(A, N);
    output(A, N);

    return 0;
}

/* Your function will be put here */
void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

void sort(ElementType *arr, int start, int end) {
    if (start >= end) return;
    int mid = arr[end];
    int left = start, right = end - 1;
    while (left < right) {
        while (arr[left] < mid && left < right) left++;
        while (arr[right] >= mid && left < right) right--;
        swap(&arr[left], &arr[right]);
    }
    if (arr[left] >= arr[end])
        swap(&arr[left], &arr[end]);
    else {
        left++;
        swap(&arr[left], &arr[end]);
    }
    if (left) sort(arr, start, left - 1);
    sort(arr, left + 1, end);
}

void merge_pass(ElementType list[], ElementType sorted[], int N, int length) {
    for (int i = 0; i < N; i++) sorted[i] = list[i];
    length *= 2;
    int i = 0;
    for (; i + length - 1 < N; i += length) sort(sorted, i, i + length - 1);
    if (i <= N) sort(sorted, i, N - 1);
}