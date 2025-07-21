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

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void addValue(Node* root, int value) {
    if (root == NULL) return;
    QueueNode* front = NULL;
    QueueNode* rear = NULL;
    enqueue(&front, &rear, root);

    while (front != NULL) {
        Node* current = dequeue(&front, &rear);
        if (current->left == NULL) {
            current->left = createNode(value);
            return;
        } else {
            enqueue(&front, &rear, current->left);
        }

        if (current->right == NULL) {
            current->right = createNode(value);
            return;
        } else {
            enqueue(&front, &rear, current->right);
        }
    }
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d\n", root->data);
    inorder(root->right);
}

int main() {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    addValue(root, 6);
    inorder(root);
    return 0;
}
