#include <stdio.h>
#include <math.h>
typedef struct student_s
{
    char name[50];
    int score;
} student_t;
void input(student_t s[50], int i){
    scanf("%s",&s[i].name);
    scanf("%d",&s[i].score);
}

void getHigh(student_t s[50], int n,char name[50]){
    int i,Max=0;
    for(i=1;i<n;i++){
        if(s[i].score>s[Max].score){
            Max=i;
            name=s[i].name;
        }
    }
    printf("%s\n",name);
}

int getAverage(student_t s[50], int n){
    int i,total=0;
    for(i=0;i<n;i++){
        total+=s[i].score;
    }
    printf("%d\n",total/n);
}

int main()
{
    int i,num;
    scanf("%d\n",&num);
    student_t student_data[50];
    for(i=0;i<num;i++){
        input(student_data,i);
    }
    getHigh(student_data,num,student_data[0].name);
    getAverage(student_data,num);
}
