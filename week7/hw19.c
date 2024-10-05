#include <stdio.h>
#define CHANGE(x, y) { int temp = x; x = y; y = 7-temp; }
#define SWAP(x, y) { int temp = x; x = y; y = temp; }
void roll(int data[], int b)
{
    if (b==1) CHANGE(data[0], data[1])
        else if (b==2) CHANGE(data[1], data[0])
            else if (b==3) CHANGE(data[2], data[1])
                else if (b==4) CHANGE(data[1], data[2])
                }
int countSame(int data[4][3], int sum[7])
{
    int maxIndex=0;
    for (int i=1; i<=6; i++)
    {
        for (int j=0; j<4; j++)
        {
            if (data[j][1]==i) sum[i]++;
        }
        if (sum[i]>=sum[maxIndex]) maxIndex=i;
    }
    return maxIndex;
}
int sameSum(int sum[], int index)
{
    int num=0;
    for (int i=1; i<=6; i++)
        if (sum[i]==sum[index]) num++;
    return num;
}
int normalPoint(int sum[])
{
    int point=0;
    for (int i=1; i<=6; i++)
        if (sum[i]==1) point=point+i;
    return point;
}
int getPoint(int data[4][3])
{
    int sum[7]= {0,0,0,0,0,0,0};
    int maxIndex=0, point=0;
    maxIndex = countSame(data, sum);
    if (sum[maxIndex]==4) point=18;
    else if ((sum[maxIndex]==1)||(sum[maxIndex]==3)) point=0;
    else if ((sum[maxIndex]==2)&&(sameSum(sum, maxIndex)==2)) point=2*maxIndex;
    else if (sum[maxIndex]==2) point=normalPoint(sum);
    return point;
}
int game()
{
    int m=0, a[4], data[4][3],point=0;
    for (int i=0; i<4; i++)
    {
        data[i][0]=4;
        data[i][1]=1;
        data[i][2]=2;
    }
    scanf("%d", &m);
    for (int i=0; i<m; i++)
    {
        scanf("%d %d %d %d", &a[0], &a[1], &a[2], &a[3]);
        for (int j=0; j<4; j++) roll(data[j], a[j]);
    }
    point=getPoint(data);
    return point;
}
int main(){
    int i,player[50];
    for(i=0;i<1;i++){
        player[i]=game();
    }
    printf("%d",player[0]);

}
