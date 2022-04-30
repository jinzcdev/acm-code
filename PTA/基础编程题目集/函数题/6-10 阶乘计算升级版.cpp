// https://pintia.cn/problem-sets/14/problems/742
void Print_Factorial(const int N) {
    if (N < 0) {
        printf("Invalid input\n");
    } else if (N <= 1) {
        printf("1\n");
    } else {
        int ans[10000] = {0}, len = 1;
        ans[0] = 1;
        for (int i = 2; i <= N; i++) {
             // 初始化进位为0, tempLen 临时长度，记录上一次运算后结果的长度
            int carry = 0, tempLen = len;
            len = 0;        // 记录本次计算的位长
            for (int j = 0; j < tempLen; j++) {
                int temp = ans[j] * i + carry;
                ans[len++] = temp % 10;
                carry = temp / 10;
            }
            while (carry != 0) {    // 进位不为0，按位依次添加进结果数组
                ans[len++] = carry % 10;
                carry /= 10;
            }
            // 结束本次运算后，len恰为结果长度
        }
        for (int i = len - 1; i >= 0; i--) {
            printf("%d", ans[i]);
        }
    }
}