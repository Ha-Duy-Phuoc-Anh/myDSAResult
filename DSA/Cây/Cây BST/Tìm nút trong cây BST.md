#file [[Cây BST]]

## **Mô tả thuật toán**
- So sánh với nút gốc
- Nếu lớn hơn thì di chuyển sang bên phải
- Nếu bé hơn thì di chuyển sang bên trái
- Lặp tiếp cho đến khi tìm thấy nút hoặc đến nút lá

## **Thực hiện thuật toán**
### Tiếp cận đệ quy
``` cpp
// Hàm tìm kiếm nút trong cây (tiếp cận đệ quy)
bool Tree_Recursive_Search(Node *root, int key) {
  // Nếu root là nullptr thì ko có dữ liệu đó trong cây
  if (root == nullptr)
    return false;

  // Đệ quy bên trái bên phải
  if (key > root->data) return Tree_Recursive_Search(root->right, key);
  else if (key < root->data) return Tree_Recursive_Search(root->right, key);
  else return true;
}
```
**Thời gian**: $O(h)$
**Bộ nhớ**: $O(h)$

### Tiếp cận tuần tự
``` cpp
// Hàm tìm kiếm nút trong cây (Tiếp cận tuần tự)
bool Tree_Iterative_Search(Node *root, int key) {
  // Tạo một nút tạm duyệt cây
  Node *curr = root;

  // Lặp cho đến khi curr là nullptr hoặc thoát hàm
  while (curr != nullptr) {
    // Nếu dữ liệu của curr = key thì trả về True và thoát hàm
    if (curr->data == key)
      return true;

    // Nếu ko thì so sánh để di chuyển nút sang trái, sang phải
    if (key > curr->data)
      curr = curr->right;
    else
      curr = curr->left;
  }

  // Chạy được tới đây nghĩa là không tìm thấy
  return false;
}
```
**Thời gian**: $O(h)$
**Bộ nhớ**: $O(1)$

**Bài trước**: [[Xóa nút trong cây BST]]