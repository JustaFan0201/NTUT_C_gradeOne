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
int add(calculate,calculate_two){
    int result=0;
    result=calculate+calculate_two;
    return result;
}
int miner(calculate,calculate_two){
    int result=0;
    result=calculate-calculate_two;
    return result;
}
int power(calculate,calculate_two){
    int result=0;
    result=calculate*calculate_two;
    return result;
}
void count(int calculate[2],int calculate_two[2],char point, int result[3]) {
    int temp,flag=0,calculate_save=0,calculate_save_two=0,negative=0;
    if(calculate[1]==calculate_two[1]){
        printf("");
    }
    else{
        temp=calculate[1];
        calculate[0]*=calculate_two[1];
        calculate[1]*=calculate_two[1];
        calculate_two[0]*=temp;
        calculate_two[1]*=temp;
    }
    if(point=='+'){
        calculate_save=add(calculate[0],calculate_two[0]);
        calculate_save_two=calculate[1];
    }
    else if(point=='-'){
        calculate_save=miner(calculate[0],calculate_two[0]);
        calculate_save_two=calculate[1];
    }
    else if(point=='*'){
        calculate_save=power(calculate[0],calculate_two[0]);
        calculate_save_two=power(calculate[1],calculate_two[1]);
    }
    else if(point=='/'){
        calculate_save=power(calculate[0],calculate_two[1]);
        calculate_save_two=power(calculate[1],calculate_two[0]);
    }
    if(calculate_save<0){
        calculate_save*=-1;
        negative=1;
    }
    while(calculate_save>=calculate_save_two){
        calculate_save-=calculate_save_two;
        flag++;
    }
    if(negative==1&&flag!=0){
        flag*=-1;
    }
    else if(negative==1&&flag==0){
        calculate_save*=-1;
    }
    if(calculate_save!=0){
        for(int i=500;i>0;i--){
            if(calculate_save%i==0 && calculate_save_two %i==0){
                calculate_save/=i;
                calculate_save_two/=i;
            }
        }
    }

    result[0]=flag;
    result[1]=calculate_save;
    result[2]=calculate_save_two;
}

int main() {
    char data[50], data_two[50], choose[50], point[50];
    int i,j=0,flag_error=0,calculate[2], calculate_two[2],result[3],final_result[50][3];
    while (1) {
        scanf("%s", data);
        change(data, calculate);
        scanf("%s", point);
        scanf("%s", data_two);
        change(data_two, calculate_two);
        if(calculate_two[1]==0 || calculate[1]==0 || (calculate_two[0]==0&&point[0]=='/')){
            result[0]=0;
            result[1]=0;
            result[2]=0;
            flag_error=1;
        }
        if(flag_error==0){
            count(calculate,calculate_two,point[0],result);
        }
        for(i=0;i<3;i++){
            final_result[j][i]=result[i];
        }
        j++;
        flag_error=0;
        scanf("%s", choose);
        if (choose[0] == 'n') {
            break;
        }
    }
    for(i=0;i<j;i++){
        if(final_result[i][0]==0&&final_result[i][1]==0&&final_result[i][2]==0){
            printf("error\n");
        }
        else if(final_result[i][1]==0&&final_result[i][0]!=0){
            printf("%d\n",final_result[i][0]);
        }
        else if(final_result[i][1]==0){
            printf("0\n");
        }
        else if(final_result[i][0]==0){
            printf("%d/%d\n",final_result[i][1],final_result[i][2]);
        }
        else{
            printf("%d(%d/%d)\n",final_result[i][0],final_result[i][1],final_result[i][2]);
        }
    }
    return 0;
}
