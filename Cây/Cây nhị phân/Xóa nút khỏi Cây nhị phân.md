#file [[Cây nhị phân]]

``` cpp
// Hàm xóa nút khỏi cây
void Tree_Delete(Node* root, Node* DNode) {
    std::queue<Node*> q;
    q.push(root);

    Node* curr;
    while (!q.empty()) {
        curr = q.front();
        q.pop();

        // Nếu curr là nút sâu nhất thì xóa nó
        if (curr == DNode) {
            curr = nullptr;
            delete DNode;
            return;
        }

        // Kiểm tra nút phải trước  
        if (curr->right != nullptr) {
            // Nếu nút phải là nút sâu nhất thì xoa nó
            if (curr->right == DNode) {
                curr->right = nullptr;
                delete DNode;
                return;
            }
            // Nếu không phải thì đẩy nút vào hàng đợi
            q.push(curr->right);
        }

        // Làm điều tương tự ở bên trái
        if (curr->left != nullptr) {
            if (curr->left == DNode) {
                curr->left = nullptr;
                delete DNode;
                return;
            }
            q.push(curr->left);
        }
    }
}
Node* Tree_Delete(Node* root, int value) {
    // Nếu như cây rỗng, trả về Null
    if (root == nullptr) return nullptr;

    // Nếu cây chỉ có một nút duy nhát
    if (root->left == nullptr && root->right == nullptr) {
        // Nếu nút đó chính là key
        if (root->data == value) {
            delete root;
            return nullptr;
        }
        else return root;   // Nếu không thì trả về root
    }

    // Nếu không thì duyệt BFS
    std::queue<Node*> q;
    q.push(root);

    Node* curr;
    Node* keyNode = nullptr;

    while (!q.empty()) {
        curr = q.front();
        q.pop();

        // Nếu nút được lấy là key
        if (curr->data == value) {
            keyNode = curr;
            break;
        }  
        
        // Nếu không thì push nút trái và nút phải
        if (curr->left != nullptr) q.push(curr->left);
        if (curr->right != nullptr) q.push(curr->right);
    }

    // Nếu như tìm thấy, chỉnh sửa dữ liệu của nó ở nút cấp thấp nhất
    if (keyNode != nullptr) {
        // Lấy dữ liệu của nút sâu nhất
        int x = curr->data;

        // Thay thế dữ liệu của nó với nút sâu nhất
        keyNode->data = x;

        // Xóa nút sâu nhất đi
        Tree_Delete(root, curr);
    }

    // Trả về dữ liệu đã được xóa
    return root;
}
```