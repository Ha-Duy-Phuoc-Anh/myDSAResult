#include <iostream>

class Stack {
private:
    // Khởi tạo top, và kích thước
    int top, capacity;

    // Khởi tạo con trỏ mảng
    int* data;

public:
    // Hàm khởi tạo Stack
    Stack(int size) : top(-1), capacity(size), data(new int[capacity]) {};

    // Hàm thêm dữ liệu vào Stack
    bool push(int value) {
        // Kiểm tra nếu Stack đầy
        if (top >= capacity - 1) {
            std::cout << "ERROR 001: Stack is full" << std::endl;
            return false;
        }

        // Đẩy dữ liệu vào
        data[++top] = value;

        // Cho thấy hoạt động thành công
        return true;
    }

    // Hàm xóa dữ liệu khỏi Stack
    int pop() {
        // Kiểm tra nếu Stack rỗng
        if (top < 0) {
            std::cout << "ERROR 002: Stack is empty" << std::endl;
            return 0;
        }

        // Xóa dữ liệu khỏi Stack và trả về dữ liệu đó
        return data[top--];
    } 

    // Hàm lấy giá trị của top
    int peek() {
        return data[top];
    }

    // Hàm kiểm tra Stack rỗng
    bool isEmpty() {
        return top < 0;
    }

    // Hàm kiểm tra Stack đầy
    bool isFull() {
        return top >= capacity - 1;
    }

    // Hàm ghi ra Stack
    void print() {
        for (int i = top; i > -1; --i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    // Hàm xóa stack
    ~Stack() { delete[] data; };
};

int main() {
    Stack newStack(4);
    newStack.push(1);
    newStack.push(2);
    newStack.push(3);
    newStack.push(4);
    
    std::cout << "Before Delete: ";
    newStack.print();
    
    std::cout << "Is stack full: " << (newStack.isFull() ? "TRUE" : "FALSE") << std::endl;

    newStack.pop();
    newStack.pop();

    std::cout << "After Delete: ";
    newStack.print();

    std::cout << "Is stack empty: " << (newStack.isEmpty() ? "TRUE" : "FALSE") << std::endl;

    newStack.pop();

    std::cout << "TOP Element: " << newStack.peek() << std::endl;

    newStack.pop();

    std::cout << "Is stack empty: " << (newStack.isEmpty() ? "TRUE" : "FALSE") << std::endl;
    std::cout << "Is stack full: " << (newStack.isFull() ? "TRUE" : "FALSE") << std::endl;

    return 0;
}