#file [[Cây AVL]]

## Mô tả thuật toán
- Làm giống như chèn nút, nhưng khác cái là xóa

## Thực hiện thuật toán
``` cpp
Node *Tree_GetSuccessor(Node *root) {
    root = root->right;
    while (root != nullptr && root->left != nullptr)
      root = root->left;
    return root;
}
int Tree_GetBalance(Node *root) {
  if (root == nullptr) {
    return 0;
  }
  return ((root->left) ? root->left->height : -1) - ((root->right) ? root->right->height : -1);
}

Node *Tree_Rotate_LL(Node* y) {
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

Node *Tree_Rotate_RR(Node *x) {
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
Node *BST_Delete(Node *root, int value) {
  Node *parent = nullptr;
  Node *curr = root;

  // Tìm nút cần xóa
  while (curr && curr->data != value) {
    parent = curr;
    if (value < curr->data)
      curr = curr->left;
    else
      curr = curr->right;
  }

  if (!curr)
    return root; // Không tìm thấy

  // Trường hợp nút có hai con
  if (curr->left && curr->right) {
    Node *succParent = curr;
    Node *succ = curr->right;
    while (succ->left) {
      succParent = succ;
      succ = succ->left;
    }
    curr->data = succ->data;

    // Xóa successor
    curr = succ;
    parent = succParent;
  }

  // Trường hợp một con hoặc nút lá
  Node *child = curr->left ? curr->left : curr->right;

  // Xóa root
  if (!parent) {
    delete curr;
    return child;
  }

  // Dịch chuyển các nút sang vị trí an toàn để tránh unaddressible access
  if (parent->left == curr)
    parent->left = child;
  else
    parent->right = child;

  delete curr;
  return root;
}
Node *Tree_Delete(Node *root, int value) {
  // Thực hiện thao tác xóa của BST
  root = BST_Delete(root, value);

  // Cập nhật chiều cao của cây AVL
  root->height = 1 + std::max((root->left) ? root->left->height : -1,
                              (root->right) ? root->right->height : -1);

  // Lấy hệ số cân bằng của cây AVL
  int balanceIndex = Tree_GetBalance(root);

  // Nếu cây không được cân bằng thì sẽ có 4 trường hợp sau
  // Trường hợp LL:
  if (balanceIndex > 1 && Tree_GetBalance(root->left) >= 0)
    return Tree_Rotate_LL(root);
    
  // Trường hợp RR:
  if (balanceIndex < -1 && Tree_GetBalance(root->right) <= 0)
    return Tree_Rotate_RR(root);
  
  // Trường hợp LR:
  if (balanceIndex > 1 && Tree_GetBalance(root->left) < 0) {
    root->left = Tree_Rotate_LL(root->left);
    return Tree_Rotate_RR(root);
  }

  // Trường hợp RL:
  if (balanceIndex < -1 && Tree_GetBalance(root->right) > 0) {
    root->right = Tree_Rotate_RR(root->right);
    return Tree_Rotate_LL(root);
  }

  // Trả về cây chưa được xoay nếu ko có trường hợp nào cần xoay
  return root;
}
```

**Bài trước**: [[Chèn nút trong cây AVL]]