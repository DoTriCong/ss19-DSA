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

typedef struct QueueNode {
    Node* treeNode;
    struct QueueNode* next;
} QueueNode;

QueueNode* createQueueNode(Node* treeNode) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->treeNode = treeNode;
    newNode->next = NULL;
    return newNode;
}

void enqueue(QueueNode** front, QueueNode** rear, Node* treeNode) {
    QueueNode* newNode = createQueueNode(treeNode);
    if (*rear == NULL) {
        *front = *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

Node* dequeue(QueueNode** front, QueueNode** rear) {
    if (*front == NULL) return NULL;
    QueueNode* temp = *front;
    Node* result = temp->treeNode;
    *front = (*front)->next;
    if (*front == NULL) *rear = NULL;
    free(temp);
    return result;
}

int searchBFS(Node* root, int target) {
    if (root == NULL) return 0;
    QueueNode* front = NULL;
    QueueNode* rear = NULL;
    enqueue(&front, &rear, root);
    while (front != NULL) {
        Node* current = dequeue(&front, &rear);
        if (current->data == target) return 1;
        if (current->left != NULL) enqueue(&front, &rear, current->left);
        if (current->right != NULL) enqueue(&front, &rear, current->right);
    }
    return 0;
}

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    Node* root = createNode(3);
    root->left = createNode(2);
    root->right = createNode(4);
    root->left->left = createNode(1);
    root->left->right = createNode(5);
    int target = 5;
    if (searchBFS(root, target)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}
