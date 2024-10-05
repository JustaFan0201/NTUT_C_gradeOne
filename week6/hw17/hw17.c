#include <stdio.h>
#include <string.h>
#include <math.h>
int i_index=0,now_index=0;
char data[100]={0};
int table_data[100];
void table(int size){
    if(data[i_index++]!='2'){
        for(int j=0;j<size*size;j++){
            if(data[i_index-1]=='1'){
                table_data[now_index++]=1;
            }
            else{
                table_data[now_index++]=0;
            }
        }
    }
    else{
        for(int k=0;k<4;k++){
            table(size/2);
        }
    }
}
void swap(int index,int num,int* final_re[num][num]){
    int i=0,temp;
    for(i=index;i<index+2;i++){
        temp=final_re[i/num][i%num];
        final_re[i/num][i%num]=final_re[i/num+1][i%num-2];
        final_re[i/num+1][i%num-2]=temp;
    }
}
void swap_2(int index,int num,int* final_re[num][num]){
    int i=0,temp;
    for(i=index;i<index+2;i++){
        temp=final_re[i/num][i%num];
        final_re[i/num][i%num]=final_re[i/num][i%num+2];
        final_re[i/num][i%num+2]=temp;
    }
    for(i=index+8;i<index+8+2;i++){
        temp=final_re[i/num][i%num];
        final_re[i/num][i%num]=final_re[i/num][i%num+2];
        final_re[i/num][i%num+2]=temp;
    }
}
void swap_3(int index,int num,int* final_re[num][num]){
    int i=0,temp;
    for(i=index;i<index+4;i++){
        temp=final_re[i/num][i%num];
        final_re[i/num][i%num]=final_re[i/num+2][i%num-4];
        final_re[i/num+2][i%num-4]=temp;
    }
    for(i=index+8;i<index+8+4;i++){
        temp=final_re[i/num][i%num];
        final_re[i/num][i%num]=final_re[i/num+2][i%num-4];
        final_re[i/num+2][i%num-4]=temp;
    }
}

int main(){
    int i,j=0,num,count=0;
    scanf("%s",data);
    scanf("%d",&num);
    if(data[0]=='1'&&strlen(data)==1){
        for(i=0;i<num;i++){
            for(j=0;j<num;j++){
                printf("%d,%d\n",i,j);
            }
        }
        return 0;
    }
    else if(data[0]=='0'&&strlen(data)==1){
        printf("all white");
        return 0;
    }
    int result[100][4];
    int* final_re[num][num];
    for(i=0;i<4*(pow(4,num/4));i++){
        table_data[i]=0;
    }
    table(num);
    for(i=0;i<num;i++){
        for(j=0;j<num;j++){
            final_re[i][j]=table_data[count++];
        }
    }
    if(num==4){
        swap(2,num,final_re);
        swap(10,num,final_re);
    }
    else if(num==8){
        swap(2,num,final_re);
        swap(6,num,final_re);
        swap(18,num,final_re);
        swap(22,num,final_re);
        swap(34,num,final_re);
        swap(38,num,final_re);
        swap(50,num,final_re);
        swap(54,num,final_re);
        swap_2(2,num,final_re);
        swap_2(18,num,final_re);
        swap_2(34,num,final_re);
        swap_2(50,num,final_re);
        swap_3(4,num,final_re);
        swap_3(36,num,final_re);
    }
    for(i=0;i<num;i++){
        for(j=0;j<num;j++){
            if(final_re[i][j]==1){
               printf("%d,%d\n",i,j);
            }
        }
    }
}
