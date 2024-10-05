#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dnode_s {
int data;
struct dnode_s * front;
struct dnode_s * back;
} node_t;
typedef node_t * nodep_t;

nodep_t create(int data) {
    nodep_t newNode = (nodep_t)malloc(sizeof(node_t));
    newNode->data = data;
    newNode->back = NULL;
    newNode->front = NULL;
    return newNode;
}

int double_link(int num, char result[100][100]) {
    int i, count_result = 0 ,count_node=0;
    char input[20];
    int data,num_data;
    nodep_t top = NULL;
    nodep_t tail = NULL;
    for (i = 0; i < num; i++) {
        scanf("%s", input);
        if (strcmp(input, "addFront") == 0) {
            scanf("%d", &data);
            nodep_t newNode = create(data);
            if (top == NULL) {
                top = tail = newNode;
            }
            else {
                newNode->back = top;
                top->front= newNode;
                top = newNode;
            }
            count_node++;
        }
        else if (strcmp(input, "addBack") == 0) {
            scanf("%d", &data);
            nodep_t newNode = create(data);
            if (tail == NULL) {
                top = tail = newNode;
            } else {
                tail->back = newNode;
                newNode->front=tail;
                tail = newNode;
            }
            count_node++;
        }
        else if (strcmp(input, "removeFront") == 0) {
            if (top) {
                nodep_t temp=top;
                top=top->back;
                top->front=NULL;
                free(temp);
                if(top==NULL){
                    tail=NULL;
                }
            } else {
                strcpy(result[count_result++], "Double link list is empty");
            }
            count_node--;
        }
        else if (strcmp(input, "removeBack") == 0) {
            if (tail) {
                nodep_t temp=tail;
                tail=tail->front;
                tail->back=NULL;
                free(temp);
                if(tail==NULL){
                    top=NULL;
                }
            } else {
                strcpy(result[count_result++], "Double link list is empty");
            }
            count_node--;
        }
        else if (strcmp(input, "empty") == 0) {
            if (top) {
                while (top) {
                    nodep_t temp = top;
                    top= top->back;
                    free(temp);
                }
                tail = NULL;
            } else {
                strcpy(result[count_result++], "Double link list is empty");
            }
            count_node=0;
        }
        else if (strcmp(input, "insert") == 0) {
            scanf("%d", &num_data);
            scanf("%d", &data);
            if (num_data<count_node&&count_node>0){
                nodep_t current = top;
                for(int i=1;i<num_data;i++){
                    current = current->back;
                }
                nodep_t newNode = create(data);
                nodep_t save=current->back;
                save->front=newNode;
                newNode->back=save;
                current->back=newNode;
                newNode->front=current;
                count_node++;
            } else {
                strcpy(result[count_result++], "Invalid command");
            }
        }
        else if (strcmp(input, "remove") == 0) {
            scanf("%d", &num_data);
            if (num_data<count_node&&count_node>0){
                nodep_t current = top;
                for(int i=1;i<num_data;i++){
                    current = current->back;
                }
                nodep_t save=current->front;
                nodep_t save_back=current->back;
                save->back=save_back;
                save_back->front=save;
                free(current);
                count_node--;
            } else {
                strcpy(result[count_result++], "Invalid command");
            }
        }
        else if (strcmp(input, "print") == 0) {
            if (top) {
                nodep_t current = top;
                while (current) {
                    sprintf(result[count_result++], "%d", current->data);
                    current = current->back;
                }
            } else {
                strcpy(result[count_result++], "Double link list is empty");
            }
        }
    }
    return count_result;
}

int main() {
    int num = 0,count_result;
    char result[100][100] = {0};
    scanf("%d", &num);
    count_result=double_link(num, result);
    for (int i = 0; i < count_result; i++) {
        printf("%s\n", result[i]);
    }
    return 0;
}
