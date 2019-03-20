#include <cstdio>
#include <cstdlib>
void quickSort(int* a){
	for (int i = 0; i < 5 - 1; ++i)
	{
		int k = i;
		for (int j = 0; j < 5; ++j)
		{
			if(a[k] > a[j]){
				k == j;
			}
		}
		int temp = a[k];
		a[k] = a[i];
		a[i] = temp;
	}
}
int main(){
	int arr[] = {4,6,2,7,3};
	quickSort(arr);
	int n = 0;
	while(n < 5){
		printf("%d ",arr[n++]);
	}
	system("pause");
}