#include <iostream>
#include "linkedlist.hpp"

class Stack {
private:
  // Khởi tạo top (không cần capacity vì đây là Dyamic Stack)
  int top;

  // Tạo Danh sách liên kết cho Stack
  LinkedList head;

public:
  // Hàm khởi tạo đối tượng Stack
  Stack() : top(-1) {};

  // Method push vào Stack
  void push(int data) {
    head.push_front(data);
    top++;
  }

  // Method pop khỏi Stack
  int pop() {
    if (top < 0) {
      std::cerr << "ERROR 001: Stack underflow (Stack is empty)" << ENTER;
      return -1;
    }
    top--;
    return head.pop_front();
  }

  // Method peek giá trị của top
  int peek() const {
    return head.at(top);
  }

  // Method kiểm tra Stack rỗng
  bool isEmpty() const {
    return top < 0;
  }

  // Method hiển thị Stack
  void display() const {
    std::cout << "|";
    for (int i = top; i > -1; --i) {
      std::cout << ' ' << head.at(i) << " |";
    }
    std::cout << ENTER;
  }

  // Hàm hủy Stack
  ~Stack() {
    head.~LinkedList();
  }
};

int main() {
    Stack newStack;
    newStack.push(1);
    newStack.push(2);
    newStack.push(3);
    newStack.push(4);
    
    std::cout << "Before Delete: ";
    newStack.display();

    newStack.pop();
    newStack.pop();

    std::cout << "After Delete: ";
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

    return 0;
}