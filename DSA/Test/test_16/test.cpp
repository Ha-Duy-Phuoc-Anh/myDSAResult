#include <iostream>
#include <queue>
#include <vector>

// Kiểu dữ liệu nút của cây nhị phân
struct Node {
  // Dữ liệu của nút
  int data;

  // Con trỏ đến hai nút tiếp theo
  Node *left;
  Node *right;

  // Chiều cao của cây
  int height;

  // Hàm khởi tạo nút
  Node(int value) : data(value), left(nullptr), right(nullptr), height(0) {};
};

// Các hàm hỗ trợ
Node *Tree_GetSuccessor(Node *root);  // Lấy Successor (nút kế nhiện duyệt trung tự)
int Tree_GetBalance(Node *root);    // Lấy hệ số cân bằng của cây
Node *Tree_Rotate_LL(Node *root);     // Hàm xoay cây (LL)
Node *Tree_Rotate_RR(Node *root);     // Hàm xoay cây (RR)

// Hàm duyệt trong DFS
void Tree_Preorder_Print(Node *root);
void Tree_Inorder_Print(Node *root);
void Tree_Postorder_Print(Node *root);

// Hàm Duyệt BFS
void Tree_RecursionBFS_Print(Node *root, int level, std::vector<std::vector<int>> &res);
void Tree_RecursionBFS_Print(Node *root);
void Tree_QueueBFS_Print(Node *root);

// Hàm thêm nút vào cây (đệ quy và tuần tự)
Node *BST_Insert(Node *root, int value);
Node *Tree_Insert(Node *root, int value);

// Hàm xóa nút khỏi cây (đệ quy, đệ quy tối ưu và tuần tự)
Node *BST_Delete(Node *root, int value);
Node *Tree_Delete(Node *root, int value);

// Hàm tìm kiếm nút trong cây (đệ quy và tuần tự)
bool Tree_Recursive_Search(Node *root, int key);
bool Tree_Iterative_Search(Node *root, int key);

// Hàm giải phóng bộ nhớ của Cây
void Tree_Free(Node *root);

int main() {
  // Khởi tạo Cây nhị phân
  Node *root = new Node(50);
  root = Tree_Insert(root, 30);
  root = Tree_Insert(root, 70);
  root = Tree_Insert(root, 20);
  root = Tree_Insert(root, 40);
  root = Tree_Insert(root, 60);
  root = Tree_Insert(root, 80);

  std::cout << "Before delete: " << std::endl;
  Tree_QueueBFS_Print(root);

  root = Tree_Delete(root, 20);
  root = Tree_Delete(root, 30);
  root = Tree_Delete(root, 50);

  std::cout << "After delete: " << std::endl;
  Tree_QueueBFS_Print(root);

  std::cout << "IS 20 EXIST: " << (Tree_Iterative_Search(root, 20) ? "TRUE" : "FALSE") << std::endl;
  std::cout << "IS 80 EXIST: " << (Tree_Iterative_Search(root, 80) ? "TRUE" : "FALSE") << std::endl;

  // Giải phóng bộ nhớ
  Tree_Free(root);

  return 0;
}

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

void Tree_Preorder_Print(Node *root) {
  // Nếu đã hết nhánh thì thoát hàm trong đệ quy
  if (root == nullptr)
    return;

  // In dữ liệu ra của sổ dòng lệnh
  std::cout << root->data << " ";

  // Đệ quy nút trái và nút phải
  Tree_Preorder_Print(root->left);
  Tree_Preorder_Print(root->right);
}

void Tree_Inorder_Print(Node *root) {
  // Nếu đã hết nhánh thì thoát đệ quy
  if (root == nullptr)
    return;

  // Đệ quy nút trái trước
  Tree_Inorder_Print(root->left);

  // In dữ liệu ra cửa sổ dòng lệnh
  std::cout << root->data << " ";

  // Đệ quy nút phải sau
  Tree_Inorder_Print(root->right);
}

void Tree_Postorder_Print(Node *root) {
  // Nếu đã hết nhánh thì thoát đệ quy
  if (root == nullptr)
    return;

  // Đệ quy nút trái và nút phải đầu tiên
  Tree_Postorder_Print(root->left);
  Tree_Postorder_Print(root->right);

  // In ra cửa sổ dòng lệnh dữ liệu
  std::cout << root->data << " ";
}

void Tree_RecursionBFS_Print(Node *root, int level,
                             std::vector<std::vector<int>> &res) {
  // Nếu nút đã đến hết nhánh, thoát đệ quy
  if (root == nullptr)
    return;

  // Thêm một cấp vào kết quả nếu cần
  if (res.size() <= (long long unsigned int)level)
    res.push_back({});

  // Thêm dữ liệu của nút vào cấp phù hợp
  res[level].push_back(root->data);

  // Đệ quy cho nút trái và nút phải
  Tree_RecursionBFS_Print(root->left, level + 1, res);
  Tree_RecursionBFS_Print(root->right, level + 1, res);
}
void Tree_RecursionBFS_Print(Node *root) {
  // Khởi tạo vùng lưu trữ kết quả
  std::vector<std::vector<int>> result;

  // Đệ quy overloading
  Tree_RecursionBFS_Print(root, 0, result);

  // In kết quả ra console
  for (const auto &level_bucket : result) {
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

void Tree_QueueBFS_Print(Node *root) {
  // Nếu root là NULL thì in một mảng rỗng và thoát
  if (root == nullptr) {
    std::cout << "[]" << std::endl;
    return;
  }

  // Tạo một hàng đợi và một mảng để lưu trữ dữ liệu
  std::queue<Node *> q;
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
      Node *node = q.front();
      q.pop();

      // Đẩy dữ liệu vào mảng lưu trữ
      res[currentLevel].push_back(node->data);

      // Đảy dữ liệu của nút trái và nút phải vào queue
      if (node->left != nullptr)
        q.push(node->left);
      if (node->right != nullptr)
        q.push(node->right);
    }

    // Nâng cấp lên một cấp
    currentLevel++;
  }

  // In dữ liệu ra của sổ dòng lệnh
  for (const auto &level_bucket : res) {
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
  root->height = 1 + std::max((root->left) ? root->left->height : -1,
                              (root->right) ? root->right->height : -1);

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

bool Tree_Recursive_Search(Node *root, int key) {
  // Nếu root là nullptr thì ko có dữ liệu đó trong cây
  if (root == nullptr)
    return false;

  // Đệ quy bên trái bên phải
  if (key > root->data) return Tree_Recursive_Search(root->right, key);
  else if (key < root->data) return Tree_Recursive_Search(root->left, key);
  else return true;
}

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

void Tree_Free(Node *root) {
  // Nếu root là NULL thì thoát nhánh
  if (root == nullptr)
    return;

  // Chuyển đến nhánh trái và nhánh phải
  Tree_Free(root->left);
  Tree_Free(root->right);

  // Xóa nút và giải phóng bộ nhớ
  delete root;
}