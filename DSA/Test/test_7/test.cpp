#include <iostream>
#include "linkedlist.hpp"


class Queue {
private:
	// Danh sách liên kết dữ liệu trong hàng đợi
	LinkedList queue;

public:
	// Hàm khởi tạo đối tượng hàng đợi
	Queue(size_t size) {} // size không cần thiết vì LinkedList có thể tự động mở rộng

	// Method enqueue vào trong hàng đợi
	void enqueue(int data) {
		// Thêm dữ liệu vào cuối queue
		queue.push_back(data);
	}

	// Method dequeue khỏi hàng đợi
	void dequeue() {
		// Nếu Queue rỗng thì pop_front sẽ tự động xử lý lỗi
		queue.pop_front();
	}

	// Method peek của Queue
	int peek() const {
		// Lấy phần tử đầu tiên (index 0)
		return queue.at(0);
	}

	// Method lấy kích thước của Queue
	size_t size() const {
		return queue.size();
	}

	// Method kiểm tra Queue rỗng
	bool isEmpty() const {
		return queue.size() == 0;
	}

	// Method hiển thị Queue
	void display() const {
		if (isEmpty()) {
			std::cout << "Queue is empty" << ENTER;
			return;
		}
		std::cout << "|";
		for (int i = 0; i < queue.size(); ++i) {
			std::cout << ' ' << queue.at(i) << " |";
		}
		std::cout << ENTER;
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

    std::cout << "Is queue empty: "
			  << (newQueue.isEmpty() ? "TRUE" : "FALSE")
			  << ENTER;

    newQueue.dequeue();
    newQueue.dequeue();

	std::cout << "After delete: ";
    newQueue.display();

    std::cout << "Size after 2 dequeue: " 
			  << newQueue.size()
			  << ENTER;

    std::cout << "The FRONT element: " 
			  << newQueue.peek()
			  << ENTER;

    newQueue.dequeue();
    newQueue.dequeue();

    std::cout << "Is queue empty after dequeue: " 
			  << (newQueue.isEmpty() ? "TRUE" : "FALSE")
			  << ENTER;

    return 0;
}