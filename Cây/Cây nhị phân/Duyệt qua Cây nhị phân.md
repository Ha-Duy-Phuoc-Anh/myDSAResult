#file [[Cây nhị phân]]

## **Depth First Search (DFS)**
**Thuật toán Depth First Search (DFS)**: Khám phá càng xa càng tốt trong một nhánh cây trước khi quay lại _(Backtracking)_. Nó sử dụng đệ quy để thực hiện thao tác này. Các phương pháp duyệt chính trong DFS cho [[Cây nhị phân]] là:
- **Preoder Traversal (current - left - right) { Tạm dịch: Duyệt tiền tự (hiện tại - trái - phải) }**: Tới **nút** đầu trước, nút con bên trái, rồi đến nút con bên phải.
- **Inorder Traversal (left - current - right) { Tạm dịch: Duyệt trung tự (trái - hiện tại - phải) }**: Tới nút con bên trái trước, sau đó mới đến nút đầu rồi đến nút phải
- **Postorder Traversal (left - right - current) { Tạm dịch: Duyệt hậu tự (trái - phải - hiện tại) }:** Tới nút con bên trái trước, rồi đến bên phải và cuối cùng là nút đầu.

### Thực hiện thuật toán **Preorder Traversal** trong **DFS**
``` cpp
// Hàm duyệt Cây nhị phân Preorder DFS
void Tree_Preorder_Print(Node* root) {
    // Nếu hết nhánh thì thoát hàm trong đệ quy
    if (root == nullptr) return;

    // In vào cửa sổ dòng lệnh
    std::cout << root->data << " ";

    // Đệ quy hai nhánh trái và phải
    Tree_Preorder_Print(root->left);
    Tree_Preorder_Print(root->right);
}
```

> **Time complexity**: $O(n)$
> **Space complexity**: $O(h)$

### Thực hiện thuật toán **Inorder Traversal** trong **DFS**
``` cpp
// Hàm duyệt cây theo Inorder DFS
void Tree_Inorder_Print(Node* root) {
    // Nếu đã hết nhánh thì thoát đệ quy
    if (root == nullptr) return;

    // Chuyển đến nhánh trái
    Tree_Inorder_Print(root->left);

    // In ra cửa sổ dòng lệnh
    std::cout << root->data << " ";

    // Chuyển đến nhánh phải
    Tree_Inorder_Print(root->right);
}
```

> **Time complexity**: $O(n)$
> **Space complexity**: $O(h)$

### Thực hiện thuật toán **Postorder Traversal** trong **DFS**
``` cpp
// Hàm duyệt cây theo Postorder DFS
void Tree_Postorder_Print(Node* root) {
    // Nếu đã hết nhánh thì thoát đệ quy
    if (root == nullptr) return;

    // Chuyển đến nhánh trái
    Tree_Postorder_Print(root->left);

    // Chuyển đến nhánh phải
    Tree_Postorder_Print(root->right);

    // In ra cửa sổ dòng lệnh
    std::cout << root->data << " ";
}
```

> **Time complexity**: $O(n)$
> **Space complexity**: $O(h)$

## **Breadth First Search (BFS)**
Còn được gọi là **Level Order Traversal**, loại thuật toán này không di chuyển từng nút như trước, thay vào đó là lấy tất cả phần tử trong Phân cấp đó, sau đó chuyển đến phân cấp cao hơn.
Các các giải **BFS**:
- **Đệ quy**
- **Hàng đợi** (tuần tự)

> **Lưu ý**: Cả **Đệ quy** và **Hàng đợi** đều tốn **$O(n)$ thời gian** và **$O(h)$ không gian** cho nên là chọn cái nào cũng được.
### Tiếp cận đệ quy
``` cpp
void Tree_RecursionBFS_Print(Node* root, int level, std::vector<std::vector<int>>& res) {
    // Nếu nút đã đến hết nhánh, thoát đệ quy
    if (root == nullptr) return;

    // Thêm một cấp vào kết quả nếu cần
    if (res.size() <= (long long unsigned int)level) res.push_back({});
    
    // Thêm dữ liệu của nút vào cấp phù hợp
    res[level].push_back(root->data);

    // Đệ quy cho nút trái và nút phải
    Tree_RecursionBFS_Print(root->left, level + 1, res);
    Tree_RecursionBFS_Print(root->right, level + 1, res);
}
void Tree_RecursionBFS_Print(Node* root) {
    // Khởi tạo vùng lưu trữ kết quả
    std::vector<std::vector<int>> result;

    // Đệ quy overloading
    Tree_RecursionBFS_Print(root, 0, result);

    // In kết quả ra console
    for (const auto& level_bucket : result) {
        std::cout << "[";
        for (size_t i = 0; i < level_bucket.size(); i++) {
            std::cout << level_bucket[i];
            if (i != level_bucket.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }
}
```

### Tiếp cận hàng đợi
``` cpp
// Hàm in theo kiểu hàng đợi trong BFS
void Tree_QueueBFS_Print(Node* root) {
    // Nếu root là NULL thì in một mảng rỗng và thoát
    if (root == nullptr) {
        std::cout << "[]" << std::endl;
        return;
    }

    // Tạo một hàng đợi và một mảng để lưu trữ dữ liệu
    std::queue<Node*> q;
    std::vector<std::vector<int>> res;

    // Thêm root vào queue
    q.push(root);

    // Tạo biến lưu trữ cấp hiện tại
    int currentLevel = 0;

    // Lặp cho đến khi hàng đợi rỗng
    while (!q.empty()) {
        // Tạo biến lưu trữ kích thước của queue
        int len = q.size();

        // Đẩy một mảng rỗng vào mảng lưu trữ dữ liệu
        res.push_back({});

        // Duyệt qua các phần tử của Queue
        for (int i = 0; i < len; i++) {
            // Lưu front của queue và xóa phần tử front
            Node* node = q.front();
            q.pop();

            // Đẩy dữ liệu vào mảng lưu trữ
            res[currentLevel].push_back(node->data);

            // Đảy dữ liệu của nút trái và nút phải vào queue
            if (node->left != nullptr) q.push(node->left);
            if (node->right != nullptr) q.push(node->right);
        }

        // Nâng cấp lên một cấp
        currentLevel++;
    }

    // In dữ liệu ra của sổ dòng lệnh
    for (const auto& level_bucket : res) {
        std::cout << "[";
        for (size_t i = 0; i < level_bucket.size(); i++) {
            std::cout << level_bucket[i];
            if (i != level_bucket.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }
}
```

**Bài trước**: [[Các giá trị trong cây nhị phân]]
**Bài sau**: [[Thêm nút vào cây nhị phân]]