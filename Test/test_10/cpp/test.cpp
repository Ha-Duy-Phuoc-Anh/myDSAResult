#include <iostream>

// Gọi thư viện deque
#include <deque>


// Hàm hiển thị Deque
void display(std::deque<int> queue) {
    for (const auto& i : queue) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Khởi tạo deque
    std::deque<int> newQueue;

    // Thêm dữ liệu ở sau
    newQueue.push_back(13);
    newQueue.push_back(89);
    newQueue.push_back(67);
    newQueue.push_back(105);

    // Hiển thị Queue
    display(newQueue);

    // Thêm dữ liệu ở trước
    newQueue.push_front(87);
    newQueue.push_front(64);
    newQueue.push_front(35);
    newQueue.push_front(84);

    // Hiển thị Queue
    display(newQueue);

    // Xóa dữ liệu ở trước
    newQueue.pop_front();
    newQueue.pop_front();

    // Hiển thị Queue
    display(newQueue);

    // Xóa dữ liệu ở sau
    newQueue.pop_back();
    newQueue.pop_back();

    // Hiển thị Queue
    display(newQueue);

    // Hiển thị kích thước của Queue
    std::cout << "The size of Deque is: " << newQueue.size() << std::endl;

    // Xóa toàn bộ Queue
    newQueue.clear();

    // Cho biết Queue có rỗng không
    std::cout << "Is Queue empty: " << (newQueue.empty() ? "TRUE" : "FALSE") << std::endl;

    return 0;
}