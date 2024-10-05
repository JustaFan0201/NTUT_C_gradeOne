#include <stdio.h>
#include <string.h>
char* check(char input[200],int len){
    static char result[200];
    int i=0,j=0;
    while(i<180){
        if(input[i]!='-'){
            result[j]=input[i];
            j++;
        }
        i++;
    }
    return result;
}
int battle(char input1[200],char input2[200],int x_len,int y_len){
    int result=-1;
    int i=x_len;
    if(x_len>y_len){
        return 0;
    }
    else if(y_len>x_len){
        return 1;
    }
    else{
        while(i>=0){
            if(input1[i]>input2[i]){
                return 0;
            }
            else if(input1[i]<input2[i]){
                return 1;
            }
            i--;
        }
    }
    return 2;
}

void add(int x[200],int y[200],int choose){
    int i;
    int result[200];
    memset(result,0,200);
    for(i=0;i<choose;i++){
        result[i]=x[i]+y[i];
    }
    for(i=0;i<choose-1;i++){
        if(result[i]>=10){
            result[i]-=10;
            result[i+1]+=1;
        }
    }
    for(i=choose-1;i>=0;i--){
        printf("%d",result[i]);
    }
    printf("\n");
}
void mind(int x[200],int y[200],int choose){
    int i;
    int result[200];
    memset(result,0,200);
    for(i=0;i<choose;i++){
        result[i]=x[i]-y[i];
    }
    for(i=0;i<choose;i++){
        if(result[i]<=0){
            result[i]*=-1;
        }
        else{
            result[i]=10-result[i];
            result[i+1]+=1;
        }
    }
    int flag=0;
    for(i=choose-1;i>=0;i--){
        if(result[i]!=0&&flag==0){
           printf("%d",result[i]);
           flag=1;
        }
        else if(flag==1){
            printf("%d",result[i]);
        }
    }
    printf("\n");
}
void mul(int x[200],int y[200],int x_len,int y_len){
    int i,j;
    int result[200];
    for(i=0;i<200;i++){
        result[i]=0;
    }
    for(i=0;i<x_len;i++){
        for(j=0;j<y_len;j++){
            result[i+j]+=(x[i]*y[j]);
        }
    }
    i=0;
    while(1){
        if(result[i]>=10){
            result[i+1]+=1;
            result[i]-=10;
        }
        else{
            i++;
        }
        if(i>180){
            break;
        }
    }
    int flag=0;
    for(i=199;i>=0;i--){
        if(result[i]!=0&&flag==0){
           printf("%d",result[i]);
           flag=1;
        }
        else if(flag==1){
            printf("%d",result[i]);
        }
    }
    printf("\n");
}
int main(){
    int i,x_len,y_len,x[200],y[200],flag_y=1,flag_x=1,battle_result=-1;
    char choose=-1,choose_2=-1,input1[200],input2[200];
    scanf("%s%s",&input1,&input2);

    x_len=strlen(input1);
    y_len=strlen(input2);

    if(input1[0]=='-'){
        strncpy(input1,check(input1,x_len),x_len-1);
        input1[x_len-1]='\0';
        flag_x=0;
        x_len-=1;
    }
    if(input2[0]=='-'){
        strncpy(input2,check(input2,y_len),y_len-1);
        input2[y_len-1]='\0';
        flag_y=0;
        y_len-=1;
    }
    battle_result=battle(input1,input2,x_len,y_len);
    for(i=0;i<x_len;i++){
        x[x_len-i-1]=input1[i]-'0';
    }
    for(i=0;i<y_len;i++){
        y[y_len-i-1]=input2[i]-'0';
    }
    if(x_len>=y_len){
       choose=x_len;
       for(i=y_len;i<x_len;i++){
            y[i]=0;
       }
    }
    else{
        choose=y_len;
        for(i=x_len;i<y_len;i++){
            x[i]=0;
       }
    }
    if(flag_x==1&&flag_y==1){
        add(x,y,choose);
        if(battle_result==0){
            printf("");
        }
        else if(battle_result==1){
            printf("-");
        }
        mind(x,y,choose);
        mul(x,y,x_len,y_len);
    }
    else if(flag_x==1&&flag_y==0){
        if(battle_result==0){
            printf("");
            mind(y,x,choose);
        }
        else if(battle_result==1){
            printf("-");
            mind(x,y,choose);
        }
        else{
            printf("0\n");
        }
        add(x,y,choose);
        printf("-");
        mul(x,y,x_len,y_len);
    }
    else if(flag_x==0&&flag_y==1){
        if(battle_result==0){
            printf("-");
            mind(y,x,choose);
        }
        else if(battle_result==1){
            printf("");
            mind(x,y,choose);
        }
        else{
            printf("0\n");
        }
        printf("-");
        add(x,y,choose);
        printf("-");
        mul(x,y,x_len,y_len);
    }
    else{
        printf("-");
        add(x,y,choose);
        if(battle_result==0){
            printf("-");
            mind(y,x,choose);
        }
        else if(battle_result==1){
            printf("");
            mind(x,y,choose);
        }
        else{
            printf("0\n");
        }
        mul(x,y,x_len,y_len);
    }
}
