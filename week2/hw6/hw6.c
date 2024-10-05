#include <stdio.h>
#include <string.h>
void print_well(int i , int m){
    int j;
    for(j=m;j>i;j--){
        printf("#");
    }
}
void print_star(int i , int m){
    int j;
    for(j=m;j>=i;j--){
        printf("*");
    }
}
int print_star_eng(int i,int m,int shape){
    int j,flag=0;
    for(j=2;j<=i;j++){
        printf("*%c",(char)shape);
        flag=1;
    }
    if(flag==1){
        shape++;
    }
    if(shape==68){
        shape=65;
    }
    printf("*");
    return shape;
}
void print_num_positive(int i , int m){
    int j;
    for(j=1;j<=i;j++){
        printf("%d",j);
    }
}
void print_num_negative(int i , int m){
    int j;
    for(j=i;j>=1;j--){
        printf("%d",j);
    }
}
void num_1(int n , int m){
    int i,shape=65;
    for(i=1;i<=m;i++){
        print_well(i,m);
        shape=print_star_eng(i,m,shape);
        print_well(i,m);
        printf("\n");
    }
}
void num_2(int n , int m){
    int i,shape=65;
    for(i=1;i<=m;i++){
        print_num_positive(i,m);
        print_star(i,m);
        print_star(i,m);
        print_num_negative(i,m);
        printf("\n");
    }
}
int main(){
    int num,muti;
    scanf("%d",&num);
    scanf("%d",&muti);
    if(num==1&&muti<=9&muti>=2){
        num_1(num,muti);
    }
    else if(num==2&&muti<=9&muti>=2){
        num_2(num,muti);
    }
    else{
        printf("error");
    }
}
