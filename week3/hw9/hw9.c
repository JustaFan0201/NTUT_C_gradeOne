#include <stdio.h>
#include <string.h>
#include <math.h>
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
int sol2(int num, char data[50]) {
    int result = 0;
    int i;
    for (i = num - 1 ; i >= 0; i--) {
        if (data[i] == '1') {
            result += pow(2, num - 1 - i);
        }
    }
    return result;
}
int sol3(int num) {
    int result=0;

    while(1){
        if(num==0 || num == 1){
            return result;
        }
        if(num%2==0){
            num/=2;
            result+=1;
        }
        else{
            num=(num+1)/2;
            result+=1;
        }
    }
}



int main() {
    int no_need, i;
    char data[50], result[10][50];
    int count = 0, save, final_data = 0;
    while (1) {
        scanf("%s", data);
        save = sol2(10, data);
        for (i = 0; i <= save; i++) {
            final_data += sol3(i);
        }
        strncpy(result[count], sol(14, final_data), 14);
        result[count][14] = '\0'; // ²K¥[ null µ²§À¦r²Å
        count++;
        final_data = 0;
        scanf("%d", &no_need);
        if (no_need == -1) {
            break;
        }
    }
    for (i = 0; i < count; i++) {
        printf("%s\n", result[i]);
    }
    return 0;
}
