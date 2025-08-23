#include <iostream>
#include <vector>
#include <queue>

// Kiểu dữ liệu nút của cây nhị phân
struct Node
{
    // Dữ liệu của nút
    int data;

    // Con trỏ đến hai nút tiếp theo
    Node *left;
    Node *right;

    // Hàm khởi tạo nút
    Node(int value) : data(value), left(nullptr), right(nullptr) {};
};

// Hàm duyệt Preorder trong DFS
void Tree_Preorder_Print(Node *root)
{
    // Nếu đã hết nhánh thì thoát hàm trong đệ quy
    if (root == nullptr)
        return;

    // In dữ liệu ra của sổ dòng lệnh
    std::cout << root->data << " ";

    // Đệ quy nút trái và nút phải
    Tree_Preorder_Print(root->left);
    Tree_Preorder_Print(root->right);
}

// Hàm duyệt Inorder trong DFS
void Tree_Inorder_Print(Node *root)
{
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

// Hàm duyệt Postorder trong DFS
void Tree_Postorder_Print(Node *root)
{
    // Nếu đã hết nhánh thì thoát đệ quy
    if (root == nullptr)
        return;

    // Đệ quy nút trái và nút phải đầu tiên
    Tree_Postorder_Print(root->left);
    Tree_Postorder_Print(root->right);

    // In ra cửa sổ dòng lệnh dữ liệu
    std::cout << root->data << " ";
}

// Hàm in theo kiểu Đệ quy trong BFS
void Tree_RecursionBFS_Print(Node *root, int level, std::vector<std::vector<int>> &res)
{
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
void Tree_RecursionBFS_Print(Node *root)
{
    // Khởi tạo vùng lưu trữ kết quả
    std::vector<std::vector<int>> result;

    // Đệ quy overloading
    Tree_RecursionBFS_Print(root, 0, result);

    // In kết quả ra console
    for (const auto &level_bucket : result)
    {
        std::cout << "[";
        for (size_t i = 0; i < level_bucket.size(); i++)
        {
            std::cout << level_bucket[i];
            if (i != level_bucket.size() - 1)
            {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }
}

// Hàm in theo kiểu hàng đợi trong BFS
void Tree_QueueBFS_Print(Node *root)
{
    // Nếu root là NULL thì in một mảng rỗng và thoát
    if (root == nullptr)
    {
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
    while (!q.empty())
    {
        // Tạo biến lưu trữ kích thước của queue
        int len = q.size();

        // Đẩy một mảng rỗng vào mảng lưu trữ dữ liệu
        res.push_back({});

        // Duyệt qua các phần tử của Queue
        for (int i = 0; i < len; i++)
        {
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
    for (const auto &level_bucket : res)
    {
        std::cout << "[";
        for (size_t i = 0; i < level_bucket.size(); i++)
        {
            std::cout << level_bucket[i];
            if (i != level_bucket.size() - 1)
            {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }
}

// Hàm thêm nút vào cây
Node *Tree_Insert(Node *root, int value)
{
    // Nếu cây rỗng, nút mới sẽ là root của cây
    if (root == nullptr)
    {
        root = new Node(value);
        return root;
    }

    // Nếu không, chạy BFS cho đến khi tìm thấy vị trí phù hợp
    std::queue<Node *> q;
    q.push(root);

    // Lặp cho đến khi hàng đợi rỗng
    while (!q.empty())
    {
        // Tạo một nút tạm đảy nút đầu của queue vào
        Node *curr = q.front();
        q.pop();

        // Kiểm tra nút bên trái, nếu không phải null thì push vào hàng đợi, nếu phải thì chèn nút
        if (curr->left != nullptr)
        {
            q.push(curr->left);
        }
        else
        {
            curr->left = new Node(value);
            return root;
        }

        // Làm điều tương tự đối với bên phải
        if (curr->right != nullptr)
        {
            q.push(curr->right);
        }
        else
        {
            curr->right = new Node(value);
            return root;
        }
    }
    return root;
}

// Hàm xóa nút khỏi cây
void Tree_Delete(Node* root, Node* d_node) {
    std::queue<Node*> q;
    q.push(root);

    Node* curr;
    while (!q.empty()) {
        curr = q.front();
        q.pop();

        if (curr->left) {
            if (curr->left == d_node) {
                curr->left = nullptr;
                delete d_node;
                return;
            } else {
                q.push(curr->left);
            }
        }
        if (curr->right) {
            if (curr->right == d_node) {
                curr->right = nullptr;
                delete d_node;
                return;
            } else {
                q.push(curr->right);
            }
        }
    }
}
Node* Tree_Delete(Node* root, int value) {
    if (!root)
        return nullptr;

    // Nếu cây chỉ có một nút
    if (!root->left && !root->right) {
        if (root->data == value) {
            delete root;
            return nullptr;
        } else
            return root;
    }

    std::queue<Node*> q;
    q.push(root);

    Node* keyNode = nullptr;
    Node* curr = nullptr;

    while (!q.empty()) {
        curr = q.front();
        q.pop();

        if (curr->data == value)
            keyNode = curr;

        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }

    // Nếu tìm thấy node cần xóa
    if (keyNode) {
        keyNode->data = curr->data; // curr là node cuối cùng trong BFS
        Tree_Delete(root, curr);
    }

    return root;
}

// Hàm giải phóng bộ nhớ của Cây
void Tree_Free(Node *root)
{
    // Nếu root là NULL thì thoát nhánh
    if (root == nullptr)
        return;

    // Chuyển đến nhánh trái và nhánh phải
    Tree_Free(root->left);
    Tree_Free(root->right);

    // Xóa nút và giải phóng bộ nhớ
    delete root;
}

int main()
{
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

    // Giải phóng bộ nhớ
    Tree_Free(root);

    return 0;
}