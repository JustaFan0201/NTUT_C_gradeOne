#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100

typedef struct node_s {
    int id;
    struct node_s *nexts[30];
    int nextCount;
} task_t;

typedef task_t* pTask;

void input(int save[4]) {
    char data[50];
    fgets(data, 50, stdin);
    sscanf(data, "%d %d %d %d", &save[0], &save[1], &save[2], &save[3]);
}

void findPath(int current, int end, int adjMatrix[MAX_NODES][MAX_NODES], int visited[MAX_NODES], int path[MAX_NODES], int pathLen, int *shortestDist, int shortestPath[MAX_NODES], int mid, int *foundMid) {
    visited[current] = 1;
    path[pathLen++] = current;

    if (current == end) {
        if ((mid == -1 || *foundMid) && pathLen < *shortestDist) {
            *shortestDist = pathLen;
            for (int i = 0; i < pathLen; i++) {
                shortestPath[i] = path[i];
            }
        }
    } else {
        for (int i = 0; i < MAX_NODES; i++) {
            if (adjMatrix[current][i] && !visited[i]) {
                if (i == mid) {
                    *foundMid = 1;
                }
                findPath(i, end, adjMatrix, visited, path, pathLen, shortestDist, shortestPath, mid, foundMid);
                if (i == mid) {
                    *foundMid = 0;
                }
            }
        }
    }

    visited[current] = 0;
    pathLen--;
}

void travel(int num, int start, int end, int mid, int adjMatrix[MAX_NODES][MAX_NODES]) {
    int visited[MAX_NODES] = {0};
    int path[MAX_NODES];
    int shortestPath[MAX_NODES];
    int shortestDist = INT_MAX;
    int pathLen = 0;
    int foundMid = 0;

    findPath(start, end, adjMatrix, visited, path, pathLen, &shortestDist, shortestPath, mid, &foundMid);

    if (shortestDist == INT_MAX) {
        printf("NO\n");
    } else {
        printf("%d\n", shortestDist - 1);
        for (int i = 0; i < shortestDist; i++) {
            printf("%d ", shortestPath[i]);
        }
        printf("\n");
    }
}

int main() {
    int save[4] = {0};
    int adjMatrix[MAX_NODES][MAX_NODES] = {0};
    input(save);
    int num = save[0];
    int start = save[1];
    int end = save[2];
    int mid = save[3];
    if (mid == 0) {
        mid = -1;
    }
    for (int i = 0; i < num; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adjMatrix[a][b] = 1;
        adjMatrix[b][a] = 1;
    }
    travel(num, start, end, mid, adjMatrix);
    return 0;
}
