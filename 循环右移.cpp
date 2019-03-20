#include<cstdio>
int main(){
  int arr[100],a[100];
  int n,m;
  scanf("%d %d",&n,&m);

  int i;
  for(i = 0;i < n;i++ ){
    scanf("%d",arr+i);
  }

  if(n == m){
    for(int i = 0;i < n;i++){
      printf("%d",arr[i]);
      if(i < n-1)
        printf(" ");
    }
    return 0;
  }
  else if(m > n){
    m = m % n;
  }
  for(int i = 0; i < m;i++)
    a[i] = arr[i + n - m];
  for(int i = m;i < n;i++)
    a[i] = arr[i - m];

  for(i = 0;i < n;i++ ){
    printf("%d",a[i]);
    if(i < n-1)
      printf(" ");
  }
  return 0;
}