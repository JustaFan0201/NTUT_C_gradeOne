#include <stdio.h>
#include <string.h>
typedef enum scoreType_s {G,GPA,S} scoreType_t;
typedef enum G_s {Aplus,A,Aduce,Bplus,B,Bduce,Cplus,C,Cduce,F,X} G_t;
typedef enum GPA_s {b4dot3,b4dot0,b3dot7,b3dot3,b3dot0,b2dot7,b2dot3,b2dot0,b1dot7,b1,b0} GPA_t;
typedef enum S_s {b90to100,b85to89,b80to84, b77to79,b73to76,b70to72,b67to69,b63to66,b60to62,b1to59,b0to0} S_t;
typedef union student_s
{
    int score;
    G_t G;
    GPA_t GPA;
    S_t S;
} student_t;
void tran_G(student_t student[50],int index){
    char data[50];
    scanf("%s",&data);
    if(strcmp(data,"A+")==0||strcmp(data,"4.3")==0||strcmp(data,"90-100")==0){
        student[index].score+=95;
    }
    else if(strcmp(data,"A")==0||strcmp(data,"4.0")==0||strcmp(data,"85-89")==0){
        student[index].score+=87;
    }
    else if(strcmp(data,"A-")==0||strcmp(data,"3.7")==0||strcmp(data,"80-84")==0){
        student[index].score+=82;
    }
    else if(strcmp(data,"B+")==0||strcmp(data,"3.3")==0||strcmp(data,"77-79")==0){
        student[index].score+=78;
    }
    else if(strcmp(data,"B")==0||strcmp(data,"3.0")==0||strcmp(data,"73-76")==0){
        student[index].score+=75;
    }
    else if(strcmp(data,"B-")==0||strcmp(data,"2.7")==0||strcmp(data,"70-72")==0){
        student[index].score+=70;
    }
    else if(strcmp(data,"C+")==0||strcmp(data,"2.3")==0||strcmp(data,"67-69")==0){
        student[index].score+=68;
    }
    else if(strcmp(data,"C")==0||strcmp(data,"2.0")==0||strcmp(data,"63-66")==0){
        student[index].score+=65;
    }
    else if(strcmp(data,"C-")==0||strcmp(data,"1.7")==0||strcmp(data,"60-62")==0){
        student[index].score+=60;
    }
    else if(strcmp(data,"F")==0||strcmp(data,"1")==0||strcmp(data,"1-59")==0){
        student[index].score+=50;
    }
    else if(strcmp(data,"X")==0||strcmp(data,"0")==0){
        student[index].score+=0;
    }
}
int check(char name[50][50],char check_data[50][50],int count){
    for(int i=0;i<count;i++){
        if(strcmp(name,check_data[i])==0){
            return 0;
        }
    }
    return 1;
}
int main()
{
    int i,j,num,student_num;
    char choose[50],name[50][50],check_data[50][50];
    student_t student[50];
    scanf("%d",&num);
    for(i=0;i<num;i++){
        scanf("%s\n",&choose);
    }
    scanf("%d",&student_num);
    for(i=0;i<student_num;i++){
        scanf("%s",&name[i]);
        student[i].score=0;
        for(j=0;j<num;j++){
            tran_G(student,i);
        }
        student[i].score/=num;
    }
    int small=99,count=0,index=0;
    char ready_name[50];
    while(1){
        small=999;
        for(i=0;i<student_num;i++){
            if(student[i].score<small&&check(name[i],check_data,student_num)==1){
                small=student[i].score;
                index=i;
            }
        }
        printf("%s %d\n",name[index],small);
        strcpy(check_data[count],name[index]);
        count++;
        if(count==student_num){
            break;
        }
    }
}
