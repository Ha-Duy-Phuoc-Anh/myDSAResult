#file [[Cây BST]]

## **Mô tả thuật toán**
### Trường hợp 1: Xóa nút lá
- Tách nút khỏi cây và đặt con trỏ đến nút đó là `NULL`
- Xóa nút đó
### Trường hợp 2: Xóa nút con, chỉ có một cây con là chính nó trong nhánh đó
- Hoán đổi vị trí của nút lá bên phải với nút con
- Tách nút con ra và con trỏ đến nó thành `NULL`
- Xóa nút đó
### Trường hợp 3: Xóa nút có nhiều nút con
- Tìm kiếm **Nút kế nhiệm theo duyệt trung tự** trong cây **BST** của nút được xóa
- Hoán đổi vị trí của hai nút đó
- Tách nút con ra và con trỏ đến nó thành `NULL`
- Xóa nút đó

## **Thực hiện thuật toán**
### Tiếp cận đệ quy
``` cpp
// Hàm xóa nút khỏi cây (tiếp cận đệ quy)
Node* Tree_Recursion_Delete(Node* root, int value) {
    // Trường hợp 1
    if (root == nullptr) return root;

    // Trường hợp 2
    if (root->data == value) root->left = Tree_Recursion_Delete(root->left, value);
    else if (root->data == value) root->right = Tree_Recursion_Delete(root->right, value);
    else {
        // Xử lí Trường hợp 2
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Xử lí phát sinh trường hợp 3
        Node* successor = Tree_GetSuccessor(root);
        root->data = successor->data;
        root->right = Tree_Recursion_Delete(root, successor->data);
    }

    // Trả về cây đã được chỉnh sửa
    return root;
}
```

**Thời gian**: $O(h)$
**Bộ nhớ**: $O(h)$
### Tiếp cận đệ quy tối ưu
``` cpp
// Hàm xóa nút khỏi cây (tiếp cận đệ quy tối ưu)
Node* Tree_OpRecursion_Delete(Node* root, int value) {
    // Trường hợp 1
    if (root == nullptr) return root;

    // Trường hợp 2
    if (value < root->data) {
        root->left = Tree_OpRecursion_Delete(root->left, value);
        return root;
    }
    else if (value > root->data) {
        root->right = Tree_OpRecursion_Delete(root->right, value);
        return root;
    }
    
    if (root->left == nullptr) {
        Node* temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == nullptr) {
        Node* temp = root->left;
        delete root;
        return temp;
    }

    // Trường hợp 3
    Node* parent_succesor = root;
    Node* successor = root->right;
    if (root->left != nullptr) {
        parent_succesor = successor;
        successor = successor->left;
    }
    root->data = successor->data;
    if (parent_succesor->left == successor) parent_succesor->left = successor->right;
    else parent_succesor->right = successor->right;
    delete successor;

    // Trả về cây đã được chỉnh sửa
    return root;
}
```

**Thời gian**: $O(h)$
**Không gian**: $O(h)$
### Tiếp cận tuần tự
``` cpp
// Hàm xóa nút khỏi cây (tiếp cận tuần tự)
Node* Tree_Iterative_Delete(Node* root, int value) {
    Node* current = root;
    Node* previous = nullptr;
    while (current != nullptr) {
        previous = current;
        if (value < current->data) current = current->left;
        else current = current->right;
    }

    if (current == nullptr) return root;

    if (current->left == nullptr || current->right == nullptr) {
        Node* new_current;
        if (current->left == nullptr) new_current = current->right;
        else new_current = current->left;

        if (previous == nullptr) return new_current;

        if (current == previous->left) previous->left = new_current;
        else previous->right = new_current;
        
        delete current;
    }
    else {
        Node* p = nullptr;
        Node* temp = current->right;
        if (temp->left != nullptr) {
            p = temp;
            temp = temp->left;
        }

        if (p != nullptr) p->left = temp->right;
        else current->right = temp->right;

        delete temp;
    }
    return root;
}
```

**Thời gian**: $O(h)$
**Bộ nhớ**: $O(1)$

