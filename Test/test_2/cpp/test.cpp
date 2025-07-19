#include <iostream>
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
        std::cout << curr->data << " ";

        // Di chuyển về nút đằng sau
        curr = curr->next;
    }
    std::cout << std::endl;
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

// Hàm thêm nút ở cuối danh sách liên kết đôi
Node* append(Node* head, int data) {
    // Tạo nút với dữ liệu được cho
    Node* newNode = new Node(data);

    // Kiểm tra nếu danh sách rỗng thì làm giống như thêm nút ở đầu danh sách liên kết đôi
    if (head == nullptr) {
        head = newNode;
    }
    else {
        // Nếu không thì tạo một nút tạm duyệt đến cuối danh sách
        Node* last = head;
        while (last->next != nullptr) last = last->next;

        // Thêm nút vào danh sách và nối con trỏ
        last->next = newNode;
        newNode->prev = last;
    }

    // Trả về danh sách đã được chỉnh sửa
    return head;
}

// Hàm thêm nút ở một vị trí cụ thể trong Danh sách liên kết
Node* add(Node* head, int data, int pos) {
    // Tạo một nút với dữ liệu được cho
    Node* newNode = new Node(data);

    // Thêm nút ở đầu danh sách liên kết
    if (pos == 1) {
        head = insert(head, data);
        return head;
    }

    // Tạo môt nút tạm để duyệt đến vị trí của người dùng
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != nullptr; i++) temp = temp->next;

    // Kiểm tra nếu vị trí mà người dùng đưa ra vượt kích thước của danh sách
    if (temp == nullptr) {
        std::cout << "ERROR 001: Index out of range" << std::endl;
        delete newNode; // Giải phóng bộ nhớ
        return head;
    }

    // Nếu không thì thêm nút và nối con trỏ vào danh sách
    newNode->prev = temp;
    newNode->next = temp->next;
    temp->next = newNode;

    // Nếu nút được thêm vào không phải là nút cuối cùng, thì nối con trỏ PREV mà nút trước đó
    if (newNode->next != nullptr) newNode->next->prev = newNode;

    // Trả về Danh sách liên kết đã được chỉnh sửa
    return head;
}

// Hàm xóa nút đầu của Danh sách liên kết
Node* removeFirst(Node* head) {
    // Nếu danh sách rỗng thì báo lỗi và trả về null
    if (head == nullptr) {
        std::cout << "ERROR 002: List is empty" << std::endl;
        return nullptr;
    }

    // Lưu trữ nút vào biến tạm để xóa sau
    Node* temp = head;

    // Chuyển con trỏ đến nút tiếp theo
    head = head->next;

    // Nếu HEAD không phải là NULL thì gán con trỏ PREV của head vào null
    if (head != nullptr) head->prev = nullptr;

    // Xóa nút và trả về danh sách đã chỉnh sửa
    delete temp;
    return head;
}

// Hàm xóa nút cuối của danh sách liên kết
Node* removeLast(Node* head) {
    // Kiểm tra nếu danh sách rỗng
    if (head == nullptr) {
        std::cout << "ERROR 002: List is empty" << std::endl;
        return nullptr;
    }

    // Kiểm tra nếu chỉ có một nút trong danh sách
    if (head->next == nullptr) {
        delete head; // Xóa nút duy nhất
        return nullptr; // Danh sách trở thành rỗng
    }

    // Duyệt tới nút cuối cùng
    Node* last = head;
    while (last->next != nullptr) {
        last = last->next;
    }

    // Chuyển con trỏ của nút trước để bỏ nút sau để tránh lỗi không thể truy cập bộ nhớ
    last->prev->next = nullptr;

    // Xóa nút cuối cùng (đây là nút 'last')
    delete last;

    // Trả về head của danh sách đã được chỉnh sửa
    return head;
}

// Hàm xóa nút ở vị trí cụ thể trong Danh sách liên kết
Node* remove(Node* head, int pos) {
    // Kiểm tra nếu danh sách rỗng thì báo lỗi
    if (head == nullptr) {
        std::cout << "ERROR 002: List is empty" << std::endl;
        return nullptr;
    }

    // Tạo một nút tạm duyệt tới vị trí người dùng đưa ra
    Node* curr = head;
    for (int i = 1; curr != nullptr && i < pos; i++) curr = curr->next;

    // Nếu như vị trí người dùng đưa ra vượt quá kích thước danh sách
    if (curr == nullptr) {
        std::cout << "ERROR 001: Index out of range" << std::endl;
        return head;
    }

    // Cập nhật con trỏ nút để xóa nút an toàn
    if (curr->prev != nullptr) curr->prev->next = curr->next;
    if (curr->next != nullptr) curr->next->prev = curr->prev;

    // Nếu như nút bị xóa chính là HEAD
    if (head == curr) head = curr->next;

    // Xóa nút và trả về danh sách đã được chỉnh sửa
    delete curr;    
    return head;
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

    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 5);

    head = append(head, 2);
    head = append(head, 3);
    head = append(head, 4);
    head = append(head, 5);

    head = add(head, 10, 2);
    head = add(head, 10, 10);

    std::cout << "Before delete: ";
    tranversal(head);
    
    head = removeFirst(head);
    head = removeFirst(head);
    head = removeLast(head);
    head = removeLast(head);
    head = remove(head, 2);
    head = remove(head, 5);

    std::cout << "After delete: ";
    tranversal(head);
    
    std::cout << "The list length: " << getLength(head) << std::endl;

    // Giải phóng bộ nhớ
    deleteList(head);

    return 0;
}