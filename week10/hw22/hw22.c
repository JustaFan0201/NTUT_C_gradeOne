#include <stdio.h>
#include <string.h>
int check(char data[200],int len){
    int i,j,count=0,flag=0,count_change=0,max_num=0,tri[200];
    for(i=0;i<strlen(data);i++){
        if(data[i]>='a'){
            tri[i]=-1;
        }
        else{
            tri[i]=1;
        }
    }
    for(i=0;i<strlen(data)-len;i++){
        count=0;
        if(tri[i]==-1){
            flag=-1;
            count_change=len;
            for(j=i;j<strlen(data);j++){
                if(tri[j]==flag){
                    count_change--;
                }
                else if(tri[j]!=flag){
                    break;
                }
                if(count_change==0){
                    count_change=len;
                    flag*=-1;
                    count+=len;
                }
                if(max_num<count&&count>len&&count%len==0){
                    max_num=count;
                }
            }
        }
        else{
            flag=1;
            count_change=len;
            for(j=i;j<strlen(data);j++){
                if(tri[j]==flag){
                    count_change--;
                }
                else if(tri[j]!=flag){
                    break;
                }
                if(count_change==0){
                    count_change=len;
                    flag*=-1;
                    count+=len;
                }
                if(max_num<count&&count>len&&count%len==0){
                    max_num=count;
                }
            }
        }

    }
    return max_num;
}
int main()
{
    char data[50][200];
    int len[50],result[50]={0},num,i,j;
    scanf("%d",&num);
    for(i=0;i<num;i++){
        scanf("%s",data[i]);
        scanf("%d",&len[i]);
        result[i]=check(data[i],len[i]);
    }
    for(i=0;i<num;i++){
        printf("%d\n",result[i]);
    }
}
