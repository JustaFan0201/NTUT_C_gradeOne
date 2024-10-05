#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
    int power;
    struct node_s *next;
} node_t;
typedef node_t *nodep_t;

nodep_t create(int power) {
    nodep_t newNode = (nodep_t)malloc(sizeof(node_t));
    newNode->power = power;
    newNode->next = NULL;
    return newNode;
}

int input(int data[2][100], int index) {
    char input_data[100];
    int i = 0, count = 0, neg = 0;
    fgets(input_data, 100, stdin);
    data[index][count] = 0;
    for (i = 0; i < 100; i++) {
        if (input_data[i] == ' ' && input_data[i + 1] == ' ') {
            break;
        } else if (input_data[i] == '\n') {
            if (neg == 1) {
                data[index][count] *= -1;
            }
            break;
        } else if (input_data[i] == ' ') {
            if (neg == 1) {
                data[index][count] *= -1;
            }
            count++;
            data[index][count] = 0;
            neg = 0;
        } else {
            if (input_data[i] >= '0' && input_data[i] <= '9') {
                data[index][count] = data[index][count] * 10 + (input_data[i] - '0');
            } else {
                neg = 1;
            }
        }
    }
    return count + 1;
}
void print(int save[100],int max){
    for (int i = max ; i >= 0; i--) {
        if (save[i] != 0) {
            if (i < max  && save[i] > 0) {
                printf("+");
            }
            if (i > 1) {
                if(save[i]==-1){
                    printf("-x^%d", i);
                }
                else if(save[i]==1){
                    printf("x^%d", i);
                }
                else{
                    printf("%dx^%d", save[i], i);
                }
            }
            else if (i == 1) {
                if(save[i]==-1){
                    printf("-x");
                }
                else if(save[i]==1){
                    printf("x");
                }
                else{
                    printf("%dx", save[i]);
                }
            }
            else {
                printf("%d", save[i]);
            }
        }
    }
    if (max == -1 || (max == 0 && save[0] == 0)) {
        printf("0");
    }
    printf("\n");
}
void add(int save[100], nodep_t list[2], int save_count[2]) {
    int max = 0;
    for (int i = 0; i < 2; i++) {
        nodep_t current = list[i];
        int count = save_count[i] - 1;
        while (current) {
            save[count] += current->power;
            current = current->next;
            count--;
        }
        if (save_count[i] > max) {
            max = save_count[i];
        }
    }
    for(int i=max;i>=0;i--){
        if(save[i]==0){
            max--;
        }
        else{
            break;
        }
    }
    print(save,max);
}

void sub(int save[100], nodep_t list[2], int save_count[2]) {
    int max = 0;
    for (int i = 0; i < 2; i++) {
        nodep_t current = list[i];
        int count = save_count[i] - 1;
        while (current) {
            save[count] += (i == 0 ? current->power : -current->power);
            current = current->next;
            count--;
        }
        if (save_count[i] > max) {
            max = save_count[i];
        }
    }
    for(int i=max;i>=0;i--){
        if(save[i]==0){
            max--;
        }
        else{
            break;
        }
    }
    print(save,max);
}

void mul(int result[200], nodep_t list[2], int save_count[2]) {
    // Initialize the result array with zeros
    for (int i = 0; i < 200; i++) {
        result[i] = 0;
    }

    // Get the lengths of the two polynomials
    int max1 = save_count[0];
    int max2 = save_count[1];

    // Multiply each term of the first polynomial with each term of the second polynomial
    nodep_t current1 = list[0];
    int i = max1 - 1;
    while (current1) {
        nodep_t current2 = list[1];
        int j = max2 - 1;
        while (current2) {
            result[i + j] += current1->power * current2->power;
            current2 = current2->next;
            j--;
        }
        current1 = current1->next;
        i--;
    }
    int max = (max1 - 1) + (max2 - 1);
    for(int i=max;i>=0;i--){
        if(result[i]==0){
            max--;
        }
        else{
            break;
        }
    }
    print(result, max);
}


void count() {
    int i, j;
    int data[2][100], save_count[2];
    nodep_t list[2] = {NULL, NULL}, now = NULL;
    for (i = 0; i < 2; i++) {
        save_count[i] = input(data, i);
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < save_count[i]; j++) {
            nodep_t new_node = create(data[i][j]);
            if (list[i] == NULL) {
                list[i] = new_node;
            }
            else {
                now->next = new_node;
            }
            now = new_node;
        }
        now = NULL;
    }

    int save_add[100] = {0};
    int save_subtract[100] = {0};
    int result_multiply[200] = {0};
    add(save_add, list, save_count);
    sub(save_subtract, list, save_count);
    mul(result_multiply, list, save_count);
}

int main() {
    count();
    return 0;
}
