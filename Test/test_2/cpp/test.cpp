#include <print>
#include <vector>

// Khởi tạo kiểu dữ liệu của Danh sách liên kết đơn
struct Node {
    // Con trỏ đến nút trươc đó
    Node* prev;

	// Phần dữ liệu của Danh sách liên kết đơn
	int data;
	
	// Con trỏ đến nút tiếp theo
	Node* next;

	// Hàm khởi tạo Nút
	Node(int value) : prev(nullptr), data(value), next(nullptr) {};
};

// Hàm duyệt qua danh sách liên kết đôi (từ phía sau)
void tranversal(Node* head) {
    // Tạo một biến tạm từ điểm cuổi cùng
    Node* curr = head;

    // Lắp nếu curr không phải là NULL
    while (curr != nullptr) {
        // In dữ liệu
        std::print("{} ", curr->data);

        // Di chuyển về nút đằng sau
        curr = curr->next;
    }
    std::println();
}

// Hàm tìm kích thước của danh sách liên kết đôi (từ dưới đi lên)
int getLength(Node* head) {
    // Tạo một biến tạm từ điểm cuổi cùng
    Node* curr = head;

    // Tạo một biến tạm lưu trữ kết quả
    int length = 0;

    // Lặp cho tới khi curr là NULL
    while (curr != nullptr) {
        length++;           // Cập nhật độ dài
        curr = curr->next;  // Di chuyển đến nút trước đó
    }
    return length;  // Trả về độ dài của danh sách
}

// Hàm thêm nút ở đầu danh sách liên kết đôi
Node* insert(Node* head, int data) {
    // Tạo một nút mới
    Node* newNode = new Node(data);

    // Gán newNode trở thành HEAD mới của danh sách liên kết đơn
    newNode->next = head;

    // Nếu HEAD không phải là NULL thì gán con trỏ PREV của head vào newNode
    if (head != nullptr) head->prev = newNode;

    // Trả về danh sách liên kết đã được chỉnh sửa
    return newNode;
}

void deleteList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}


int main() {
    // Khởi tạo danh sách liên kết đơn
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    head = insert(head, 2);
    head = insert(head, 3);

    tranversal(head);
    std::println("The list length: {}", getLength(head));

    // Giải phóng bộ nhớ
    deleteList(head);

    return 0;
}