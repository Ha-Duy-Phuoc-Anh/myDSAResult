#include "BTree.h"

// Constructor khởi tạo nút của một cây
BNode::BNode(bool _isLeaf, int _t) {
    // Sao chép mức độ tối thiểu và thuộc tính lá
    this->t = _t;
    this->isLeaf = _isLeaf;

    // Phân bổ bộ nhớ cho mảng khóa và mảng nút con
    // Số lượng khóa tối đa là 2t-1, số lượng con tối đa là 2t
    this->keys = new int[2 * t - 1];
    this->children = new BNode*[2 * t];

    // Khởi tạo số lượng khóa trong nút là 0
    this->n = 0;
}

// Hàm hiển thị cây B-Tree theo thứ tự duyệt trước
void BNode::display() const {
    // Duyệt qua n khóa và các nút con liên quan
    int i;
    for (i = 0; i < this->n; i++) {
        // Nếu không phải nút lá, duyệt cây con trước khi in khóa
        if (!this->isLeaf)
            this->children[i]->display();
        cout << " " << this->keys[i];
    }

    // Duyệt nút con cuối cùng nếu không phải nút lá
    if (!this->isLeaf)
        this->children[i]->display();
}

// Hàm tìm kiếm khóa trong cây con bắt đầu từ nút hiện tại
BNode* BNode::search(int target) const {
    // Tìm vị trí khóa đầu tiên lớn hơn hoặc bằng giá trị cần tìm
    int i = 0;
    while (i < this->n && target > this->keys[i])
        i++;

    // Nếu tìm thấy khóa bằng với giá trị cần tìm, trả về nút hiện tại
    if (this->keys[i] == target)
        return const_cast<BNode*>(this);

    // Nếu không tìm thấy và đây là nút lá, trả về nullptr
    if (this->isLeaf == true)
        return nullptr;

    // Tiếp tục tìm kiếm ở nút con thích hợp
    return this->children[i]->search(target);
}

// Hàm chèn một khóa mới vào B-Tree
void BTree::insert(int k) {
    // Nếu cây rỗng
    if (this->root == nullptr) {
        // Cấp phát bộ nhớ cho nút gốc mới
        this->root = new BNode(true, this->t);
        this->root->keys[0] = k;     // Chèn khóa
        this->root->n = 1;           // Cập nhật số lượng khóa trong gốc
    }
    else {  // Nếu cây không rỗng
        // Nếu nút gốc đã đầy, cây sẽ tăng chiều cao
        if (this->root->n == 2 * this->t - 1) {
            // Tạo một nút gốc mới
            BNode* s = new BNode(false, this->t);

            // Chuyển nút gốc cũ thành con của nút gốc mới
            s->children[0] = this->root;

            // Tách nút gốc cũ và đẩy một khóa lên nút gốc mới
            s->splitChild(0, this->root);

            // Nút gốc mới có hai con, quyết định con nào sẽ chứa khóa mới
            int i = 0;
            if (s->keys[0] < k)
                i++;
            s->children[i]->insertNoneFull(k);

            // Thay đổi nút gốc
            root = s;
        }
        else // Nếu nút gốc chưa đầy, gọi hàm chèn vào nút không đầy
            root->insertNoneFull(k);
    }
}
