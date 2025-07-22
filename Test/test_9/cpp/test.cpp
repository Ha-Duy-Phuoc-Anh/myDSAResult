#include <iostream>
#include "linkedlist"

// Khởi tạo kiểu dữ liệu
class Queue {
private:
    // Khởi tạo hai nút FRONT và REAR
    Node* front;
    Node* rear;

public:
    // Khởi tạo Hàng đợi
    Queue() : front(nullptr), rear(nullptr) {};

    // Hàm enqueue
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (this->isEmpty()) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    // Hàm deque
    void dequeue() {
        if (this->isEmpty()) {
            std::cout << "ERROR 001: Queue is empty" << std::endl;
            return;
        }

        Node* tmp = front;
        front = front->next;
        if (front == nullptr) rear = nullptr;

        delete tmp;
    }

    // Hàm lấy giá trị của Front
    int peek() {
        return front->data;
    }

    // Hàm lấy kích thước hiện tại của hàng đợi
    int size() {
        Node* curr = front;
        int length = 0;
        while (curr != rear) {
            curr = curr->next;
            length++;
        }
        return length;
    }

    // Hàm kiểm tra hàng đợi rỗng
    bool isEmpty() {
        return front == nullptr && rear == nullptr;
    }

    // Hàm hiển thị Queue
    void display() {
        Node* curr = front;
        while (curr != rear) {
            std::cout << curr->data << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }

    // Hàm xóa hàng đợi giải phóng bộ nhớ
    ~Queue() {
        while (front != rear && front != nullptr && rear != nullptr) {
            Node* tmp = front;
            front = front->next;
            if (front == nullptr) rear = nullptr;
            delete tmp;
        }
    }
};

int main() {
    Queue newQueue;
    newQueue.enqueue(31);
    newQueue.enqueue(28);
    newQueue.enqueue(54);
    newQueue.enqueue(49);

    std::cout << "Before delete: ";
    newQueue.display();

    std::cout << "Is queue empty: " << (newQueue.isEmpty() ? "TRUE" : "FALSE") << std::endl;

    newQueue.dequeue();
    newQueue.dequeue();

    std::cout << "Size after 2 dequeue: " << newQueue.size() << std::endl;
    std::cout << "The FRONT element: " << newQueue.peek() << std::endl;

    newQueue.dequeue();
    newQueue.dequeue();

    std::cout << "Is queue empty after dequeue: " << (newQueue.isEmpty() ? "TRUE" : "FALSE") << std::endl;

    return 0;
}