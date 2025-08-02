#file [[Cấu trúc dữ liệu cây]]

``` cpp
// Khởi tạo kiểu dữ liệu
class Node {
    // Dữ liệu
    int data;

    // Nút con
    std::vector<Node*> child;

    // Khai báo dữ liệu
    Node(int val) : data(val), child({}) {};
};
```

> [!FAQ] Trông giống [[Danh sách liên kết]] không, thực ra cây chỉ khác biệt là số lượng con trỏ nhiều hơn thôi :)

---
**Bài trước**: [[Tại sao Cây lại là cấu trúc dữ liệu phi tuyến tính]]
**Bài sau**: [[Lợi ích và bất lợi khi dùng cấu trúc dữ liệu cây]]