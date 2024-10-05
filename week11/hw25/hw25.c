#include <stdio.h>
#include <string.h>
#include <math.h>
#define ShapeText(TYPE)\
char name[10];\
double (*perimeter)(struct TYPE*);\
double (*area)(struct TYPE*)

typedef struct circle_s
{
    ShapeText(circle_s);
    double radius;
} circle_t;

double Circle_P(circle_t *obj){
    double perimeter_value = 2 * 3.14 * obj->radius;
    return perimeter_value;
}

double Circle_A(circle_t *obj){
    double area_value = obj->radius * 3.14 * obj->radius;
    return area_value;
}

void Circle_New(circle_t *obj){
    strcpy(obj->name,"circle");
    obj->perimeter=Circle_P;
    obj->area=Circle_A;
}

void Create_c(float result[50][2],int num){
    circle_t c;
    scanf("%lf",&c.radius);
    Circle_New(&c);
    result[num][0]=c.perimeter(&c);
    result[num][1]=c.area(&c);
}

typedef struct square_s
{
    ShapeText(square_s);
    double edge;
} square_t;

double square_P(square_t *obj){
    double perimeter_value = 4 * obj->edge;
    return perimeter_value;
}

double square_A(square_t *obj){
    double area_value = obj->edge * obj->edge;
    return area_value;
}

void square_New(square_t *obj){
    strcpy(obj->name,"square");
    obj->perimeter=square_P;
    obj->area=square_A;
}

void Create_s(float result[50][2],int num){
    square_t s;
    scanf("%lf",&s.edge);
    square_New(&s);
    result[num][0]=s.perimeter(&s);
    result[num][1]=s.area(&s);
}


typedef struct rectangle_s
{
    ShapeText(rectangle_s);
    double w,h;
} rectangle_t;

double rectangle_P(rectangle_t *obj){
    double perimeter_value = 2 * (obj->w+obj->h);
    return perimeter_value;
}

double rectangle_A(rectangle_t *obj){
    double area_value = obj->w * obj->h;
    return area_value;
}

void rectangle_New(rectangle_t *obj){
    strcpy(obj->name,"rectangle");
    obj->perimeter=rectangle_P;
    obj->area=rectangle_A;
}

void Create_r(float result[50][2],int num){
    rectangle_t r;
    scanf("%lf",&r.w);
    scanf("%lf",&r.h);
    rectangle_New(&r);
    result[num][0]=r.perimeter(&r);
    result[num][1]=r.area(&r);
}

typedef struct triangle_s
{
    ShapeText(triangle_s);
    double edge_one;
    double edge_two;
    double edge_three;
} triangle_t;

double triangle_P(triangle_t *obj){
    double perimeter_value =  (obj->edge_one+obj->edge_two+obj->edge_three);
    return perimeter_value;
}

double triangle_A(triangle_t *obj){
    double s=(obj->edge_one+obj->edge_two+obj->edge_three)/2.0;
    double area_value = sqrt(s*(s-obj->edge_one)*(s-obj->edge_two)*(s-obj->edge_three));
    return area_value;
}

void triangle_New(triangle_t *obj){
    strcpy(obj->name,"triangle");
    obj->perimeter=triangle_P;
    obj->area=triangle_A;
}

void Create_t(float result[50][2],int num){
    triangle_t t;
    scanf("%lf",&t.edge_one);
    scanf("%lf",&t.edge_two);
    scanf("%lf",&t.edge_three);
    triangle_New(&t);
    result[num][0]=t.perimeter(&t);
    result[num][1]=t.area(&t);
}
int main()
{
    int num;
    char data[50];
    float result[50][2],total[2];
    total[0]=0;
    total[1]=0;
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        scanf("%s",&data);
        if(data[0]=='C'){
            Create_c(result,i);
        }
        else if(data[0]=='S'){
            Create_s(result,i);
        }
        else if(data[0]=='R'){
            Create_r(result,i);
        }
        else if(data[0]=='T'){
            Create_t(result,i);
        }
        total[0]+=result[i][0];
        total[1]+=result[i][1];
    }
    for(int i=0;i<num;i++){
        printf("%.2f %.2f\n",result[i][0],result[i][1]);
    }
    printf("%.2f %.2f\n",total[0],total[1]);
    return 0;
}
