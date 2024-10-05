#include <stdio.h>
#include <string.h>
#include <math.h>
int main(){
    int num,i,j,k,now_size=0;
    char data[100]={0};
    scanf("%s",data);
    scanf("%d",&num);
    int table[100][4];
    now_size=num;
    int now_index=1,flag=0;
    for(i=0;i<pow(4,num/4)+1;i++){
        for(j=0;j<4;j++){
            table[i][j]=0;
        }
    }
    for(i=0;i<strlen(data);i++){
        if(data[i]=='2'){
            now_size/=2;
            flag=0;
        }
        else if(data[i]=='1'){
            for(j=now_index;j<now_index+now_size*now_size+1;j++){
                for(k=0;k<4;k++){
                    table[j][k]=1;
                }
                flag++;
            }
            now_index+=now_size;
            now_size/=2;
            if(flag>=4){
                now_size*=2;
                flag=0;
            }
        }
        else if(data[i]=='0'){
            for(j=now_index;j<now_index+now_size*now_size+1;j++){
                flag++;
            }
            now_index+=now_size;
            now_size/=2;
            if(flag>=4){
                now_size*=2;
                flag=0;
            }
        }
    }
    for(i=1;i<pow(4,num/4)+1;i++){
        for(j=0;j<4;j++){
            printf("i=%d j=%d %d\n",i,j,table[i][j]);
        }
    }
}

