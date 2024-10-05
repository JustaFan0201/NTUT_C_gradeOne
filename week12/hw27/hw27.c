#include <stdio.h>
#include <string.h>
int smallest(int data[10][10][2],int work_num,int index[10],int machine[10][100],int now,int check[10],int per_work[10]){
    int i;
    int now_work,need_machine,need_hour;
    int min[3]={99,99,99};//0=i 1=machine 2=hour
    for(i=0;i<work_num;i++){
        now_work=index[i];
        need_machine=data[i][now_work][0];
        need_hour=data[i][now_work][1];
        if(machine[need_machine][now]==0&&need_hour<min[2]&&check[i]==0&&index[i]<per_work[i]){
            min[0]=i;
            min[1]=need_machine;
            min[2]=need_hour;
        }
    }
    if(min[0]==99){return -1;}
    else{return min[0];}
}
void work_process(int data[10][10][2],int work_num,int machine_num,int per_work[10]){
    int machine[10][100];
    int i,j,k,index[work_num],check[work_num],min_index,need_mach,need_hour;
    for(i=0;i<machine_num;i++){
        for(j=0;j<100;j++){
            machine[i][j]=0;}}
    for(i=0;i<work_num;i++){
        index[i]=0;
        check[i]=0;
    }
    for(i=0;i<100;i++){
        for(j=0;j<work_num;j++){
            if(check[j]>0){check[j]--;}}//if check[work]>0 in per turns it would -1
        while(1){
            min_index=smallest(data,work_num,index,machine,i,check,per_work);    //find smallest work and machine could do
            if(min_index==-1){
                break;
            }
            else{
                need_hour=data[min_index][index[min_index]][1];     //fill need machine's process by 1
                need_mach=data[min_index][index[min_index]][0];
                for(j=i;j<i+need_hour;j++){
                    machine[need_mach][j]=1;
                }
                check[min_index]=need_hour;
                index[min_index]++;
                printf("i=%d %d mach=%d hour=%d\n",i,min_index,need_mach,need_hour);
            }
        }
        for(j=0;j<machine_num;j++){
            printf("mach no.%d:",j);
            for(k=0;k<50;k++){
                printf("%d",machine[j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
int main(){
    int data[10][10][2],i,j,machine_num,work_num,per_work[10];
    scanf("%d %d",&machine_num,&work_num);
    for(i=0;i<work_num;i++){
        scanf("%d",&per_work[i]);
        for(j=0;j<per_work[i];j++){
            scanf("%d",&data[i][j][0]);
            scanf("%d",&data[i][j][1]);
        }
    }
    work_process(data,work_num,machine_num,per_work);
}
