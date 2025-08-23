#file [[Cây AVL]]

## Mô tả thuật toán
- Chèn như cây BST
- Cập nhật chiều cao của cây
- Thực hiện các thao tác xoay nếu cây không cân bằng

## Thực hiện thuật toán
``` cpp
int Tree_GetBalance(Node *root) {
  if (root == nullptr) {
    return 0;
  }
  return (root->left->height) - (root->right->height);
}

Node *Tree_Rotate_LL(Node* x) {
  Node *y = x->right;
  Node *T2 = y->left;

  // Bắt đầu thao tác xoay
  y->left = x;
  x->right = T2;

  // Cập nhật chiều cao
  x->height = 1 + std::max(x->left->height, x->right->height);
  y->height = 1 + std::max(y->left->height, y->right->height);

  // Trả về gốc mới
  return y;
}

Node *Tree_Rotate_RR(Node *y) {
  Node *x = y->left;
  Node *T2 = x->right;

  // Thực hiện thao tác xoay
  x->right = y;
  y->left = T2;

  // Cập nhật chiều cao
  y->height = 1 + std::max(y->left->height, y->right->height);
  x->height = 1 + std::max(x->left->height, x->right->height);

  // Trả về root mới
  return x;
}

Node *BST_Insert(Node *root, int value) {
  Node *tmp = new Node(value);
  if (root == nullptr)
    return tmp;

  Node *parent = nullptr;
  Node *curr = root;
  while (curr != nullptr) {
    parent = curr;
    if (value < curr->data)
      curr = curr->left;
    else if (value > curr->data)
      curr = curr->right;
    else {
      delete tmp; // Đã tồn tại, không chèn
      return root;
    }
  }

  if (value < parent->data)
    parent->left = tmp;
  else
    parent->right = tmp;

  return root;
}
Node *Tree_Insert(Node *root, int value) {
  // Chèn như BST ở bước đầu
  root = BST_Insert(root, value);

  // Cập nhật chiều cao của cây
  root->height = 1 + std::max(root->left->height, root->right->height);

  // Lấy hệ số cân bằng của nút tổ tiên
  int balanceIndex = Tree_GetBalance(root);

  // Nếu cây không được cân bằng thì sẽ có 4 trường hợp sau
  // Trường hợp LL:
  if (balanceIndex > 1 && value < root->left->data)
    return Tree_Rotate_LL(root);
    
  // Trường hợp RR:
  if (balanceIndex < -1 && value > root->right->data)
    return Tree_Rotate_RR(root);
  
  // Trường hợp LR:
  if (balanceIndex < -1 && value > root->left->data) {
    root = Tree_Rotate_LL(root->left);
    return Tree_Rotate_RR(root);
  }

  // Trường hợp RL:
  if (balanceIndex > 1 && value < root->right->data) {
    root = Tree_Rotate_LL(root->right);
    return Tree_Rotate_RR(root);
  }

  // Trả về cây chưa được xoay nếu ko có trường hợp nào cần xoay
  return root;
}
```

**Bài trước**: [[Các thao tác xoay của cây AVL]]
**Bài sau**: [[Xóa nút trong cây AVL]]