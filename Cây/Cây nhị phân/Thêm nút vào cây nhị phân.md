#file [[Cây nhị phân]]

> Để làm được điều này, trước hết bạn phải biết BFS trong [[Duyệt qua Cây nhị phân]]

``` cpp
// Hàm thêm nút vào cây
Node* Tree_Insert(Node* root, int value) {
    // Nếu cây rỗng, nút mới sẽ là root của cây
    if (root == nullptr) {
        root = new Node(value);
        return root;
    }

    // Nếu không, chạy BFS cho đến khi tìm thấy vị trí phù hợp
    std::queue<Node*> q;
    q.push(root);

    // Lặp cho đến khi hàng đợi rỗng
    while (!q.empty()) {
        // Tạo một nút tạm đảy nút đầu của queue vào
        Node* curr = q.front();
        q.pop();

        // Kiểm tra nút bên trái, nếu không phải null thì push vào hàng đợi, nếu phải thì chèn nút
        if (curr->left != nullptr) {
            q.push(curr->left);
        }
        else {
            curr->left = new Node(value);
            return root;
        }

        // Làm điều tương tự đối với bên phải
        if (curr->right != nullptr) {
            q.push(curr->right);
        }
        else {
            curr->right = new Node(value);
            return root;
        }
    }
}
```

**Bài trước**: [[Duyệt qua Cây nhị phân]]
**Bài sau**: [[Xóa nút khỏi Cây nhị phân]]