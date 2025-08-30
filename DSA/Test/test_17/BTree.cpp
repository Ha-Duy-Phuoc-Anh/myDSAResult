#include "BTree.hpp"
#include "stdc++.hpp"

using namespace std;

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
	if (i < this->n && this->keys[i] == target)
		return const_cast<BNode*>(this);

	// Nếu không tìm thấy và đây là nút lá, trả về nullptr
	if (this->isLeaf)
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
		this->root->keys[0] = k; // Chèn khóa
		this->root->n = 1;		 // Cập nhật số lượng khóa trong gốc
	}
	else { // Nếu cây không rỗng
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

// Một hàm chèn khóa mới vào cây con có gốc là nút này, giả định là nút chưa
// đầy khi hàm này được gọi
void BNode::insertNoneFull(int key) {
	// Khởi tạo chỉ số ở khóa cuối cùng bên phải
	int index = n - 1;

	// Nếu đây là một nút lá
	if (this->isLeaf) {
		/*
			Vòng lặp dưới đây thực hiện hai thao tác
			1. Tìm kiếm vị trí khóa sẽ được chèn
			2. Di chuyển toàn bộ khóa lớn hơn về phía trước
		*/
		while (index >= 0 && this->keys[index] > key) {
			this->keys[index + 1] = keys[index];
			index--;
		}

		// Thêm nút vào khóa ở vị trí đã biết
		this->keys[index + 1] = key;
		this->n = this->n + 1;
	}
	else { // Nếu đây không phải nút lá
		// Tìm nút con sẽ là nơi lưu trữ khóa
		while (index >= 0 && this->keys[index] > key)
			index--;

		// Nếu nút con đó đã đầy
		if (this->children[index + 1]->n == 2 * this->t - 1) {
			// Nếu nút con đã đầy, tách nó
			this->splitChild(index + 1, this->children[index + 1]);

			// Sau khi tách, khóa ở giữa của children[i] đi lên
			// trước và children[i] tách ra hai.
			// Tìm kiếm sao nút nào sẽ giữ khóa đó
			if (this->keys[index + 1] < key)
				index++;
		}
		this->children[index + 1]->insertNoneFull(key);
	}
}

// Một hàm tách nút y của nút này ra hai phần, i là chỉ số của y trong mảng
// nút con. Nút con y bắt buộc phải đầy trước khi gọi hàm này
void BNode::splitChild(int i, BNode* y) {
    BNode* z = new BNode(y->isLeaf, y->t);
    z->n = y->t - 1;

    // Sao chép khóa
    for (int j = 0; j < y->t - 1; j++)
        z->keys[j] = y->keys[j + y->t];

    // Sao chép con (nếu có)
    if (!y->isLeaf) {
        for (int j = 0; j < y->t; j++)
            z->children[j] = y->children[j + y->t];
    }

    // Giảm số khóa y
    y->n = y->t - 1;

    // Dịch con của node hiện tại để chèn z
    for (int j = this->n; j >= i + 1; j--)
        this->children[j + 1] = this->children[j];
    this->children[i + 1] = z;

    // Dịch khóa của node hiện tại để chèn median
    for (int j = this->n - 1; j >= i; j--)
        this->keys[j + 1] = this->keys[j];
    this->keys[i] = y->keys[y->t - 1];

    this->n++;
}

// Một hàm để tìm kiếm chỉ số của khóa đầu tiên lớn hơn hoặc bằng target
int BNode::findKey(int target) const {
	int idx = 0;	// Khởi tạo chỉ số
	// Lặp cho tới khi tìm thấy khóa lớn hơn
	while (idx < this->n && this->keys[idx] < target)
		idx++;

	// Trả về chỉ số của nó
	return idx;
}

// Một hàm bọc để xóa khóa trong cây phụ có gôc là nút này
void BNode::remove(int key) {
	// Tìm kiếm chỉ số của khóa
	int idx = this->findKey(key);
	
	// Khóa được xóa sẽ có trong nút này
	if (idx < n && keys[idx] == key) {

	}
}
