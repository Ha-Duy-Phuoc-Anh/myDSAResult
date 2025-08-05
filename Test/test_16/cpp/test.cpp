// Thêm các thư viện cần thiết
#include <iostream>
    
// Khởi tạo kiểu dữ liệu
class Node
{
public:
    // Dữ liệu
    int data;

    // Nút con
    Node* left;
    Node* right;

    // Khai báo dữ liệu
    Node(int val) : data(val), left(nullptr), right(nullptr) {};
};

// Preoder Traversal trong Binary Tree
void preorderPrint(Node* root)
{
    // Nếu đã hết nhánh thì thoát đệ quy
    if (root == nullptr) return;
    
    // In ra cửa sổ dòng lệnh
    std::cout << root->data << " ";

    // Đệ quy nút con trái và nút con phải
    preorderPrint(root->left);
    preorderPrint(root->right);
}

// Inorder Traversal trong Binary Tree
void inorderPrint(Node* root)
{
    // Nếu đã hết nhánh thì thoát đệ quy
    if (root == nullptr) return;

    // Chuyển đến nhánh trái
    inorderPrint(root->left);

    // In ra cửa sổ dòng lệnh
    std::cout << root->data << " ";

    // Chuyển đến nhánh bên phải
    inorderPrint(root->right);
}

int main()
{
    Node* root = new Node(1);

    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right = new Node(3);
    root->right->right = new Node(6);

    inorderPrint(root);

    return 0;
}
