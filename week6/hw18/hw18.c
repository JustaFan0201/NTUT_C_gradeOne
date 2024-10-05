#include <stdio.h>
#define SWAP(x,y) {int t; t = x; x = y; y = t;}
int selectFlag_check=0,selectFlag_move=0;
int insertionFlag_check=0,insertionFlag_move=0;
int getMinIndex(int d[], int left, int right)
{
    int i=0, minIndex = left;
    for ((i=left+1); i<right; i++)
    {
        if (d[i]<d[minIndex]) minIndex=i;
        selectFlag_check++;
    }
    return minIndex;
}
void selectSort(int d[], int n)
{
    int i=0, index=0;
    for (i=0; i<n; i++)
    {
        index = getMinIndex(d, i, n);
        if(i!=index)
        {
            SWAP(d[i], d[index]);
            selectFlag_move++;
        }
    }
}
check_1(int j){
    insertionFlag_check++;
    if(j>0){
        return 1;
    }
    return 0;
}
check_2(int a,int target){
    insertionFlag_check++;
    if(a>target){
        return 1;
    }
    return 0;
}
void insertionSort(int a[], int n)
{
    int target=0, i=0, j=0;
    for (i=1; i<n; i++)
    {
        target = a[i];
        insertionFlag_move++;
        for (j=i; check_1(j)==1&&check_2(a[j-1],target)==1 ; j--){
            insertionFlag_move++;
            a[j] = a[j-1];
        }
        insertionFlag_move++;
        a[j] = target;
    }
}

int main()
{
    int i,num;
    scanf("%d",&num);
    int data[num];
    int data_2[num];
    for(i=0; i<num; i++)
    {
        scanf("%d",&data[i]);
        data_2[i]=data[i];
    }
    selectSort(data,num);
    insertionSort(data_2,num);
    printf("%d %d\n",selectFlag_check,selectFlag_move*3);
    printf("%d %d\n",insertionFlag_check,insertionFlag_move);
}
