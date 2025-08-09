#include <iostream>
#include <vector>

// Kiểu dữ liệu nút của cây nhị phân
struct Node {
    // Dữ liệu của nút
    int data;

    // Con trỏ đến hai nút tiếp theo
    Node* left;
    Node* right;

    // Hàm khởi tạo nút
    Node(int value) : data(value), left(nullptr), right(nullptr) {};
};

// Hàm duyệt Preorder trong DFS
void Tree_Preorder_Print(Node* root) {
    // Nếu đã hết nhánh thì thoát hàm trong đệ quy
    if (root == nullptr) return;

    // In dữ liệu ra của sổ dòng lệnh
    std::cout << root->data << " ";

    // Đệ quy nút trái và nút phải
    Tree_Preorder_Print(root->left);
    Tree_Preorder_Print(root->right);
}

// Hàm duyệt Inorder trong DFS
void Tree_Inorder_Print(Node* root) {
    // Nếu đã hết nhánh thì thoát đệ quy
    if (root == nullptr) return;

    // Đệ quy nút trái trước
    Tree_Inorder_Print(root->left);

    // In dữ liệu ra cửa sổ dòng lệnh
    std::cout << root->data << " ";

    // Đệ quy nút phải sau
    Tree_Inorder_Print(root->right);
}

// Hàm duyệt Postorder trong DFS
void Tree_Postorder_Print(Node* root) {
    // Nếu đã hết nhánh thì thoát đệ quy
    if (root == nullptr) return;

    // Đệ quy nút trái và nút phải đầu tiên
    Tree_Postorder_Print(root->left);
    Tree_Postorder_Print(root->right);

    // In ra cửa sổ dòng lệnh dữ liệu
    std::cout << root->data << " ";
}

// Hàm in theo kiểu Đệ quy trong BFS
void Tree_RecursionBFS_Print(Node* root, int level, std::vector<std::vector<int>>& res) {
    // Nếu nút đã đến hết nhánh, thoát đệ quy
    if (root == nullptr) return;

    // Thêm một cấp vào kết quả nếu cần
    if (res.size() <= level) {

    }

}
std::vector<std::vector<int>> Tree_RecursionBFS_Print(Node* root) {
    std::vector<std::vector<int>> result;
    Tree_RecursionBFS_Print(root, 0, result);
    return result;
}

// Hàm giải phóng bộ nhớ của Cây
void Tree_Free(Node* root) {
    // Nếu root là NULL thì thoát nhánh
    if (root == nullptr) return;

    // Chuyển đến nhánh trái và nhánh phải
    Tree_Free(root->left);
    Tree_Free(root->right);

    // Xóa nút và giải phóng bộ nhớ
    delete root;
}

int main() {
    // Khởi tạo Cây nhị phân
    Node* root = new Node(1);

    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right = new Node(3);
    root->right->right = new Node(6);

    Tree_Postorder_Print(root);

    // Giải phóng bộ nhớ
    Tree_Free(root);

    return 0;
}