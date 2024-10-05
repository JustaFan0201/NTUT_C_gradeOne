#include <stdio.h>
#include <string.h>
#define START 0
#define STR 1   //string
#define ZERO 2  //zero start
#define POINT 3 //FLOAT maybe
#define INT 4   //integer maybe
#define VAR 5   //variable maybe
#define NEG 6   //negative
int getstate(int state,char key)
{
    if(state==START && key=='0') return ZERO;
    else if(state==START && key>='1' && key<='9') return INT;
    else if(state==START && ((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z'))) return VAR;
    else if(state==START && key=='_') return VAR;
    else if(state==START && key=='-') return NEG;
    else if(state==ZERO && key=='.') return POINT;
    else if(state==ZERO && key=='\n') return INT;
    else if(state==POINT && key>='0' && key<='9') return POINT;
    else if(state==POINT && key=='\n') return STR;
    else if(state==INT && key=='.') return POINT;
    else if(state==INT && key>='0' && key<='9') return INT;
    else if(state==INT && key=='\n') return INT;
    else if(state==VAR && ((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z'))) return VAR;
    else if(state==VAR && key =='_') return VAR;
    else if(state==VAR && key=='\n') return VAR;
    else if(state==VAR && key>='0' && key<='9') return VAR;
    else if(state==NEG && key>='0' && key<='9') return INT;
    else return STR;
}



int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        char teststring[50];
        scanf("%s",teststring);
        char key;
        int state=START;
        int is_integer=0,is_float=0,is_variable=0;
        while(1)
        {
            key=getchar();
            state=getstate(state,key);
            if(state==STR)
            {
                break;
            }
            else if(state==VAR && key=='\n')
            {
                is_variable=1;
                break;
            }
            else if(state==INT && key=='\n')
            {
                is_integer=1;
                break;
            }
            else if(state==POINT && key=='\n')
            {
                is_float=1;
                break;
            }
        }

        int teststr_length=strlen(teststring);
        if((teststr_length>10)||(teststr_length<1))
            is_variable=0;
        if((teststr_length>50)||(teststr_length<3))
            is_float=0;
        if((teststr_length>50)||(teststr_length<1))
            is_integer=0;


        if(is_integer==1)
            printf("integer\n");
        else if(is_float==1)
            printf("float\n");
        else if(is_variable==1)
            printf("variable\n");
        else
            printf("string\n");
    }
    return 0;
}
