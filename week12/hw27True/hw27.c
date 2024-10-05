#include <stdio.h>
#include <string.h>
typedef struct work_d{
    int need_machine[10];
    int need_hour[10];
    int num_process;
    int work_now;
}work_t;
void work_process(work_t data[10],int work_num,int machine_num){
    int process_now[machine_num];
    int index[work_num];
    int min[4],choose_num=0,count[work_num];
    int i,j,k;
    int flag;
    for(i=0;i<machine_num;i++){
        process_now[i]=0;}
    for(i=0;i<work_num;i++){

        count[i]=0;
        index[i]=0;}
    while(1){
        min[0]=-1;min[1]=-1;min[2]=-1;min[3]=99;
        for(i=0;i<work_num;i++){
            if(index[i]<data[i].num_process){
                if(data[i].work_now>=process_now[data[i].need_machine[index[i]]]){
                    choose_num=data[i].work_now;
                }
                else{
                    choose_num=process_now[data[i].need_machine[index[i]]];
                }
                if(choose_num+data[i].need_hour[index[i]]<min[3]){
                    min[0]=i;
                    min[1]=index[i];
                    min[2]=data[i].need_machine[index[i]];
                    min[3]=choose_num+data[i].need_hour[index[i]];
                }
            }
        }
        if(min[0]!=-1){
            index[min[0]]++;
            process_now[min[2]]=min[3];
            data[min[0]].work_now=min[3];
            count[min[0]]+=min[3];
        }
        flag=0;
        for(i=0;i<work_num;i++){
            if(data[i].num_process==index[i]){
                flag++;
            }
        }
        if(flag==work_num){
            break;
        }
    }
    int total=0;
    for(i=0;i<work_num;i++){
        total+=data[i].work_now;
    }
    printf("%d",total);
}
int main(){
    work_t data[10];
    int i,j,machine_num,work_num;
    scanf("%d %d",&machine_num,&work_num);
    for(i=0;i<work_num;i++){
        scanf("%d",&data[i].num_process);
        data[i].work_now=0;
        for(j=0;j<data[i].num_process;j++){
            scanf("%d",&data[i].need_machine[j]);
            scanf("%d",&data[i].need_hour[j]);
        }
    }
    work_process(data,work_num,machine_num);
}
