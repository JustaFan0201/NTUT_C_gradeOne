#include <stdio.h>
#include <string.h>

char* sol(int num, int data) {
    static char result[50];
    int i;
    for (i = num - 1; i >= 0; i--) {
        if (data % 2 == 0) {
            result[i] = '0';
        } else {
            result[i] = '1';
        }
        data = data / 2;
    }
    return result;
}

char* sol2(int num, char data[50]) {
    static char result[50];
    int i;
    result[0] = data[0];
    for (i = 1; i < num; i++) {
        if (data[i] == data[i - 1]) {
            result[i] = '0';
        } else {
            result[i] = '1';
        }
    }
    result[num] = '\0'; // 添加字符串結尾
    return result;
}

int main() {
    int data[10], i;
    char results[10][50]; // 用來存儲多個字串
    int count = 0;
    while (1) {
        scanf("%d", &data[0]);
        if (data[0] == -1) {
            break;
        }
        scanf("%d", &data[1]);
        if (data[0] == 1) {
            if (data[1] == 0) {
                strncpy(results[count], "0", sizeof(results[count]) - 1);
            } else {
                strncpy(results[count], "1", sizeof(results[count]) - 1);
            }
        } else {
            strncpy(results[count], sol(data[0], data[1]), sizeof(results[count]) - 1);
            strncpy(results[count], sol2(data[0], results[count]), sizeof(results[count]) - 1);
        }

        count++; // 增加輸入次數
    }
    // 輸出結果
    for (i = 0; i < count; i++) {
        printf("%s\n", results[i]);
    }
    return 0;
}
