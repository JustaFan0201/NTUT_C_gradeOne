#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s {
    char data;
    struct node_s *left, *right;
} tree_t;

typedef tree_t *btree;

// ¨ç¼Æ«Å§i
btree buildTreeFromPreIn(char pre[], char in[], int inStart, int inEnd, int *preIndex);
btree buildTreeFromPostIn(char post[], char in[], int inStart, int inEnd, int *postIndex);
void printLevelOrder(btree root);
void printGivenLevel(btree root, int level);
int height(btree node);
int search(char arr[], int strt, int end, char value);

int main() {
    char orderType1, orderType2;
    char traversal1[21], traversal2[21];

    scanf(" %c", &orderType1);
    scanf("%s", traversal1);
    scanf(" %c", &orderType2);
    scanf("%s", traversal2);

    btree root = NULL;
    int preIndex = 0;
    int postIndex = strlen(traversal1) - 1;

    if (orderType1 == 'P' && orderType2 == 'I') {
        root = buildTreeFromPreIn(traversal1, traversal2, 0, strlen(traversal2) - 1, &preIndex);
    } else if (orderType1 == 'O' && orderType2 == 'I') {
        root = buildTreeFromPostIn(traversal1, traversal2, 0, strlen(traversal2) - 1, &postIndex);
    } else if (orderType1 == 'I' && orderType2 == 'P') {
        root = buildTreeFromPreIn(traversal2, traversal1, 0, strlen(traversal1) - 1, &preIndex);
    } else if (orderType1 == 'I' && orderType2 == 'O') {
        root = buildTreeFromPostIn(traversal2, traversal1, 0, strlen(traversal1) - 1, &postIndex);
    }

    if (root) {
        printLevelOrder(root);
    }

    return 0;
}

btree buildTreeFromPreIn(char pre[], char in[], int inStart, int inEnd, int *preIndex) {
    if (inStart > inEnd) {
        return NULL;
    }

    btree node = (btree)malloc(sizeof(tree_t));
    node->data = pre[(*preIndex)++];
    node->left = node->right = NULL;

    if (inStart == inEnd) {
        return node;
    }

    int inIndex = search(in, inStart, inEnd, node->data);
    node->left = buildTreeFromPreIn(pre, in, inStart, inIndex - 1, preIndex);
    node->right = buildTreeFromPreIn(pre, in, inIndex + 1, inEnd, preIndex);

    return node;
}

btree buildTreeFromPostIn(char post[], char in[], int inStart, int inEnd, int *postIndex) {
    if (inStart > inEnd) {
        return NULL;
    }

    btree node = (btree)malloc(sizeof(tree_t));
    node->data = post[(*postIndex)--];
    node->left = node->right = NULL;

    if (inStart == inEnd) {
        return node;
    }

    int inIndex = search(in, inStart, inEnd, node->data);
    node->right = buildTreeFromPostIn(post, in, inIndex + 1, inEnd, postIndex);
    node->left = buildTreeFromPostIn(post, in, inStart, inIndex - 1, postIndex);

    return node;
}

void printLevelOrder(btree root) {
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        printGivenLevel(root, i);
    }
}

void printGivenLevel(btree root, int level) {
    if (root == NULL) {
        return;
    }
    if (level == 1) {
        printf("%c", root->data);
    } else if (level > 1) {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

int height(btree node) {
    if (node == NULL) {
        return 0;
    } else {
        int lheight = height(node->left);
        int rheight = height(node->right);

        return (lheight > rheight) ? (lheight + 1) : (rheight + 1);
    }
}

int search(char arr[], int strt, int end, char value) {
    for (int i = strt; i <= end; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}
