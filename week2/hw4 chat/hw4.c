#include <stdio.h>
#include <string.h>
int check_s(char data)//判斷特殊字元
{
    int i;
    char check[99]= {"@#\\/%&$!/*+^()<>?:"};
    for(i=0; i<strlen(check); i++)
    {
        if(data==check[i])
        {
            return 1;
        }
    }
    return 0;
}
int check_d(char data)//判斷數字
{
    int i;
    char check[10]= {"0123456789"};
    for(i=0; i<10; i++)
    {
        if(data==check[i])
        {
            return 1;
        }
    }
    return 0;
}
int check_c(char data)//判斷英文跟_
{
    if(((int)data>=65&&(int)data<=122)||(int)data=='_')
    {
        return 1;
    }
    return 0;
}
int first(char data)//判斷第一位是否0 or _ or 數字 or 有無小數點
{
    if(data=='0')
    {
        return 0;//0;
    }
    if(data=='-')
    {
        return 5;//-;
    }
    if(data=='_')
    {
        return 6;//_;
    }
    if(check_d((char)data)==1)
    {
        return 1;//d;
    }
    if(data=='.')
    {
        return 2;//f;
    }
    if(check_c((char)data)==1)
    {
        return 3;//c;
    }
    if(check_s((char)data)==1)
    {
        return 4;//s;
    }
}

int third(char data)
{
    if(data=='0')
    {
        return 0;//0;
    }
    if(data=='_')
    {
        return 6;//_;
    }
    if(check_d((char)data)==1)
    {
        return 1;//d;
    }
    if(data=='.')
    {
        return 2;//f;
    }
    if(check_c((char)data)==1)
    {
        return 3;//c;
    }
    if(check_s((char)data)==1)
    {
        return 4;//s;
    }
}
int second(char data[50],int n)
{
    int count,i,j,k,d=0,f=0,c=0,s=0,first_con=-1,third_con=-1,four_con=-1,final_con=0;
    scanf("%s",data);
    count=strlen(data);
    first_con=first(data[0]);
    third_con=third(data[1]);
    four_con=first(data[2]);
    final_con=first(data[count-1]);
    for(j=2; j<count; j++)
    {
        if(check_s((char)data[j])==1)
        {
            s=1;
        }
        else if(data[j]=='.')
        {
            f=1;
        }
        else if(check_c((char)data[j])==1)
        {
            c=1;
        }
        else if(check_d((char)data[j])==1)
        {
            d=1;
        }
    }
    if(((first_con==1||first_con==5)&&(third_con==1||third_con==0)&&d==1&&c==0&&f==0&&s==0)
        &&count<=50&&(final_con==1||final_con==0))
    {
        return 1;
    }
    else if ((count==1&&(first_con==0||first_con==1)))
    {
        return 1;
    }
    else if (count==2&&first_con==1&&(third_con==1||third_con==0))
    {
        return 1;
    }
    else if((
             (((first_con==1||first_con==0)&&third_con==2)&&d==1&&c==0&&f==0&&s==0)||
                (first_con==5&&(third_con==0||four_con==2)&&d==1&&c==0&&f==0&&s==0)||
             (first_con==5&&(third_con==1)&&d==1&&c==0&&f==1&&s==0)||
             (first_con==1&&(third_con==0||third_con==1)&&d==1&&c==0&&f==1&&s==0)
            )&&(final_con==1||final_con==0)&&count<=50&&count>=3)
    {
        return 2;
    }
    else if((first_con==6||first_con==3)&&
            (third_con!=4&&third_con!=2)&&
            f==0&&s==0&&
            final_con!=2&&final_con!=4&&
            count<=10)
    {
        return 3;
    }
    else
    {
        return 4;
    }
}
int main()
{
    char data[50];
    int i,n;
    scanf("%d",&n);
    int result[n];
    for(i=0; i<n; i++)
    {
        result[i]=second(data,n);
    }
    for(i=0; i<n; i++)
    {
        if(result[i]==1)
        {
            printf("integer\n");
        }
        else if(result[i]==2)
        {
            printf("float\n");
        }
        else if(result[i]==3)
        {
            printf("variable\n");
        }
        else if(result[i]==4)
        {
            printf("string\n");
        }
    }
}
