#include <stdio.h>

int main(){
    int now[5]={0},hit,i,j,out=0;
    int point=0;
    for(i=0;i<5;i++)
    {
        scanf("%d",&hit);
        if(hit==0){
            out++;
        }
        else if(hit==4){
            point++;
            for(j=0;j<=i;j++){
                if(now[j]>0){
                    now[j]=0;
                    point++;
                }
            }
        }
        else{
            for(j=0;j<=i-1;j++){
                if(now[j]+hit>3){
                    now[j]=0;
                    point++;
                }
                else if(now[j]>0){
                    now[j]+=hit;
                }
            }
            now[i]=hit;
        }
        if(out==3){
            for(j=0;j<=i;j++){
                now[j]=0;
            }
        }
    }
    int x1=0,x2=0,x3=0;
    for(i=0;i<5;i++)
    {
        if(now[i]==1){
            x1=1;
        }
        if(now[i]==2){
            x2=1;
        }
        if(now[i]==3){
            x3=1;
        }
    }
    printf("%d\n",point);
    printf("%d %d %d",x1,x2,x3);
}

