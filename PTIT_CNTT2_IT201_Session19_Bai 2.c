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

void preorder(Node* root) {
    if (root == NULL) return;
    printf("%d\n", root->data);
    preorder(root->left);
    preorder(root->right);
}
int main() {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->right = createNode(5);
    preorder(root);
    return 0;
}
