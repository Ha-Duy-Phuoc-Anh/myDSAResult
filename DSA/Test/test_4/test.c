#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack {
    // Khởi tạo top và kích thước
    int top, capacity;

    // Khởi tạo con trỏ mảng
    int* data;
} Stack;

// Hàm khởi tạo Stack
Stack* init(int capacity) {
    Stack* stack = (Stack*) malloc(sizeof(Stack));  // Cấp phát bộ nhớ cho Stack
    stack->capacity = capacity; // Lưu dữ liệu dung lượng của Stack
    stack->top = -1;    // Chỉnh top xuống vị trí -1
    stack->data = (int*) malloc(sizeof(int) * capacity);    // Cấp phát bộ nhớ cho dữ liệu
    return stack;   // Trả về Stack có đầy đủ công cụ
}

// Hàm thêm dữ liệu vào Stack
Stack* Stack_push(Stack* stack, int data) {
    // Kiểm tra nếu Stack đầy
    if (stack->top >= stack->capacity - 1) {
        printf("ERROR 001: Stack is full, overflow error\n");
        return stack;
    }

    // Đẩy dữ liệu vào
    stack->data[++stack->top] = data;

    // Trả về Stack đã chỉnh sửa
    return stack;
}

// Hàm xóa dữ liệu khỏi Stack
Stack* Stack_pop(Stack* stack) {
    // Kiểm tra nếu Stack rỗng
    if (stack->top < 0) {
        printf("ERROR 002: Stack is empty, underflow error\n");
        return stack;
    }

    // Xóa dữ liệu khỏi Stack
    stack->top--;

    // Trả về Stack đã được chỉnh sửa
    return stack;
}

// Hàm lấy giá trị của top
int Stack_peek(Stack* stack) {
    return stack->data[stack->top];
}

// Hàm kiểm tra Stack rỗng
bool Stack_isEmpty(Stack* stack) {
    return stack->top < 0;
} 

// Hàm kiểm tra Stack đầy
bool Stack_isFull(Stack* stack) {
    return stack->top >= stack->capacity - 1;
}

// Hầm ghi ra Stack
void Stack_print(Stack* stack) {
    for (int i = stack->top; i > -1; --i) {
        printf("%i ", stack->data[i]);
    }
    printf("\n");
} 

// Hàm xóa Stack
void Stack_free(Stack* stack) {
    free(stack->data);
    free(stack);
}

int main() {
    Stack* newStack = init(4);
    newStack = Stack_push(newStack, 1);
    newStack = Stack_push(newStack, 2);
    newStack = Stack_push(newStack, 3);
    newStack = Stack_push(newStack, 4);
    
    printf("Before Delete: ");
    Stack_print(newStack);
    
    printf("Is stack full: %s\n", (Stack_isFull(newStack) ? "TRUE" : "FALSE"));

    Stack_pop(newStack);
    Stack_pop(newStack);

    printf("After Delete: ");
    Stack_print(newStack);

    printf("Is stack empty: %s\n", (Stack_isEmpty(newStack) ? "TRUE" : "FALSE"));

    Stack_pop(newStack);

    printf("TOP Element: %i\n", Stack_peek(newStack));

    Stack_pop(newStack);

    printf("Is stack empty: %s\n", (Stack_isEmpty(newStack) ? "TRUE" : "FALSE"));
    printf("Is stack full: %s\n", (Stack_isFull(newStack) ? "TRUE" : "FALSE"));

    Stack_free(newStack);

    return 0;
}