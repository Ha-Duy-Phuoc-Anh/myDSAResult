#file [[Cây nhị phân]]

``` cpp
// Khởi tạo kiểu dữ liệu
class Node {
    // Dữ liệu
    int data;

    // Nút con
    Node* left;
    Node* right;

    // Khai báo dữ liệu
    Node(int val) : data(val), left(nullptr), right(nullptr) {};
};
```
---
**Bài trước**: [[Cây nhị phân]]
**Bài sau**: [[Các giá trị trong cây nhị phân]]