#include <stdio.h>
#include <string.h>
#define GATEVALUE(Gate) int(*GateValue)()
typedef struct _Gate{
    int input1;
    int input2;
    GATEVALUE(Gate);
} Gate;
int GateORValue(Gate *gate){
    return gate->input1||gate->input2;
}
int GateANDValue(Gate *gate){
    return gate->input1&&gate->input2;
}
int GateNOTValue(Gate *gate){
    return !(gate->input1);
}
int GateBUFFERValue(Gate *gate){
    return gate->input1;
}
void CreateGate(Gate *obj, char type){

    if(type=='O'){
        obj->GateValue=GateORValue;
    }
    else if(type=='N'){
        obj->GateValue=GateNOTValue;
    }
    else if(type=='A'){
        obj->GateValue=GateANDValue;
    }
    else if(type=='B'){
        obj->GateValue=GateBUFFERValue;
    }
}
int main(){
    Gate data;
    int i,result[3];
    int num[3]={0,0,0};
    char data_choose[3][2];
    for(i=0;i<3;i++){
        scanf("%d",&num[i]);
    }
    for(i=0;i<3;i++){
        scanf("%s",&data_choose[i]);
    }
    data.input1=0;
    data.input2=0;
    for(i=0;i<3;i++){
        data.input1=num[i];
        CreateGate(&data,data_choose[i][0]);
        data.input2=data.GateValue(&data);
        result[i]=data.GateValue(&data);
    }
    for(i=0;i<3;i++){
        if(i!=2){
            printf("%d ",result[i]);
        }
        else{
            printf("%d",result[i]);
        }
    }
}
