#include <stdio.h>
#include <math.h>
int main(){
    int a,b,c;
    float x1,x2,result,Fake1,Fake2;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    result=b*b-4*a*c;
    if (result>=0){
        x1= ((-b) + sqrt(b * b - 4 * a * c)) / (2 * a);
        x2= ((-b) - sqrt(b * b - 4 * a * c)) / (2 * a);
        printf("%.1f\n",round(x1*10)/10);
        printf("%.1f",round(x2*10)/10);
    }
    else{
        x1=  -b/1.0 / ( 2 * a ) ;
        x2=  -b/1.0 / ( 2 * a ) ;
        Fake1=( sqrt( -1 * ( b * b - 4 * a * c )) / ( 2 * a ));
        Fake2=-( sqrt( -1 * ( b * b - 4 * a * c )) / ( 2 * a ));
        if (Fake1>=0){
            printf("%.1f+%.1fi\n",round(x1*10)/10,round(Fake1*10)/10);
            printf("%.1f%.1fi\n",round(x2*10)/10,round(Fake2*10)/10);
        }
        else{
            printf("%.1f%.1fi\n",round(x1*10)/10,round(Fake1*10)/10);
            printf("%.1f+%.1fi\n",round(x2*10)/10,round(Fake2*10)/10);
        }
    }
}
