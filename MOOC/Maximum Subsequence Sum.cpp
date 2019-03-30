#include <cstdio>
const int maxn = 10010;
int main(){
  int k,a[maxn];
  scanf("%d",&k);
  for(int i = 0;i < k;i++)
    scanf("%d",a + i);
  int thisSum = 0,maxSum = 0,thisFirst = 0,maxFisrt = 0,thisLast,maxLast;
  for(int i = 0;i < k;i++){
    thisSum += a[i];
    if(thisSum > maxSum){
      maxSum = thisSum;
      maxFisrt = thisFirst;
      maxLast = thisLast = i;
    }else if(thisSum < 0){
      thisSum = 0;
      thisFirst = i + 1;
    }
  }
  if(maxSum == 0)
    printf("0 %d %d",a[0],a[k - 1]);
  else
    printf("%d %d %d",maxSum,maxFisrt,maxLast);
  return 0;
}