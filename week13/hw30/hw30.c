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

int queue_operations(int num, char result[100][100]) {
    int i, count_result = 0;
    char input[10];
    int data;
    nodep_t front = NULL;
    nodep_t rear = NULL;

    for (i = 0; i < num; i++) {
        scanf("%s", input);
        if (strcmp(input, "push") == 0) {
            scanf("%d", &data);
            nodep_t newNode = create(data);
            if (rear == NULL) {
                front = rear = newNode;
            } else {
                rear->next = newNode;
                rear = newNode;
            }
        } else if (strcmp(input, "front") == 0) {
            if (front) {
                sprintf(result[count_result++], "%d", front->data);
            } else {
                strcpy(result[count_result++], "Queue is empty");
            }
        } else if (strcmp(input, "empty") == 0) {
            if (front) {
                while (front) {
                    nodep_t temp = front;
                    front = front->next;
                    free(temp);
                }
                rear = NULL;
            } else {
                strcpy(result[count_result++], "Queue is empty");
            }
        } else if (strcmp(input, "pop") == 0) {
            if (front) {
                sprintf(result[count_result++], "%d", front->data);
                nodep_t temp = front;
                front = front->next;
                if (front == NULL) {
                    rear = NULL;
                }
                free(temp);
            } else {
                strcpy(result[count_result++], "Queue is empty");
            }
        } else if (strcmp(input, "print") == 0) {
            if (front) {
                nodep_t current = front;
                while (current) {
                    sprintf(result[count_result++], "%d", current->data);
                    current = current->next;
                }
            } else {
                strcpy(result[count_result++], "Queue is empty");
            }
        }
    }
    return count_result;
}

int main() {
    int num = 0, count_result;
    char result[100][100] = {0};
    scanf("%d", &num);
    count_result = queue_operations(num, result);
    for (int i = 0; i < count_result; i++) {
        printf("%s\n", result[i]);
    }
    return 0;
}
