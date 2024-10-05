#include <stdio.h>
#include <string.h>
int check(int cut[100],int check_data[100],int num){
    int i,flag=0;
    for(i=0;i<num;i++){
        if(cut[i]==check_data[i]){
            flag++;
        }
    }
    if(flag==num){
        return 0;
    }
    else{
        return 1;
    }
}
int check_two(int cut[100],int num){
    int i,j,flag=0;
    for(i=0;i<num;i++){
        for(j=0;j<num;j++){
            if(i!=j){
                if(cut[i]==cut[j]){
                    return 0;
                }
            }
        }
    }
    return 1;
}
int main(){
    int i=0,j=0,k=0,num,data[100],temp=0,len,same=0,same_flag=0;
    scanf("%d",&num);
    while(1){
        scanf("%d",&temp);
        if(temp==-1){
            break;
        }
        else{
            data[i]=temp;
            i++;
        }
    }
    len=i;
    int cut[len-num+1][num];
    for(i=0;i<len-num+1;i++){
        for(j=0;j<num;j++){
            cut[i][j]=data[i+j];
        }
    }
    int check_data[len-num][num],flag=1,index=0;
    for(i=0;i<len-num+1;i++)
    {
        for(j=0;j<index;j++){
            if(check(cut[i],check_data[j],num)==0){
                flag=0;
                same_flag=1;
                break;
            }
            else{
                flag=1;
            }
        }
        if(flag==1&&check_two(cut[i],num)==1){
            for(k=0;k<num;k++){
                check_data[index][k]=cut[i][k];
            }
            index++;
        }
        else if(same_flag==1&&check_two(cut[i],num)==1){
            same++;
            same_flag=0;
        }
        flag=1;
    }

    int result[100][num],rank[index],flag_rank=0;
    for(i=0;i<index;i++){
        rank[i]=0;
    }
    for(i=0;i<index;i++){
        for(j=0;j<index;j++){
            if(i!=j){
                for(k=0;k<num;k++){
                    if(check_data[i][k]>check_data[j][k]){
                        flag_rank=1;
                        break;
                    }
                    else if(check_data[i][k]<check_data[j][k]){
                        break;
                    }
                }
            }
            if(flag_rank==1){
                rank[i]++;
                flag_rank=0;
            }
        }
    }
    for(i=0;i<index;i++){
        for(j=0;j<num;j++){
            result[rank[i]][j]=check_data[i][j];
        }
    }
    printf("%d\n",index+same);
    for(i=0;i<index;i++){
        for(j=0;j<num;j++){
            if(j==num-1){
                printf("%d",result[i][j]);
            }
            else{
                printf("%d ",result[i][j]);
            }
        }
        printf("\n");
    }
}
