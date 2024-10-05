#include <stdio.h>
#include <string.h>
int main(){
    int i,j,k,flag=0,class_number,num,day,class_day[70][10],save[3][3];
    for(i=0;i<70;i++)
    {
        for(j=0;j<10;j++)
        {
            class_day[i][j]=1;
        }
    }

    for(i=0;i<3;i++)
    {
        scanf("%d",&class_number);
        scanf("%d",&num);
        for(j=0;j<num;j++)
        {
            scanf("%d",&day);
            k=class_day[day][0];
            class_day[day][k]=class_number;
            class_day[day][0]++;
        }
    }
    for(i=0;i<70;i++)
    {
        k=0;
        for(j=1;j<3;j++)
        {
            if(class_day[i][0]>j&&class_day[i][j]!=1&&class_day[i][j+1]!=1){
                printf("%d,%d,%d\n",class_day[i][j],class_day[i][j+1],i);
                k++;
                flag=1;
            }
            if(k==class_day[i][0]){
                break;
            }
        }
    }
    if(flag==0){
        printf("correct");
    }
}
