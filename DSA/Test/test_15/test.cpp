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

// Hàm thêm nút vào cây (đệ quy)
Node *Tree_Recursion_Insert(Node *root, int value)
{
    // Nếu cây rỗng, nút mới sẽ là root của cây (hoặc là cây phụ)
    if (root == nullptr)
    {
        root = new Node(value);
        return root;
    }

    // Nếu nút trùng với giá trị của một nút khác trong cây thì từ chối chèn
    if (value == root->data)
        return root;

    // Kiểm tra nếu lớn hơn nút gốc thì đệ quy bên phải
    if (value > root->data)
        root->right = Tree_Recursion_Insert(root->right, value);

    // Kiểm tra nếu bé hơn nút gốc thì đệ quy bên trái
    if (value < root->data)
        root->left = Tree_Recursion_Insert(root->left, value);

    // Trả về cây đã chỉnh sửa
    return root;
}

// Hàm thêm nút vào cây (tuần tự)
Node *Tree_Iterative_Insert(Node *root, int value)
{
    Node *tmp = new Node(value);
    if (root == nullptr)
        return tmp;

    Node *parent = nullptr;
    Node *curr = root;
    while (curr != nullptr)
    {
        parent = curr;
        if (value < curr->data)
            curr = curr->left;
        else if (value > curr->data)
            curr = curr->right;
        else
        {
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

// Hàm con dùng để lấy nút kế nhiệm duyệt trung tự
Node *Tree_GetSuccessor(Node *root)
{
    root = root->right;
    while (root != nullptr && root->left != nullptr)
        root = root->left;
    return root;
}

// Hàm xóa nút khỏi cây (tiếp cận đệ quy)
Node *Tree_Recursion_Delete(Node *root, int value)
{
    // Trường hợp 1
    if (root == nullptr)
        return root;

    // Trường hợp 2
    if (root->data > value)
        root->left = Tree_Recursion_Delete(root->left, value);
    else if (root->data < value)
        root->right = Tree_Recursion_Delete(root->right, value);
    else
    {
        // Xử lí Trường hợp 2
        if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // Xử lí phát sinh trường hợp 3
        Node *successor = Tree_GetSuccessor(root);
        root->data = successor->data;
        root->right = Tree_Recursion_Delete(root, successor->data);
    }

    // Trả về cây đã được chỉnh sửa
    return root;
}

// Hàm xóa nút khỏi cây (tiếp cận đệ quy tối ưu)
Node *Tree_OpRecursion_Delete(Node *root, int value)
{
    // Trường hợp 1
    if (root == nullptr)
        return root;

    // Trường hợp 2
    if (value < root->data)
    {
        root->left = Tree_OpRecursion_Delete(root->left, value);
        return root;
    }
    else if (value > root->data)
    {
        root->right = Tree_OpRecursion_Delete(root->right, value);
        return root;
    }

    if (root->left == nullptr)
    {
        Node *temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == nullptr)
    {
        Node *temp = root->left;
        delete root;
        return temp;
    }

    // Trường hợp 3
    Node *parent_succesor = root;
    Node *successor = root->right;
    if (root->left != nullptr)
    {
        parent_succesor = successor;
        successor = successor->left;
    }
    root->data = successor->data;
    if (parent_succesor->left == successor)
        parent_succesor->left = successor->right;
    else
        parent_succesor->right = successor->right;
    delete successor;

    // Trả về cây đã được chỉnh sửa
    return root;
}

// Hàm xóa nút khỏi cây (tiếp cận tuần tự)
Node *Tree_Iterative_Delete(Node *root, int value)
{
    Node *parent = nullptr;
    Node *curr = root;

    // Tìm nút cần xóa
    while (curr && curr->data != value)
    {
        parent = curr;
        if (value < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if (!curr)
        return root; // Không tìm thấy

    // Trường hợp nút có hai con
    if (curr->left && curr->right)
    {
        Node *succParent = curr;
        Node *succ = curr->right;
        while (succ->left)
        {
            succParent = succ;
            succ = succ->left;
        }
        curr->data = succ->data;

        // Xóa successor
        curr = succ;
        parent = succParent;
    }

    // Trường hợp một con hoặc nút lá
    Node* child = curr->left ? curr->left : curr->right;
    
    // Xóa root
    if (!parent) {
        delete curr;
        return child;
    }

    // Dịch chuyển các nút sang vị trí an toàn để tránh unaddressible access
    if (parent->left == curr) parent->left = child;
    else parent->right = child; 

    delete curr;
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
    root = Tree_Iterative_Insert(root, 30);
    root = Tree_Iterative_Insert(root, 70);
    root = Tree_Iterative_Insert(root, 20);
    root = Tree_Iterative_Insert(root, 40);
    root = Tree_Iterative_Insert(root, 60);
    root = Tree_Iterative_Insert(root, 80);

    std::cout << "Before delete: " << std::endl;
    Tree_QueueBFS_Print(root);

    root = Tree_Iterative_Delete(root, 20);
    root = Tree_Iterative_Delete(root, 30);
    root = Tree_Iterative_Delete(root, 50);

    std::cout << "After delete: " << std::endl;
    Tree_QueueBFS_Print(root);

    // Giải phóng bộ nhớ
    Tree_Free(root);

    return 0;
}