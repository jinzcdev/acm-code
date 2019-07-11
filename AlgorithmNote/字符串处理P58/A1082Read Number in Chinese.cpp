// https://pintia.cn/problem-sets/994805342720868352/problems/994805385053978624
#include <cstdio>
#include <cstring>
char num[10][5] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
char wei[5][5] = {"Shi","Bai","Qian","Wan","Yi"};

int main(){
    char str[15];
    scanf("%s",str);
    int len = strlen(str);
    int left = 0,right = len - 1;
    if(str[0] == '-'){
        left++;
        printf("Fu"); // 如果为负数,输出"Fu"
    }
    while(left + 4 <= right){
        right -=4;  // 将right下标左移4位,直到与left在同一4位数部分中
    }
    while(left < len){  // 每次循环处理一个部分(每4位为一部分)
        bool flag = false;  // 该位前是否包含0.
        bool isPrint = false;   // 表示该位是否被输出
        while(left <= right){   // 该循环结束表示该部分处理完毕
            if(left > 0 && str[left] == '0'){   // 如果当前位为0
                flag = true;
            }else{  // 如果当前位不为0
                if(flag == true){
                    printf(" ling");
                    flag = false;
                }
                if(left > 0) printf(" ");
                printf("%s",num[str[left] - '0']);  // 输出当前数字
                isPrint = true;
                if(left != right){
                    printf(" %s",wei[right - left - 1]); // 除了个位, 其他位都需要输出十百千
                }
            }
            left++;
        }
        if(isPrint == true && right != len - 1){
            printf(" %s",wei[(len - 1 - right) / 4 + 2]);
        }
        right += 4; // 右移4位,输出下一部分
    }
    return 0;
}