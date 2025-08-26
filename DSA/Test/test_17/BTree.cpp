#include "BTree.h"

// Constructor khởi tạo nút của một cây
BNode::BNode(bool _isLeaf, int _t) {
  // Sao chép Mức độ tối thiểu và dữ liệu lấ
  this->t = _t;
  this->isLeaf = _isLeaf;

  // Phân bổ bộ nhớ cho số lượng khóa và số lượng nút con tối thiểu
  this->keys = new int[2 * t - 1];
  this->children = new BNode *[2 * t];

  // Khởi tạo số lượng khóa trong một nút
  this->n = 0;
}

// Hàm in cây ra terminal
void BNode::display() const {
  // Có n khóa và n + 1 nút con. Duyệt qua n khóa và nút con n đâu tiên
  int i;
  for (i = 0; i < this->n; i++) {
    // Nếu đây không phải nút lá, thì trước khi in ra khóa[i]
    // Duyệt cây con có nút gốc là nút root với nút con[i]
    if (!this->isLeaf)
      this->children[i]->display();
    cout << " " << this->keys[i];
  }

  // In ra cửa sổ dòng lệnh có nút gốc là nút con[i]
  if (!this->isLeaf)
    this->children[i]->display();
}
