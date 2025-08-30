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
	int idx = 0; // Khởi tạo chỉ số
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
		// Nếu đây là một nút lá, gọi removeFromLeaf
		// Nếu không thì gọi removeFromNonLeaf
		if (this->isLeaf)
			removeFromLeaf(idx);
		else
			removeFromNonLeaf(idx);
	}
	else {
		// Nếu đây là một nút lá thì khóa đó sẽ không nằm trong đây
		if (this->isLeaf) {
			cerr << "ERROR 001: Key is not found" << endl;
			return;
		}

		// Chìa khóa cần bị xóa có mặt trong cây con bắt đầu từ nút này.
		// Cờ hiệu chỉ ra liệu chìa khóa có mặt trong cây
		// con bắt đầu từ đứa con cuối cùng của nút này
		bool flag = (idx == this->n) ? true : false;

		// Nếu nút con nơi khóa dự kiến tồn tại có ít hơn t khóa,
		// chúng ta sẽ điền đầy cho nút con đó.
		if (this->children[idx]->n < this->t)
			this->fill(idx);

		// Nếu nút con cuối đã bị gộp, nó phải đã gộp với nút con trước đó,
		// vì vậy chúng ta sẽ đệ quy trên nút con thứ (idx-1). Nếu không, chúng ta sẽ đệ quy trên
		// nút con thứ (idx) hiện có ít nhất t khóa.
		if (flag && idx > this->n)
			this->children[idx - 1]->remove(key);
		else
			children[idx]->remove(key);
	}
	return;
}

// Một hàm để xóa khóa bên trong một nút lá
void BNode::removeFromLeaf(int idx) {
	// Di chuyển tất cả khóa sau vị trí idx-th 1 bước về đằng sau
	for (int i = idx + 1; i < this->n; ++i)
		this->keys[i - 1] = this->keys[i];

	// Cập nhật số lượng khóa trong nút
	this->n--;

	return;
}

// Một hàm để xóa khóa bên trong một nút không phải là nút lá
void BNode::removeFromNonLeaf(int idx) {
	int key = this->keys[idx];

	// Nếu đứa con đứng trước key (children[idx]) có ít nhất t khóa,
	// hãy tìm phần tử kế trước 'predecessor' của k trong cây con có gốc tại
	// children[idx]. Thay key bằng predecessor. Tiến hành xóa đệ quy pred
	// trong children[idx].
	if (this->children[idx]->n >= t) {
		int predecessor = this->getPredecessor(idx);
		this->keys[idx] = predecessor;
		this->children[idx]->remove(predecessor);
	}

	// Nếu đứa con children[idx] có ít hơn t khóa, kiểm tra children[idx + 1]
	// Nếu children[idx + 1] có ít nhất t khóa, tìm kiếm 'successor' của key
	// trong cây phụ có gốc ở children[idx + 1]
	// Thay thế key bằng 'successor' và đệ quy xóa successor trong children[idx + 1]
	else if (this->children[idx + 1]->n >= t) {
		int successor = this->getSuccessor(idx);
		this->keys[idx] = successor;
		children[idx + 1]->remove(successor);
	}

	// Nếu cả hai children[idx] và children[idx + 1] đều bé hơn các khóa t, ghép key và tất cả children[idx + 1] vào
	// children[idx]. Bây giờ children[idx] chứa 2t - 1 khóa. Giải phóng bộ nhớ cho children[idx + 1] và đệ quy xóa key
	// trong children[idx]
	else {
		this->merge(idx);
		this->children[idx]->remove(key);
	}
	return;
}

// Một hàm để lấy nút tiền nhiệm của khóa
int BNode::getPredecessor(int idx) {
	// Tiếp tục di chuyển về nút bên phải cho đến khi chúng ta chạm tới nút lá
	BNode* current = this->children[idx];
	while (!current->isLeaf)
		current = current->children[current->n];

	// Trả về khóa cuối cùng của nút lá đó
	return current->keys[current->n - 1];
}

// Một hàm để lấy nút kế nhiệm của khóa
int BNode::getSuccessor(int idx) {
	// Tiếp tục di chuyển về bên trái bắt đầu từ children[index + 1] cho tới khi chúng ta chạm tới nút lá
	BNode* current = this->children[idx + 1];
	while (!current->isLeaf)
		current = current->children[0];

	// Trả về khóa đầu tiên của nút lá
	return current->keys[0];
}

// Một hàm để điền nút con được thể hiện ở vị trí
// idx - th trong mảng children[] nếu nút con đó có ít hơn t - 1 khóa
void BNode::fill(int idx) {
	// Nếu nút con trước đó (children[idx - 1]) có nhiều hơn t - 1 khóa, mượn một khóa từ nút con đó
	if (idx != 0 && this->children[idx - 1]->n >= this->t)
		this->borrowFromPrevious(idx);

	// Nếu nút con tiếp theo (children[idx + 1]) có nhiều hơn t - 1 khóa, mượn một khóa từ nút con đó
	else if (idx != this->n && this->children[idx + 1]->n >= this->t)
		this->borrowFromNext(idx);

	// Ghép children[idx] với anh chị em của nó
	// Nếu children[idx] là nút con cuối cùng, ghép nó với anh chị em trước của nó
	// Nếu không thì ghép nó với anh chị em tiếp theo của nó
	else {
		if (idx != n)
			this->merge(idx);
		else
			this->merge(idx - 1);
	}

	return;
}

// Một hàm để mượn khóa từ children[idx - 1]-th và đặt nó ở children[idx]th
void BNode::borrowFromPrevious(int idx) {
	BNode* child = this->children[idx];
	BNode* sibling = this->children[idx - 1];

	// Khóa cuối cùng từ children[idx - 1] đi trước nút cha mẹ và keys[idx - 1]
	// từ cha mẹ được chèm với chức trách là khóa đầu tiên trong children[idx]. Do đó
	// chúng mất một khóa và nút con được nhận khóa đó

	// Di chuyển toàn bộ khóa trong children[idx] một bước vè phía trước
	for (int i = child->n - 1; i >= 0; --i)
		child->keys[i + 1] = child->keys[i];

	// Nếu children[idx] không phải là một nút là, di chuyển toàn bộ các con trỏ con một bước về phía trước
	if (!child->isLeaf) {
		for (int i = child->n; i >= 0; --i)
			child->children[i + 1] = child->children[i];
	}

	// Chỉnh khóa đầu tiên trong child bằng với keys[idx - 1] từ nút hiện tại
	child->keys[0] = this->keys[idx - 1];

	// Di chuyển nút con cuối cùng của anh chị em bằng với nút con đầu tiên children[idx] 
	if (!child->isLeaf)
		child->children[0] = sibling->children[sibling->n];

	// Di chuyển khóa từ nút anh chị em cho tới nút cha mẹ
	// Điều này giảm thiểu số lượng khóa trong anh chị em
	this->keys[idx - 1] = sibling->keys[sibling->n - 1];

	child->n++;
	sibling->n++;

	return;
};

// Một hàm để mượn khóa từ children[idx + 1]-th và đặt nó ở children[idx]th
void BNode::borrowFromNext(int idx) {
	BNode* child = this->children[idx];
	BNode* sibling = this->children[idx + 1];

	// keys[idx] được chèn như khóa cuối cùng trong children[idx]
	child->keys[(child->n)] = keys[idx];

	// Nút con đầu tiên của anh chị em được chèn như là nút con cuối cùng của children[idx]
	if (!child->isLeaf)
		child->children[(child->n) + 1] = sibling->children[0];

	// Sao chép con trỏ con từ children[idx + 1] tới children[idx]
	if (!child->isLeaf) {
		for (int i = 0; i <= sibling->n; ++i)
			child->children[i + this->t] = sibling->children[i];
	}

	// Di chuyển tất cả các khóa sao idx trong nút current một bước 
}