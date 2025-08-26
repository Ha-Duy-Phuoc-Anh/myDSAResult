#include <vector>

using namespace std;

class Node {
	// Số lượng khóa trong nút
	int n;

	// Mảng lưu trữ khóa trong nút
	vector<int> keys;

	// Mảng lưu trữ con trỏ đến các nút trong trong cây
	vector<Node*> children;

	// Boolean cho biết nút đó có phải nút lá ko
	bool isLeaf;

	// Hàm khởi tạo đối tượng Nút
	Node(bool _isLeaf = false, int _m = 0) : n(0), isLeaf(_isLeaf) {
		// Khởi tạo đủ bộ nhớ cho mảng lưu trữ khóa
		keys.resize(_m);

		// Khởi tạo đủ bộ nhớ cho mảng lưu trữ đến các nút trong cây
		if (!isLeaf)
			children.resize(_m + 1);
	}

	
};
class BTree {
private:
	Node* root = nullptr;

  // Hàm overload hỗ trợ tìm kiếm
  bool search(Node *overloadRoot, int key) const {
		int i = 0;
    while (i < overloadRoot->n && key > overloadRoot->keys[i]) {
      i++;
    }
    if (i < overloadRoot->n && key == overloadRoot->keys[i]) {
      return true;
    }
    if (overloadRoot->isLeaf) {
      return false;
    }
    return search(overloadRoot->children[i], key);
	}

public:
	// Hàm khởi tạo cây
	BTree() {
		root = nullptr;
	};

	// Hàm tìm kiếm nút trong cây
	bool search(int key) const {
		if (!root) return false;
		return search(root, key);
	}

	// Hàm duyệt cây
	void display() const {
		// Có n khóa và n + 1 nút con, duyệt qua những khóa n
		// và nút con đầu tiền
		int i;
		for (int i = 0; i < root->n; i++) {
			// Nếu đây không phải là nút lá, thì trước khi in ra khóa[i]
			// Duyệt cây con có gốc là C[i]
			if (!root->isLeaf) {
			}

		}
	}
};

