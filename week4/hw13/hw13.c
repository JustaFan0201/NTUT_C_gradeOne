#include <stdio.h>
#include <string.h>
#include <math.h>

void sol(int x1, int y1, int x2, int y2, int* result[50][4], int flag) {
    int i, m1, m2, b1, b2;
    m1 = (y1 - y2);
    m2 = (x1 - x2);
    b1 = (x2 * y1 - x1 * y2);
    b2 = (x2 - x1);
    if (m1 < 0 && m2 < 0) {
        m1 *= -1;
        m2 *= -1;
    }
    if (b1 < 0 && b2 < 0) {
        b1 *= -1;
        b2 *= -1;
    }
    if (m1 < 0 || m2 < 0) {
        m1 = -1 * abs(m1);
        m2 = abs(m2);
    }
    if (b1 < 0 || b2 < 0) {
        b1 = -1 * abs(b1);
        b2 = abs(b2);
    }
    for (i = 99; i > 0; i--) {
        if (m1 % i == 0 && m2 % i == 0) {
            m1 /= i;
            m2 /= i;
        }
        if (b1 % i == 0 && b2 % i == 0) {
            b1 /= i;
            b2 /= i;
        }
    }
    result[flag][0] = m1;
    result[flag][1] = m2;
    result[flag][2] = b1;
    result[flag][3] = b2;
}

int main() {
    int i, j, x1, x2, y1, y2, num, *result[50][4], flag;
    float m, b;
    flag = 0;
    scanf("%d", &num);
    for (i = 0; i < num; i++) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        sol(x1, y1, x2, y2, result, flag);
        flag++;
    }

    for (i = 0; i < num; i++) {
        int m1 = result[i][0];
        int m2 = result[i][1];
        int b1 = result[i][2];
        int b2 = result[i][3];
        m=m1/1.0/m2;
        b=b1/1.0/b2;
        int m_flag = (m1 % m2 == 0) ? 1 : 0;
        int b_flag = (b1 % b2 == 0) ? 1 : 0;
        // 判斷 m 和 b 的正負號
        int m_sign = (m1 * m2 >= 0) ? 1 : 0;
        int b_sign = (b1 * b2 >= 0) ? 1 : 0;
        if(m==1){
            if(b==0){
                printf("y = x\n",b);
            }
            else if(b_sign==1){
                if(b_flag==1){
                    printf("y = x + %.0f\n",b);
                }
                else{
                    printf("y = x + %d/%d\n",b1,b2);
                }
            }
            else{
                if(b_flag==1){
                    printf("y = x - %.0f\n",b*-1);
                }
                else{
                    printf("y = x - %d/%d\n",b1*-1,b2);
                }
            }
        }
        else if(m==-1){
            if(b==0){
                printf("y = -x\n",b);
            }
            else if(b_sign==1){
                if(b_flag==1){
                    printf("y = -x + %.0f\n",b);
                }
                else{
                    printf("y = -x + %d/%d\n",b1,b2);
                }
            }
            else{
                if(b_flag==1){
                    printf("y = -x - %.0f\n",b*-1);
                }
                else{
                    printf("y = -x - %d/%d\n",b1*-1,b2);
                }
            }
        }
        else if(m==0){
            if(b==0){
                printf("y = 0\n",b);
            }
            else if(b_sign==1){
                if(b_flag==1){
                    printf("y = %.0f\n",b);
                }
                else{
                    printf("y = %d/%d\n",b1,b2);
                }
            }
            else{
                if(b_flag==1){
                    printf("y = %.0f\n",b);
                }
                else{
                    printf("y = %d/%d\n",b1,b2);
                }
            }
        }
        else{
            if(b==0){
                if(m_flag==1){
                    printf("y = %.0fx\n",m);
                }
                else{
                    printf("y = %d/%dx\n",m1,m2);
                }
            }
            else{
                if(m_flag==1){
                    if(b_sign==1){
                        if(b_flag==1){
                            printf("y = %.0fx + %.0f\n",m,b);
                        }
                        else{
                            printf("y = %.0fx + %d/%d\n",m,b1,b2);
                        }
                    }
                    else{
                        if(b_flag==1){
                            printf("y = %.0fx - %.0f\n",m,b*-1);
                        }
                        else{
                            printf("y = %.0fx - %d/%d\n",m,b1*-1,b2);
                        }
                    }
                }
                else{
                    if(b_sign==1){
                        if(b_flag==1){
                            printf("y = %d/%dx + %.0f\n",m1,m2,b);
                        }
                        else{
                            printf("y = %d/%dx + %d/%d\n",m1,m2,b1,b2);
                        }
                    }
                    else{
                        if(b_flag==1){
                            printf("y = %d/%dx - %.0f\n",m1,m2,b*-1);
                        }
                        else{
                            printf("y = %d/%dx - %d/%d\n",m1,m2,b1*-1,b2);
                        }
                    }
                }
            }
        }
    }


    return 0;
}
