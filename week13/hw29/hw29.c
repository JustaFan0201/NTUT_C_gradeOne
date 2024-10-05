#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
    int data;
    struct node_s *next;
} node_t;

typedef node_t *nodep_t;

nodep_t create(int data) {
    nodep_t newNode = (nodep_t)malloc(sizeof(node_t));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int stack_mine(int num, char result[100][100]) {
    int i, count_result = 0;
    char input[10];
    int data;
    nodep_t top = NULL;

    for (i = 0; i < num; i++) {
        scanf("%s", input);
        if (strcmp(input, "push") == 0) {
            scanf("%d", &data);
            nodep_t newNode = create(data);
            newNode->next = top;
            top = newNode;
        } else if (strcmp(input, "top") == 0) {
            if (top) {
                sprintf(result[count_result++], "%d", top->data);
            } else {
                strcpy(result[count_result++], "Stack is empty");
            }
        } else if (strcmp(input, "empty") == 0) {
            if (top) {
                while (top) {
                    nodep_t temp = top;
                    top = top->next;
                    free(temp);
                }
            } else {
                strcpy(result[count_result++], "Stack is empty");
            }
        } else if (strcmp(input, "pop") == 0) {
            if (top) {
                sprintf(result[count_result++], "%d", top->data);
                nodep_t temp = top;
                top = top->next;
                free(temp);
            } else {
                strcpy(result[count_result++], "Stack is empty");
            }
        } else if (strcmp(input, "print") == 0) {
            if (top) {
                nodep_t current = top;
                while (current) {
                    sprintf(result[count_result++], "%d", current->data);
                    current = current->next;
                }
            } else {
                strcpy(result[count_result++], "Stack is empty");
            }
        }
    }
    return count_result;
}

int main() {
    int num = 0,count_result;
    char result[100][100] = {0};
    scanf("%d", &num);
    count_result=stack_mine(num, result);
    for (int i = 0; i < count_result; i++) {
        printf("%s\n", result[i]);
    }
    return 0;
}
