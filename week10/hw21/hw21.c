#include <stdio.h>
#include <string.h>
int str_split(char data[50][50]){
    char input[200];
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
    return count+1;
}
void same(char temp_data[50][50][50], char data[50][50][50], int len[50], int num) {
    int i, j, count;
    for (i = 0; i < num; i++) {
        count = 0;
        for (j = 0; j < len[i]; j++) {
            if (check(temp_data[i][j], data[i], count) == 1) {
                strncpy(data[i][count], temp_data[i][j], strlen(temp_data[i][j]));
                data[i][count][strlen(temp_data[i][j])+1]='\0';
                count++;
            }
        }
        len[i] = count;
    }
}

void sol(char data[50][50][50],int len[50],int num,int *flag){
    int i,j,k;
    for(i=1;i<num;i++){
        for(j=1;j<num;j++){
            if(i<j){
                if(cmp(data,i,j,len)==1){
                    (*flag)++;
                }
            }
        }
    }
}
int  cmp(char data[50][50][50],int index_one,int index_two,int len[50]){
    int i,j,count=0;
    char check_data[50][50];
    for(i=0;i<len[index_one];i++){
        for(j=0;j<len[index_two];j++){
            if(strcmp(data[index_one][i],data[index_two][j])==0){
                return 0;
            }
        }
    }
    for(i=0;i<len[0];i++){
        for(j=0;j<len[index_one];j++){
            if(strcmp(data[0][i],data[index_one][j])==0){
                count++;
            }
        }
    }
    for(i=0;i<len[0];i++){
        for(j=0;j<len[index_two];j++){
            if(strcmp(data[0][i],data[index_two][j])==0){
                count++;
            }
        }
    }
    if(count==len[0]){
        return 1;
    }
    else{
        return 0;
    }
}
int check(char data[50], char check_data[50][50], int count) {
    for (int i = 0; i < count; i++) {
        if (strcmp(check_data[i], data) == 0) {
            return 0;
        }
    }
    return 1;
}
int main()
{
    char temp_data[50][50][50],data[50][50][50];
    int len[50],num,i,j,flag=0;
    len[0]=str_split(temp_data[0]);
    scanf("%d\n",&num);
    for(i=1;i<=num;i++){
        len[i]=str_split(temp_data[i]);
    }
    same(temp_data,data,len,num+1);
    sol(data,len,num+1,&flag);
    printf("%d",flag);
}
