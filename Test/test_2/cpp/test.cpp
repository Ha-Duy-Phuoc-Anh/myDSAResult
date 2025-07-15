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
void tranversal(Node* tail) {
    // Tạo một biến tạm từ điểm cuổi cùng
    Node* curr = tail;

    // Lắp nếu curr không phải là NULL
    while (curr != nullptr) {
        // In dữ liệu
        std::print("{} ", curr->data);

        // Di chuyển về nút đằng sau
        curr = curr->prev;
    }
    std::println();
}

// Hàm tìm kích thước của danh sách liên kết đôi (từ dưới đi lên)
int getLength(Node* tail) {
    // Tạo một biến tạm từ điểm cuổi cùng
    Node* curr = tail;

    // Tạo một biến tạm lưu trữ kết quả
    int length = 0;

    // Lặp cho tới khi curr là NULL
    while (curr != nullptr) {
        length++;           // Cập nhật độ dài
        curr = curr->prev;  // Di chuyển đến nút trước đó
    }
    return length;  // Trả về độ dài của danh sách
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
    Node* first = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);

    first->next = second;
    second->next = third;
    third->prev = second;
    second->prev = first;

    tranversal(third);
    std::println("The list length: {}", getLength(third));

    //head = insert(head, 2);
    //head = insert(head, 3);
    //head = insert(head, 4);
    //head = insert(head, 5);
    //head = append(head, 2);
    //head = append(head, 3);
    //head = append(head, 4);
    //head = append(head, 5);
    //head = add(head, 2, 10);
    //head = add(head, 10, 20);

    //// Duyệt danh sách liên kết đơn
    //std::print("Before delete: ");
    //tranversalList(head);

    //head = removeFirst(head);
    //head = removeFirst(head);
    //head = removeLast(head);
    //head = removeLast(head);
    //head = remove(head, 2);
    //head = remove(head, 5);

    //std::print("After delete: ");
    //tranversalList(head);

    //head = reverse(head);
    //std::print("After reverse: ");
    //tranversalList(head);

    //head = modify(head);
    //std::print("After modified: ");
    //tranversalList(head);

    //// Test
    //std::println("{} ", (search(head, 12) ? "TRUE" : "FALSE"));
    //std::println("{} ", (search(head, 3) ? "TRUE" : "FALSE"));

    //std::println("{}", count(head));

    // Giải phóng bộ nhớ
    deleteList(first);

    return 0;
}