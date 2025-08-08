#file [[Cây nhị phân]]

## **Depth First Search (DFS)**
---
**Thuật toán Depth First Search (DFS)**: Khám phá càng xa càng tốt trong một nhánh cây trước khi quay lại _(Backtracking)_. Nó sử dụng đệ quy để thực hiện thao tác này. Các phương pháp duyệt chính trong DFS cho [[Cây nhị phân]] là:
- **Preoder Traversal (current - left - right) { Tạm dịch: Duyệt tiền tự (hiện tại - trái - phải) }**: Tới **nút** đầu trước, nút con bên trái, rồi đến nút con bên phải.
- **Inorder Traversal (left - current - right) { Tạm dịch: Duyệt trung tự (trái - hiện tại - phải) }**: Tới nút con bên trái trước, sau đó mới đến nút đầu rồi đến nút phải
- **Postorder Traversal (left - right - current) { Tạm dịch: Duyệt hậu tự (trái - phải - hiện tại) }:** Tới nút con bên trái trước, rồi đến bên phải và cuối cùng là nút đầu.

### Thực hiện thuật toán **Preorder Traversal** trong **DFS**
---
``` c
// Hàm duyệt Cây nhị phân Preorder DFS
void Tree_Preorder_Print(Node* root) {
    // Nếu hết nhánh thì thoát hàm trong đệ quy
    if (root == NULL) return;

    // In vào cửa sổ dòng lệnh
    printf("%i ", root->data);

    // Đệ quy hai nhánh trái và phải
    Tree_Preorder_Print(root->left);
    Tree_Preorder_Print(root->right);
}
```

> **Time complexity**: $O(n)$
> **Space complexity**: $O(h)$

### Thực hiện thuật toán **Inorder Traversal** trong **DFS**
---
``` c
// Hàm duyệt cây theo Inorder DFS
void Tree_Inorder_Print(Node* root) {
    // Nếu đã hết nhánh thì thoát đệ quy
    if (root == NULL) return;

    // Chuyển đến nhánh trái
    Tree_Inorder_Print(root->left);

    // In ra cửa sổ dòng lệnh
    printf("%i ", root->data);

    // Chuyển đến nhánh phải
    Tree_Inorder_Print(root->right);
}
```

> **Time complexity**: $O(n)$
> **Space complexity**: $O(h)$

### Thực hiện thuật toán **Postorder Traversal** trong **DFS**
---
``` c
// Hàm duyệt cây theo Postorder DFS
void Tree_Postorder_Print(Node* root) {
    // Nếu đã hết nhánh thì thoát đệ quy
    if (root == NULL) return;

    // Chuyển đến nhánh trái
    Tree_Postorder_Print(root->left);

    // Chuyển đến nhánh phải
    Tree_Postorder_Print(root->right);

    // In ra cửa sổ dòng lệnh
    printf("%i ", root->data);
}
```

> **Time complexity**: $O(n)$
> **Space complexity**: $O(h)$

## **Breadth First Search (BFS)**
---
Còn được gọi là **Level Order Traversal**, loại thuật toán này không di chuyển từng nút như trước, thay vào đó là lấy tất cả phần tử trong Phân cấp đó, sau đó chuyển đến phân cấp cao hơn.
Các các giải **BFS**:
- **Đệ quy**
- **Hàng đợi** (tuần tự)

> **Lưu ý**: Cả **Đệ quy** và **Hàng đợi** đều tốn **$O(n)$ thời gian** và **$O(h)$ không gian** cho nên là chọn cái nào cũng được.
### Tiếp cận đệ quy
---
``` c

```