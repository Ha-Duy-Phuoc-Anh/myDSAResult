#include <iostream>

// Khởi tạo kiểu dữ liệu
class Queue {
private:
    // FRONT và REAR
    int head, tail;

    // Kích thước
    int capacity;

    // Dữ liệu
    int* data;

public:
    // Khởi tạo Hàng đợi
    Queue(int size) : head(0), tail(-1), capacity(size), data(new int[capacity]) {};

    // Hàm enqueue
    void enqueue(int value) {
        if (this->isFull()) {
            std::cout << "ERROR 002: Queue is full" << std::endl;
            return;
        }
        data[++tail] = value;
    }

    // Hàm deque (khá phức tạp, vì phải di chuyển element)
    void dequeue() {
        if (this->isEmpty()) {
            std::cout << "ERROR 001: Queue is empty" << std::endl;
            return;
        };
        for (int i = head; i < tail; i++) {
            data[i] = data[i + 1];
        }
        tail--;
    }

    // Hàm lấy giá trị của Front
    int peek() {
        return data[head];
    }

    // Hàm lấy kích thước hiện tại của hàng đợi
    int size() {
        return tail;
    }

    // Hàm kiểm tra hàng đợi rỗng
    bool isEmpty() {
        return head > tail;
    }

    // Hàm kiểm tra hàng đợi đầy
    bool isFull() {
        return tail >= capacity - 1;
    }

    // Hàm hiển thị Queue
    void display() {
        for (int i = head; i <= tail; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    // Hàm xóa hàng đợi giải phóng bộ nhớ
    ~Queue() {
        delete[] data;
    }
};

int main() {
    Queue newQueue(4);
    newQueue.enqueue(31);
    newQueue.enqueue(28);
    newQueue.enqueue(54);
    newQueue.enqueue(49);

    std::cout << "Before delete: ";
    newQueue.display();

    std::cout << "Is queue full: " << (newQueue.isFull() ? "TRUE" : "FALSE") << std::endl;
    std::cout << "Is queue empty: " << (newQueue.isEmpty() ? "TRUE" : "FALSE") << std::endl;

    newQueue.dequeue();
    newQueue.dequeue();

    std::cout << "Size after 2 dequeue: " << newQueue.size() << std::endl;
    std::cout << "The FRONT element: " << newQueue.peek() << std::endl;

    newQueue.dequeue();
    newQueue.dequeue();

    std::cout << "Is queue full after dequeue: " << (newQueue.isFull() ? "TRUE" : "FALSE") << std::endl;
    std::cout << "Is queue empty after dequeue: " << (newQueue.isEmpty() ? "TRUE" : "FALSE") << std::endl;

    return 0;
}