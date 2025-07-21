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

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d\n", root->data);
    inorder(root->right);
}

int main() {
    Node* root = createNode(2);
    root->left = createNode(5);
    root->right = createNode(3);
    root->right->left = createNode(2);
    root->right->right = createNode(4);
    root->right->left->left = createNode(5);
    inorder(root);
    return 0;
}
