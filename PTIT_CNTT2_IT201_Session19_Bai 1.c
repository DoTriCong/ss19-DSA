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

int main() {
    int value;
    printf("Nhap gia tri cho nut: ");
    scanf("%d", &value);

    Node* root = createNode(value);
    printf("Nut duoc tao: { data: %d, left->NULL, right->NULL }\n", root->data);

    return 0;
}
