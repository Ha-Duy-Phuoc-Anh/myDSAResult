#file [[Cây nhị phân]]

``` cpp
// Kiểu dữ liệu nút của cây nhị phân
struct Node {
    // Dữ liệu của nút
    int data;

    // Con trỏ đến hai nút tiếp theo
    Node* left;
    Node* right;

    // Hàm khởi tạo nút
    Node(int value) : data(value), left(nullptr), right(nullptr) {};
};
```

**Bài trước**: [[Cây nhị phân]]
**Bài sau**: [[Các giá trị trong cây nhị phân]]