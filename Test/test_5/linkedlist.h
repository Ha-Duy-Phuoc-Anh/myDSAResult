#include <stdlib.h>

#pragma once

typedef struct Node {
    int* data;
    struct Node* next;
} Node;

Node* Node_init(int data) {
    Node* node = malloc(sizeof(Node));
    node->data = malloc(sizeof(int));
    *(node->data) = data;
    node->next = NULL;
    return node;
}
