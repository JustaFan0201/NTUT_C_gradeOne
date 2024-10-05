#include <stdio.h>
#include <string.h>
#include <math.h>

int to_ten(int enter, char data[100]) {
    int i, count = 0;
    for (i = 0; i < strlen(data); i++) {
        if ((int)data[i] <= 57 && (int)data[i] >= 48) {
            count += (((int)data[i] - 48) * (pow(enter, strlen(data) - i - 1)));
        }
        else {
            count += (((int)data[i] - 55) * (pow(enter, strlen(data) - i - 1)));
        }
    }
    return count;
}

char* ten_to(int out, int data) {
    int i = 0,flag=0;
    static char result[50];
    while (1) {
        if (data / out >= out) {
            result[i] = (data % out > 9) ? (data % out) + 55 : (data % out) + 48; // Convert remainder to character
            data /= out;
            flag=1;
            i++;
        } else {
            result[i] = (data % out > 9) ? (data % out) + 55 : (data % out) + 48; // Convert remainder to character
            data /= out;
            i++;
            break;
        }
    }
    if(flag==1)
        result[i++] = (data % out > 9) ? (data % out) + 55 : (data % out) + 48;
    result[i] = '\0'; // Add string terminator
    return result;
}

int main() {
    int i,enter, out, trans_ten = 0;
    char data[100], result[50];
    scanf("%d", &enter);
    scanf("%s", data);
    scanf("%d", &out);
    trans_ten = to_ten(enter, data);
    strncpy(result, ten_to(out, trans_ten), strlen(ten_to(out, trans_ten))); // Use strlen to get the length of the returned string
    for(i=strlen(result)-1;i>=0;i--)
        printf("%c", result[i]);
    return 0;
}
