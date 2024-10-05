#include <stdio.h>
#include <string.h>
#include <math.h>

int sol(char data[10][10],int choose){
    int i=0,j,temp,temp_base,player_num,turn=0,base[3]={0},out=0,score=0,run[10]={0},rank[3],name[3],rank_hit[3],hit[10]={0};
    while(1){
        player_num=i%9;
        if(i%9==0&&i!=0){
            turn++;
        }
        if(data[player_num][turn]=='O'){
            out++;
            if(out==choose){
                break;
            }
            if(out%3==0&&out!=0){
                base[0]=0;
                base[1]=0;
                base[2]=0;
            }
        }
        else if(data[player_num][turn]=='H'){
            score++;
            run[player_num+1]+=4;
            hit[player_num+1]++;
            for(j=0;j<3;j++){
                if(base[j]>0){
                    run[base[j]]+=4-j-1;
                    score++;
                    base[j]=0;
                }
            }
        }
        else{
            for(j=2;j>=0;j--){
                if(base[j]>0){
                    temp=base[j];
                    temp_base=(int)(data[player_num][turn]-'0')+j;
                    run[temp]+=temp_base-j;
                    if(temp_base<3){
                        base[temp_base]=temp;
                    }
                    else{
                        run[temp]-=(temp_base-j);
                        run[temp]+=4-j-1;
                        score++;
                    }
                    base[j]=0;
                }
            }
            base[(int)(data[player_num][turn]-'0')-1]=player_num+1;
            run[player_num+1]+=(int)(data[player_num][turn]-'0');
            hit[player_num+1]++;
        }
        i++;
    }
    rank[0]=0;
    rank[1]=0;
    rank[2]=0;
    for(i=1;i<10;i++){
        if(run[i]>rank[0]){
            if(rank[0]>=rank[1]&&name[0]!=name[1]){
                rank[1]=rank[0];
                name[1]=name[0];
                rank_hit[1]=rank_hit[0];
            }
            else if(rank[0]>=rank[2]&&name[0]!=name[2]){
                rank[2]=rank[0];
                name[2]=name[0];
                rank_hit[2]=rank_hit[0];
            }
            rank[0]=run[i];
            name[0]=i;
            rank_hit[0]=hit[i];
        }
        else if(run[i]>rank[1]){
            if(rank[1]>=rank[2]&&name[1]!=name[2]){
                rank[2]=rank[1];
                name[2]=name[1];
                rank_hit[2]=rank_hit[1];
            }
            rank[1]=run[i];
            name[1]=i;
            rank_hit[1]=hit[i];
        }
        else if(run[i]>rank[2]){
            rank[2]=run[i];
            name[2]=i;
            rank_hit[2]=hit[i];

        }
    }
    printf("%d\n",score);
    for(i=0;i<3;i++){
        printf("%d %d %d\n",name[i],rank_hit[i],rank[i]);
    }

    return 0;
}

int main() {
    int i,j,num,choose;
    char data[10][10]={0};
    for(i=0;i<9;i++){
        scanf("%d",&num);
        for(j=0;j<num;j++){
            scanf(" %c",&data[i][j]);
        }
        data[i][num]='\0';
    }
    scanf("%d",&choose);
    num=sol(data,choose);
    return 0;
}
