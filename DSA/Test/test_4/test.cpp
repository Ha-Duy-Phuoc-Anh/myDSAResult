#include <iostream>

#define ENTER '\n'

class Stack {
private:
	// Khởi tạo TOP và CAPACITY
	int top;
  size_t capacity;

	// Khởi tạo con trỏ mảng
	int *stack;

public:
  // Hàm khởi tạo đối tượng
  Stack(size_t size) {
    top = -1;
    capacity = size;
    stack = new int[capacity];
  }

  // Hàm push vào Stack
  void push(int data) {
    // Kiểm tra nếu Stack đầy
    if (top >= (int)capacity - 1) {
      std::cout << "ERROR 001: Stack is full, overflow error" << ENTER;
      return;
    }

    // Đẩy dữ liệu vào nếu không có lỗi gì
    stack[++top] = data;
  }

  // Hàm pop khỏi Stack
  int pop() {
    // Nếu Stack rỗng thì báo lỗi
    if (top < 0) {
      std::cout << "ERROR 002: Stack is empty, underflow error" << ENTER;
      return -1;
    }

    // Nếu không thì tiếp tục
    int popedValue = stack[top];
    top--;
    return popedValue;
  }

  // Hàm lấy giá trị của top
  int peek() const {
    if (this->isEmpty()) {
      std::cout << "ERROR 003: Stack is empty, can't peek" << ENTER;
      return -1;
    }
    return stack[top];
  }

  // Hàm kiểm tra Stack rỗng
  bool isEmpty() const {
    return top < 0;
  }

  // Hàm kiểm tra Stack đầy
  bool isFull() const {
    return top >= capacity - 1;
  }

  // Hàm hiển thị Stack
  void display() const {
    std::cout << "|";
    for (int i = top; i > -1; --i) {
      std::cout << ' ' << stack[i] << " |";
    }
    std::cout << ENTER;
  }

  // Hảm hủy Stack (Destructor)
  ~Stack() {
    delete[] stack;
  }
};


int main() {
    Stack newStack(4);
    newStack.push(1);
    newStack.push(2);
    newStack.push(3);
    newStack.push(4);
    
    std::cout << "Before Delete: ";
    newStack.display();
    
    std::cout << "Is stack full: "
              << (newStack.isFull() ? "TRUE" : "FALSE")
              << ENTER;

    newStack.pop();
    newStack.pop();

    printf("After Delete: ");
    newStack.display();

    std::cout << "Is stack empty: "
              << (newStack.isEmpty() ? "TRUE" : "FALSE")
              << ENTER;

    newStack.pop();

    std::cout << "TOP Element: " << newStack.peek() << ENTER;

    newStack.pop();

    std::cout << "Is stack empty: "
              << (newStack.isEmpty() ? "TRUE" : "FALSE")
              << ENTER;
    std::cout << "Is stack full: "
              << (newStack.isFull() ? "TRUE" : "FALSE")
              << ENTER;

    return 0;
}