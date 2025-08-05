#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include "linkedlist.h"

typedef struct Stack {
    Node* head;
} Stack;

// Hàm khởi tạo Stack
Stack* init() {
    Stack* tmp = malloc(sizeof(Stack));
    tmp->head = NULL;
    return tmp;
}

// Hàm thêm dữ liệu vào Stack
Stack* Stack_push(Stack* root, int data) {
    Node* newNode = Node_init(data);
    newNode->next = root->head;
    root->head = newNode; 
    return root;      
} 

// Hàm xóa dữ liệu khỏi Stack
Stack* Stack_pop(Stack* root) {
    if (root->head == NULL) {
        printf("ERROR 001: Stack is empty\n");
    }
    else {
        Node* tmp = root->head;
        root->head = root->head->next;
        free(tmp->data);
        free(tmp);
    }
    return root;
}

// Hàm lấy dữ liệu của TOP
int Stack_peek(Stack* root) {
    if (!root->head) {
        printf("ERROR 001: Stack is empty\n");
        return INT_MIN;
    }
    else {
        return *(root->head->data);
    }
}

// Hàm kiểm tra Stack rỗng
bool Stack_isEmpty(Stack* root) {
    return root->head == NULL;
}

// Hàm ghi Stack ra CLI
void Stack_print(Stack* root) {
    Node* curr = root->head;
    while (curr != NULL) {
        printf("%i \n", *curr->data);
        curr = curr->next;
    }
    printf("\n");
}


// Hàm xóa Stack giải phóng bộ nhớ
void Stack_free(Stack* root) {
    Node* curr = root->head;
    while (curr != NULL) {
        Node* temp = curr;
        curr = curr->next;
        free(temp->data);
        free(temp);
    }
    free(root);
}

int main() {
    Stack* newStack = init();
    newStack = Stack_push(newStack, 1);
    newStack = Stack_push(newStack, 2);
    newStack = Stack_push(newStack, 3);
    newStack = Stack_push(newStack, 4);
    
    printf("Before Delete: ");
    Stack_print(newStack);

    newStack = Stack_pop(newStack);
    newStack = Stack_pop(newStack);

    printf("After Delete: ");
    Stack_print(newStack);

    printf("Is stack empty: %s\n", (Stack_isEmpty(newStack) ? "TRUE" : "FALSE"));

    newStack = Stack_pop(newStack);

    printf("TOP Element: %i\n", Stack_peek(newStack));

    newStack = Stack_pop(newStack);

    printf("Is stack empty: %s\n", (Stack_isEmpty(newStack) ? "TRUE" : "FALSE"));

    Stack_free(newStack);

    return 0;
}