#include <iostream>

#define ENTER '\n'

// Khởi tạo kiểu dữ liệu và các method cho Danh sách liên kết
class LinkedList {
private:
  // Kiểu dữ liệu cho nút
  struct Node {
    // Dữ liệu của nút
    int key;

    // Con trỏ đến nút tiếp theo
    Node *next;

    // Khởi tạo một đối tượng nút
    Node(int data) : key(data), next(nullptr) {};
  };

  // Nút last của Danh sách liên kết
  Node *last = nullptr;

  // Hàm thêm nút vào Danh sách liên kết rỗng
  void push_when_empty(int data) {
    last = new Node(data);
    last->next = last;
  }

public:
  // Hàm hiển thị Danh sách liên kết
  void display() const {
    // Nếu rỗng thì in chữ rỗng
    if (last == nullptr) {
      std::cout << "EMPTY" << ENTER;
      return;
    }

    // Tạo một nút tạm và duyệt đến khi quay trở lại nút ban đầu
    Node *current = last->next;
    do {
      std::cout << current->key << " -> ";
      current = current->next;
    } while (current != last->next);

    // In ra END ở cuối danh sách
    std::cout << "END" << ENTER;
  }

  // Hàm thêm nút vào đầu Danh sách liên kết
  void push_front(int data) {
    // Nếu danh sách rỗng thì chèn theo kiểu khác (nằm trong private)
    if (last == nullptr) {
      this->push_when_empty(data);
      return;
    }

    // Khởi tạo nút mới
    Node *newNode = new Node(data);

    // Điều chỉnh con trỏ để thêm nút vào danh sách
    newNode->next = last->next;
    last->next = newNode;
  }

  // Hàm thêm nút vào cuối Danh sách liên kết
  void push_back(int data) {
    // Kiểm tra nếu danh sách rỗng
    if (last == nullptr) {
      this->push_when_empty(data);
      return;
    }

    // Tạo nút mới với dữ liệu được cho
    Node *newNode = new Node(data);

    // Cập nhất con trỏ để thêm nút vào danh sách
    newNode->next = last->next;
    last->next = newNode;
    last = newNode;
  }

  // Hàm thêm nút vào vị trí cụ thể trong Danh sách liên kết
  void push_at(int data, int position) {
    if (position < 0) {
        std::cerr << "ERROR 001: Invalid Position" << ENTER;
        return;
    }
    if (last == nullptr) {
        if (position == 0) {
            // Fixed: Use push_when_empty for empty list when position==0
            this->push_when_empty(data); // [Sửa phần lặp: xử lý trường hợp danh sách rỗng]
        } else {
            std::cerr << "ERROR 001: Invalid Position" << ENTER;
        }
        return;
    }
    if (position == 0) {
        push_front(data);
        return;
    }
    Node* curr = last->next; // Bắt đầu từ head
    // Duyệt (position-1) bước để tìm nút trước vị trí cần chèn
    for (int i = 0; i < position - 1; i++) {
        curr = curr->next;
        if (curr == last->next) { // Đã lặp một vòng đầy đủ, vị trí không hợp lệ
            std::cerr << "ERROR 001: Invalid Position" << ENTER; // [Sửa phần lặp: kiểm tra vị trí vượt quá kích thước danh sách]
            return;
        }
    }
    Node* newNode = new Node(data);
    newNode->next = curr->next;
    curr->next = newNode;
    if (curr == last) { // Nếu chèn vào sau nút cuối, cập nhật last
        last = newNode;
    }
    // [Đã sửa phần lặp trong push_at]
  }

  // Hàm xóa nút ở đầu Danh sách liên kết
  int pop_front() {
    // Kiểm tra nếu Danh sách rỗng
    if (!last) {
      std::cout << "ERROR 002: List is empty" << std::endl;
      return -1;
    }

    // Kiểm tra nếu nút tiếp theo là null thì xóa nhanh gọn
    if (last->next == last) {
      delete last;
      last = nullptr;
    }

    // Nếu không thì tách last ra chỗ khác và xóa nó (lưu dữ liệu của nút chuẩn
    // bị xóa để trả về nữa)
    Node *willBeDelete = last->next;
    int popedNodeData = willBeDelete->key;

    last->next = willBeDelete->next;
    delete willBeDelete;

    return popedNodeData;
  }

  // Hàm xóa nút ở cuối Danh sách liên kết
  int pop_back() {
    // Nếu danh sách rỗng
    if (!last) {
      std::cout << "ERROR 002: List is empty" << ENTER;
      return -1;
    }

    // Nếu danh sách chỉ có một nút
    if (last->next == last) {
      int val = last->key;
      delete last;
      last = nullptr;
      return val;
    }

    // Nếu ko thì duyệt đến nút cuối
    Node *head = last->next;
    Node *current = last;
    while (current->next != last)
      current = current->next;

    // Chỉnh con trỏ và tách nút chuẩn bị được xóa ra để tránh lỗi ko thể truy cập bộ nhớ
    // Hoặc SEGMENT FAULT (CORE DUMP)
    int popedValue = last->key;
    current->next = head;
    delete last;
    last = current;

    // Trả về dữ liệu của nút ra đã tách sau khi xong hàng loạt thao tác
    return popedValue;
  }
  

  // Hàm xóa nút ở vị trí cụ thể trong Danh sách liên kết
  int pop_at(int position) {
    // Nếu danh sách rỗng
    if (!last) {
      std::cout << "ERROR 002: List is empty" << std::endl;
      return -1;
    }

    // Nếu vị trí bé hơn 0 thì coi như bị lỗi vị trí
    if (position < 0) {
      std::cout << "ERROR 001: Invalid Position" << std::endl;
      return -1;
    }

    // Nếu như vị trí là 0 thì xóa nút đầu
    if (position == 0) {
      return this->pop_front();
    }

    // Nếu khác thì tạo một nút duyệt đến trước vị trí được xóa
    Node* current = last->next;
    int currentPosition = 0;
    do {
      currentPosition++;
      if (currentPosition == position)
        break;

      current = current->next;
    } while (current != last);

    // Kiểm tra nếu current là nullptr (hoặc nút được xóa là nullptr) thì báo
    // lỗi
    if (current == last || current->next == last) {
      std::cout << "ERROR 001: Invalid Position\n";
      return -1;
    }

    // Nếu ko thì tạo nút tạm tách nút được xóa với dữ liệu liệu của nút được
    // xóa ra Sau đó nối con trỏ curr vào nút tiếp theo của nút tiếp theo và xóa
    // nút tạm đó
    Node *tmp = current->next;
    int popedValue = tmp->key;

    current->next = tmp->next;
    delete tmp;

    return popedValue;
  }

  // Hàm lấy kích thước danh sách liên kết
  size_t size() const {
    size_t length = 0;
    Node *curr = last;
    do {
      length++;
      curr = curr->next;
    } while (curr != last);

    return length;
  }

  // Hàm giải phóng bộ nhớ Danh sách liên kết
  ~LinkedList() {
    // Tạo một nút tạm duyệt từng nút và xóa
    Node *curr = last;
    do {
      Node *tmp = curr;
      curr = curr->next;
      delete tmp;
    }
    while (curr != last);
  }
};

int main() {
  LinkedList newList;
  newList.push_front(1);

  newList.push_front(2);
  newList.push_front(3);
  newList.push_front(4);
  newList.push_front(5);

  newList.push_back(2);
  newList.push_back(3);
  newList.push_back(4);
  newList.push_back(5);

  newList.push_at(10, 1);
  newList.push_at(20, 9);

  std::cout << "Before delete: ";
  newList.display();

  newList.pop_front();
  newList.pop_front();
  newList.pop_back();
  newList.pop_back();
  newList.pop_at(2);
  newList.pop_at(3);

  std::cout << "After delete: ";
  newList.display();

  std::cout << newList.size() << ENTER;

  return 0;
}