#include <stdio.h>
#include <string.h>
#include <math.h>

void change(char data[50], int calculate[]) {
    int save = 0, i, j = 0, temp = 0, flag = 0, negative = 0;
    for (i = 0; i < strlen(data); i++) {
        if ((int)data[i] <= 57 && (int)data[i] >= 48) {
            save *= 10;
            save += (int)data[i] - 48;
        }
        else if (data[i] == '(' || data[i] == ')') {
            if (j == 0 && flag == 0) {
                temp = save;
                save = 0;
                flag++;
            }
            else {
                calculate[j] = save;
                save = 0;
                j++;
            }
        }
        else if (data[i] == '/') {
            calculate[j] = save;
            save = 0;
            j++;
        }
        else if (data[i] == '-') {
            negative = 1;
        }
        if (i == strlen(data) - 1 && j == 1) {
            calculate[j] = save;
            save = 0;
            j++;
        }
    }
    calculate[0] = calculate[0] + calculate[1] * temp;
    if (negative == 1) {
        calculate[0] *= -1;
    }
}

int add(int calculate, int calculate_two){
    return calculate + calculate_two;
}

int subtract(int calculate, int calculate_two){
    return calculate - calculate_two;
}

int multiply(int calculate, int calculate_two){
    return calculate * calculate_two;
}

int divide(int calculate, int calculate_two){
    return calculate / calculate_two;
}

void reduceFraction(int *numerator, int *denominator) {
    int gcd = 1;
    for (int i = 1; i <= *numerator && i <= *denominator; i++) {
        if (*numerator % i == 0 && *denominator % i == 0) {
            gcd = i;
        }
    }
    *numerator /= gcd;
    *denominator /= gcd;
}

int main() {
    char data[50], data_two[50], choose[50], point[50];
    int i, j = 0, flag_error = 0, calculate[2], calculate_two[2], result[3], final_result[50][3];

    while (1) {
        scanf("%s", data);
        change(data, calculate);
        scanf("%s", point);
        scanf("%s", data_two);
        change(data_two, calculate_two);

        if (calculate_two[1] == 0 || calculate[1] == 0 || (calculate_two[0] == 0 && point[0] == '/')) {
            result[0] = 0;
            result[1] = 0;
            result[2] = 0;
            flag_error = 1;
        }

        if (flag_error == 0) {
            switch (point[0]) {
                case '+':
                    result[1] = add(calculate[0], calculate_two[0]);
                    result[2] = calculate[1];
                    break;
                case '-':
                    result[1] = subtract(calculate[0], calculate_two[0]);
                    result[2] = calculate[1];
                    break;
                case '*':
                    result[1] = multiply(calculate[0], calculate_two[0]);
                    result[2] = multiply(calculate[1], calculate_two[1]);
                    break;
                case '/':
                    result[1] = multiply(calculate[0], calculate_two[1]);
                    result[2] = multiply(calculate[1], calculate_two[0]);
                    break;
                default:
                    printf("Invalid operation\n");
                    return 1;
            }

            // Reduce the fraction
            reduceFraction(&result[1], &result[2]);
            result[0] = result[1] / result[2];
            result[1] %= result[2];
        }

        final_result[j][0] = flag_error;
        final_result[j][1] = result[1];
        final_result[j][2] = result[2];

        j++;
        flag_error = 0;

        scanf("%s", choose);
        if (choose[0] == 'n') {
            break;
        }
    }

    for (i = 0; i < j; i++) {
        if (final_result[i][0] == 1) {
            printf("error\n");
        } else if (final_result[i][1] == 0) {
            printf("0\n");
        } else if (final_result[i][0] == 0) {
            printf("%d/%d\n", final_result[i][1], final_result[i][2]);
        } else {
            printf("%d(%d/%d)\n", final_result[i][0], final_result[i][1], final_result[i][2]);
        }
    }

    return 0;
}
