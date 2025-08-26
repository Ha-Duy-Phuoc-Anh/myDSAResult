#file [[Cây B]]

``` cpp
#include <vector>

using namespace std;

class BTree {
private:
	struct Node {
		// Số lượng khóa trong nút
		int n;

		// Mảng lưu trữ khóa trong nút
		vector<int> keys;

		// Mảng lưu trữ con trỏ đến các nút trong trong cây
		vector<Node*> children;

		// Boolean cho biết nút đó có phải nút lá ko
		bool _isLeaf;

		// Hàm khởi tạo đối tượng Nút
		Node(bool isLeaf = false, int m = 0) : n(0), _isLeaf(isLeaf) {
			// Khởi tạo đủ bộ nhớ cho mảng lưu trữ khóa
			keys.resize(m);

			// Khởi tạo đủ bộ nhớ cho mảng lưu trữ đến các nút trong cây
			if (!isLeaf)
				children.resize(m + 1);
		}
	};
	Node* root = nullptr;

  

public:
	// Hàm khởi tạo cây
	BTree(int m) {
		root = new Node(true, m);
	};
};
```

**Bài trước**: [[Những điểm đặc biệt của cây B]]
**Bài sau**: [[Chèn dữ liệu vào cây B]]