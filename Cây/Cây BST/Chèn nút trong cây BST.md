#file [[Cây BST]]

## **Mô tả thuật toán**
- Khởi tạo nút mới với dữ liệu đã cho
- So sánh với nút gốc
- Nếu lớn hơn thì di chuyển sang phải
- Nếu nhỏ hơn thì di chuyển sang trái
- Lặp từ bước 2 đến bước 4 cho đến khi tìm thấy nút lá
- Chèn nút dựa trên so sánh

## **Thực hiện thuật toán**
## Tiếp cận đệ quy
``` cpp
// Hàm thêm nút vào cây
Node* Tree_Insert(Node* root, int value) {
    // Nếu cây rỗng, nút mới sẽ là root của cây (hoặc là cây phụ)
    if (root == nullptr) {
        root = new Node(value);
        return root;
    }

    // Nếu nút trùng với giá trị của một nút khác trong cây thì từ chối chèn
    if (value == root->data) return root;

    // Kiểm tra nếu lớn hơn nút gốc thì đệ quy bên phải
    if (value > root->data) root->right = Tree_Insert(root->right, value);

    // Kiểm tra nếu bé hơn nút gốc thì đệ quy bên trái
    if (value < root->data) root->left = Tree_Insert(root->left, value);

    // Trả về cây đã chỉnh sửa
    return root;
}
```

**Thời gian**: $O(h)$
**Bộ nhớ**: $O(h)$
## Tiếp cận tuần tự
---
``` cpp
// Hàm thêm nút vào cây (tuần tự)
Node* Tree_Iterative_Insert(Node* root, int value) {
    // Tạo nút tạm với dữ liệu được cho
    Node* tmp = new Node(value);

    // Nếu cây rỗng
    if (root == nullptr) return tmp;
    
    // Tìm và so sánh đến khi đén nút lá
    Node* parent = nullptr, *curr = root;
    while (curr != nullptr) {
        parent = curr;
        if (curr->data > value) curr = curr->left;
        else if (curr->data < value) curr = curr->right;
        else return root;
    }

    // Nếu nút mới nhỏ hơn nút gốc thì chèn bên trái, nếu lớn hơn thì chèn bên phải
    if (curr->data < value) curr->left = tmp;
    else if (curr->data < value) curr->right = tmp;

    // Trả về cây đã được chỉnh sửa
    return root;
}
```

**Thời gian**: $O(h)$
**Bộ nhớ**: $O(1)$

**Bài trước**: [[Cây BST]]
**Bài sau**: [[Xóa nút trong cây BST]]