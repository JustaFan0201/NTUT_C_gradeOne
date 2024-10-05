#include <stdio.h>
#include <string.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
typedef struct node_s{
    int id;
    int time;
    struct node_s * nexts[30];
    int nextCount;
} task_t;
typedef task_t * pTask;
pTask create(int index,int data,int num){
    pTask newNode;
    newNode=(pTask)malloc(sizeof(task_t));
    newNode->id = index;
    newNode->time = data;
    newNode->nextCount=num;
    for(int i=0;i<num;i++){
        newNode->nexts[i]=NULL;
    }
    return newNode;
}
pTask find(pTask data_list[100],int connect_to_num[100][100],int num,int index_id,int index_now){
    int i;
    for(i=1;i<=num;i++){
        if(data_list[i]->id==connect_to_num[index_id][index_now]){
            return data_list[i];
        }
    }
}
int calculateCompletionTime(pTask task) {
    if (task->nextCount == 0) {
        return task->time;
    }
    int maxTime = 0;
    for (int i = 0; i < task->nextCount; i++) {
        int completionTime = calculateCompletionTime(task->nexts[i]);
        if (completionTime > maxTime) {
            maxTime = completionTime;
        }
    }
    return task->time + maxTime;
}

int count() {
    int i, j;
    int num, data, connect_to_num[100][100];
    pTask data_list[100];
    scanf("%d", &num);
    for (i = 1; i <= num; i++) {
        scanf("%d", &data);
        scanf("%d", &connect_to_num[i][0]);
        data_list[i] = create(i, data, connect_to_num[i][0]);
        for (j = 1; j <= connect_to_num[i][0]; j++) {
            scanf("%d", &connect_to_num[i][j]);
        }
    }
    for (i = 1; i <= num; i++) {
        for (j = 1; j <= connect_to_num[i][0]; j++) {
            data_list[i]->nexts[j - 1] = find(data_list, connect_to_num, num, i, j);
        }
    }
    int totalTime = 0;
    for (i = 1; i <= num; i++) {
        totalTime = max(totalTime, calculateCompletionTime(data_list[i]));
    }
    return totalTime;
}

int main(){
    int num=0,result[100];
    scanf("%d",&num);
    for(int i=0; i<num; i++){
        result[i]=count();
    }
    for(int i=0; i<num; i++){
        printf("%d\n",result[i]);
    }

}
