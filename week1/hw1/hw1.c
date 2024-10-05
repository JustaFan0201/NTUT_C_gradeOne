#include <stdio.h>
#include <math.h>

int main(){
    int w,h;
    float total;
    scanf("%d",&w);
    scanf("%d",&h);
    total=w/(h*h/10000.0);
    printf("%.1f",round(total*10)/10);
}
