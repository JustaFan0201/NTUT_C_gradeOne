#include <stdio.h>
#include <string.h>
void fun_1(char data[100][100],char data_1[50],char data_2[50],int len){
    for(int i=0;i<len;i++){
        if(i==len-1){
            if(strcmp(data[i], data_1) == 0){
                printf("%s",data_2);
            }
            else{
                printf("%s",data[i]);
            }
        }
        else{
            if(strcmp(data[i], data_1) ==0){
                printf("%s ",data_2);
            }
            else{
                printf("%s ",data[i]);
            }
        }
    }
    printf("\n");
}
void fun_2(char data[100][100],char data_1[50],char data_2[50],int len){
    for(int i=0;i<len;i++){
        if(i==len-1){
            if(strcmp(data[i], data_1) == 0){
                printf("%s %s",data_2,data[i]);
            }
            else{
                printf("%s",data[i]);
            }
        }
        else{
            if(strcmp(data[i], data_1) ==0){
                printf("%s %s ",data_2,data[i]);
            }
            else{
                printf("%s ",data[i]);
            }
        }
    }
    printf("\n");
}
void fun_3(char data[100][100],char data_1[50],char data_2[50],int len){
    for(int i=0;i<len;i++){
        if(i==len-1){
            if(strcmp(data[i], data_1) == 0){
                continue;
            }
            else{
                printf("%s",data[i]);
            }
        }
        else{
            if(strcmp(data[i], data_1) ==0){
                continue;
            }
            else{
                printf("%s ",data[i]);
            }
        }
    }
    printf("\n");
}
void fun_4(char data[100][100], int len) {
    char name[100][100];
    int count = 0, rank[50] = {0},max_num=-1,j=0;

    for(int i = 0; i < len; i++) {
        int found = 0;
        for(int j = 0; j < count; j++) {
            if(strcmp(data[i], name[j]) == 0) {
                rank[j] += 1;
                found = 1;
                if(rank[j]>max_num){
                    max_num=rank[j];
                }
                break;
            }
        }
        if(found==0) {
            strcpy(name[count], data[i]);
            rank[count] = 1;
            count++;
        }
    }
    bubble_sort(name, rank, count);
    for(int i = 0; i < count; i++) {
        printf("%s %d\n", name[i], rank[i]);
    }
}
void swap(char str1[], char str2[], int *num1, int *num2) {
    char temp[100];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
    int temp_num = *num1;
    *num1 = *num2;
    *num2 = temp_num;
}

void bubble_sort(char arr[][100], int freq[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (freq[j] < freq[j+1]) {
                swap(arr[j], arr[j+1], &freq[j], &freq[j+1]);
            }
            else if (freq[j] == freq[j+1] && strcmp(arr[j], arr[j+1]) > 0) {
                swap(arr[j], arr[j+1], &freq[j], &freq[j+1]);
            }
        }
    }
}
int main()
{
    char input[200],data_1[50],data_2[50];
    char data[100][100];
    int i=0,j=0,count=0;
    fgets (input,200,stdin);
    for(i=0;i<200;i++){
        if(input[i]==' '&&input[i+1]==' '){
            break;
        }
        else if(input[i]=='\n'){
            break;
        }
        else if(input[i]==' '){
            data[count][j]='\0';
            j=0;
            count++;
        }
        else{
            data[count][j++]=input[i];
        }
    }
    count++;
    scanf("%s",&data_1);
    scanf("%s",&data_2);
    fun_1(data,data_1,data_2,count);
    fun_2(data,data_1,data_2,count);
    fun_3(data,data_1,data_2,count);
    fun_4(data,count);
    return 0;
}
