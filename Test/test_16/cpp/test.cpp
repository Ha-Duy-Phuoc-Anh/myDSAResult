// Thêm các thư viện cần thiết
#include <iostream>
#include <vector>
    
// Khởi tạo kiểu dữ liệu
class Tree {
    // Dữ liệu
    int data;

    // Nút con
    std::vector<Tree*> child;

    // Khai báo dữ liệu
    Tree(int val) : data(val), child({}) {};
};

int main() {

    return 0;
}