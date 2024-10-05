#include <stdio.h>
#include <string.h>
int main(){
    int score_temp_one=0,score_temp_two=0,total_score[70][2];
    int i,j,race_num,temp_one,temp_two,best;
    char team[10];
    scanf("%d",&race_num);
    for(i=0;i<70;i++){
        total_score[i][1]=0;
        total_score[i][0]=0;
    }
    for(i=0;i<race_num;i++){
        score_temp_one=0;
        score_temp_two=0;
        scanf("%s%s",&team[0],&team[1]);
        for(j=0;j<4;j++){
            scanf("%d%d",&temp_one,&temp_two);
            score_temp_one+=temp_one;
            score_temp_two+=temp_two;
        }
        total_score[(int)team[0]][0]+=score_temp_one;
        total_score[(int)team[1]][0]+=score_temp_two;
        if(score_temp_one>score_temp_two){
            total_score[(int)team[0]][1]+=1;
        }
        else{
            total_score[(int)team[1]][1]+=1;
        }
    }
    best=65;
    for(i=66;i<68;i++){
        if(total_score[i][1]>total_score[best][1]){
            best=i;
        }
    }
    printf("%c\n",best);
    printf("%d",total_score[best][0]);
}
