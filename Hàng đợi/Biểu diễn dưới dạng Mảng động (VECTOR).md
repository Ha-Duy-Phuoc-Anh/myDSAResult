#file [[Hàng đợi]]

## Mẫu FULL Method
---
``` cpp
// Khởi tạo kiểu dữ liệu
class Queue {
private:
    // Khởi tạo Mảng
    std::vector<int> data;

public:
    // Không cần hàm khởi tạo

    // Hàm enqueue
    void enqueue(int value) {
        data.push_back(value);
    }

    // Hàm dequeue
    void dequeue() {
        if (this->isEmpty()) {
            std::cout << "ERROR 001: Queue is empty" << std::endl;
            return;
        };
        data.erase(data.begin());
    }

    // Hàm lấy giá trị của Front
    int peek() {
        return this->isEmpty() ? -1 : data.front();
    }

    // Hàm lấy kích thước hiện tại của hàng đợi
    int size() {
        return data.size();
    }

    // Hàm kiểm tra hàng đợi rỗng
    bool isEmpty() {
        return data.size() == 0;
    }

    // Hàm hiển thị Queue
    void display() {
        for (const auto& i : data) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    // Hàm xóa hàng đợi giải phóng bộ nhớ (không cần vì Vector đã tự động giải quyết)
};
```