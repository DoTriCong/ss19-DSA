//
// Created by 84366 on 21/07/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong the cap phat bo nho.\n");
        return NULL;
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int searchDFS(Node* root, int target) {
    if (root == NULL) return 0;
    if (root->data == target) return 1;
    return searchDFS(root->left, target) || searchDFS(root->right, target);
}

int main() {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->right = createNode(5);
    int target = 5;
    if (searchDFS(root, target)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}
