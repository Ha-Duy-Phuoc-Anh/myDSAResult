#include <iostream>

#define ENTER '\n'

class Queue {
private:
	// Khởi tạo head và tail
	int head, tail;

	// Kích thước của hàng đợi
	size_t capacity;

	// Mảng dữ liệu cho dữ liệu trong hàng đợi
	int *queue;

public:
	// Hàm khởi tạo đối tượng hàng đợi
	Queue(size_t size) {
		head = 0;
		tail = -1;
		capacity = size;
		queue = new int[capacity];
	}

	// Method enqueue vào trong hàng đợi
	void enqueue(int data) {
		// Nếu hàng đợi đầy
		if (tail >= (int)capacity - 1) {
			std::cerr << "ERROR 001: Queue is full" << ENTER;
			return;
		}
		
		// Nếu không thì thêm dữ liệu vào mảng queue
		queue[++tail] = data;
	}

	// Method dequeue khỏi hàng đợi
	void dequeue() {
		// Nếu Queue rỗng
		if (head > tail) {
			std::cerr << "ERROR 002: Queue is empty" << ENTER;
			return;
		}

		// Dịch chuyển các mảnh dữ liệu trong queue để đẩy phần tử được
		// dequeue ra
		for (int i = head; i < tail; i++)
			queue[i] = queue[i + 1];
		
		tail--;
	}

	// Method peek của Queue
	int peek() const {
		return queue[head];
	}

	// Method lấy kích thước của Queue
	size_t size() const {
		return (size_t)tail;
	}

	// Method kiểm tra Queue rỗng
	bool isEmpty() const {
		return head > tail;
	}

	// Method kiểm tra Queue đầy
	bool isFull() const {
		return tail >= (int)capacity - 1;
	}

	// Method hiển thị Queue
	void display() const {
		std::cout << "|";
		for (int i = tail; i > -1; --i) {
			std::cout << ' ' << queue[i] << " |";
		}
		std::cout << ENTER;
	}

	// Destructor giải phóng bộ nhớ
	~Queue() {
		delete[] queue;
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

    std::cout << "Is queue full: "
			  << (newQueue.isFull() ? "TRUE" : "FALSE")
			  << ENTER;

    std::cout << "Is queue empty: "
			  << (newQueue.isEmpty() ? "TRUE" : "FALSE")
			  << ENTER;

    newQueue.dequeue();
    newQueue.dequeue();

    std::cout << "Size after 2 dequeue: " 
			  << newQueue.size()
			  << ENTER;

    std::cout << "The FRONT element: " 
			  << newQueue.peek()
			  << ENTER;

    newQueue.dequeue();
    newQueue.dequeue();

    std::cout << "Is queue full after dequeue: "
			  << (newQueue.isFull() ? "TRUE" : "FALSE")
			  << ENTER;

    std::cout << "Is queue empty after dequeue: " 
			  << (newQueue.isEmpty() ? "TRUE" : "FALSE")
			  << ENTER;

    return 0;
}