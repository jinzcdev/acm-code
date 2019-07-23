#include <cstdio>
const int maxn = 10;

int A[maxn];
int n;

/**
 * 比较 n 趟排序
 */
void selectSort(){
    for(int i = 0; i < n; i++){
        int k = i;
        for (int j = i; j < n; j++){
            if(A[j] < A[k]){
                k = j;
            }
        }
        int temp = A[i];
        A[i] = A[k];
        A[k] = temp;
    }
}

/**
 * 比较 n - 1 趟
 */
void insertSort(){
    for (int i = 1; i < n; i++){ // 从第二个元素开始
        int temp = A[i], j = i;
        while(j > 0 && temp < A[j - 1]){ // j 大于首元素的索引
            A[j] = A[j - 1];
            j--;
        }
        A[j] = temp;
    }
}

int main(){
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        scanf("%d",A + i);
    }
    // selectSort();
    insertSort();
    for (int i = 0; i < n; i++){
        printf("%d ",*(A + i));
    }
    
    return 0;
}