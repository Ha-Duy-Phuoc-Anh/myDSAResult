#include <print>
#include <vector>

// Khởi tạo kiểu dữ liệu của Danh sách liên kết đơn
struct Node {
	// Phần dữ liệu của Danh sách liên kết đơn
	int data;
	
	// Con trỏ đến nút tiếp theo
	Node* next;

	// Hàm khởi tạo Nút
	Node(int value) : data(value), next(nullptr) {};
};

// Hàm thêm nút vào Danh sách liên kết rỗng
Node* insertEmpty(Node* last, int data) {
    // Kiểm tra nếu danh sách không rỗng
    if (last != nullptr) return last;

    // Tạo một nút mới và trỏ đến chính nó
    Node* newNode = new Node(data);
    newNode->next = newNode;

    // Chuyển last đến nút mới
    last = newNode;
    return last;
}

// Hàm thêm nút vào đầu Danh sách liên kết
Node* insert(Node* last, int data) {
	// Kiểm tra nếu danh sách rỗng
	if (last == nullptr) {
		last = insertEmpty(last, data);
		return last;
	}

	// Tạo một nút mới với dữ liệu được cho
	Node* newNode = new Node(data);

	// Điều chỉnh con trỏ để thêm nút mới vào danh sách
	newNode->next = last->next;
	last->next = newNode;

	// Trả về danh sách đã được chỉnh sửa
	return last;
}

void deleteList(Node* last) {
    if (last == nullptr) return;

    Node* current = last->next;
    Node* temp;

    while (current != last) {
        temp = current;
        current = current->next;
        delete temp;
    } 
}

void print(Node* last) {
    if (last == nullptr) return;

    Node* current = last->next;
    do {
        std::print("{} ", current->data);
        current = current->next;
    } while (current != last->next);
    std::println("");
}



int main() {
    // Khởi tạo danh sách liên kết vòng tròn
    Node* last = nullptr;
    last = insertEmpty(last, 1);
    last = insert(last, 2);
    last = insert(last, 3);
    last = insert(last, 4);
    last = insert(last, 5);

    print(last);

    // Giải phóng bộ nhớ
    deleteList(last);

    return 0;
}