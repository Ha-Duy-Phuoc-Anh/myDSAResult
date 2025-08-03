// Thêm các thư viện cần thiết
#include <iostream>
#include <vector>
    
// Khởi tạo kiểu dữ liệu
class Node {
    // Dữ liệu
    int data;

    // Nút con
    std::vector<Node*> child;

    // Khai báo dữ liệu
    Node(int val) : data(val), child({}) {};
};



int main() {

    return 0;
}