#include <print>

// Khởi tạo kiểu dữ liệu của Danh sách liên kết đơn
struct Node {
	// Phần dữ liệu của Danh sách liên kết đơn
	int data;
	
	// Con trỏ đến nút tiếp theo
	Node* next;

	// Hàm khởi tạo Nút
	Node(int value) : data(value), next(nullptr) {};
};

// Hàm duyệt danh sách liên kết đơn
void tranversalList(Node* head) {
    // Khởi tạo một nút tạm
    Node* temp = head;

    // Lặp nếu nút tiếp theo không phải là NULL
    while (temp != nullptr) {
        std::print("{} ", temp->data);    // In ra cửa sổ dòng lệnh
        temp = temp->next;                  // Trỏ đến nút tiếp theo
    }

    std::println();  // Xuống dòng sau khi in xong    
}

// Hàm tìm kiếm trong danh sách liên kết đơn
bool search(Node* head, int target) {
    // Khởi tạo một nút tạm
    Node* curr = head;
    
    // Lắp nếu con trỏ nút tạm khôn phải là NULL
    while (curr != nullptr) {
        // Trả về true để ngắt hàm nếu dữ liệu của nút tạm bằng với mục tiêu của người dùng
        if (curr->data == target) {
            return true;
        }

        // Chuyển đến nút tiếp theo
        curr = curr->next;
    } 

    // Trả về false nếu không có giá trị bằng với mục tiêu
    return false;
}

// Hàm đếm số lượng nút trong danh sách liên kết đơn
int count(Node* head) {
    // Khởi tạo một nút tạm
    Node* temp = head;

    // Tạo một biến tạm lưu trữ kích thước
    int length = 0;

    // Lặp nếu nút tiếp theo không phải là NULL
    while (temp != nullptr) {
        length++;                   // Tăng kích thước
        temp = temp->next;          // Trỏ đến nút tiếp theo
    }
    
    return length;      // Trả về kích thước cho chương trình
}

// Hàm thêm nút vào đầu danh sách liên kết
Node* insert(Node* head, int data) {
    // Tạo một nút mới dựa trên dữ liệu đã cho
    Node* newNode = new Node(data);

    // Trỏ con trỏ của nút mới đến HEAD
    newNode->next = head;

    // Trả về danh sách liên kết đã điều chỉnh, và cho newNode là HEAD mới của nh sách
    return newNode;
}

// Hàm thêm nút vào cuối danh sách liên kết
Node* append(Node* head, int data) {
    // Khởi tạo một nút với giá trị đã cho
    Node* newNode = new Node(data);
    
    // Kiểm tra nếu danh sách rỗng, nếu rỗng thì chèn thẳng nút vào HEAD và ngắt hàm
    if (head == nullptr) return newNode;

    // Tạo một nút tạm
    Node* last = head;

    // Lặp tới khi tới nút cuối cùng
    while (last->next != nullptr) last = last->next;

    // Chèn nút tại nút tạm last
    last->next = newNode;

    // Trả về danh sách liên kết đã chỉnh sửa
    return head;
}

// Hàm thêm nút vào một vị trí cụ thể trong danh sách liên kết
Node* add(Node* head, int pos, int data) {
    // Điều kiện này cho biết vị trí của người dùng có ít hơn 1 không, nếu có thì báo lỗi
    if (pos < 1) {
        std::println("ERROR 001: Position out of range");
        return head;
    }

    // Điều kiện này cho biết vị trí có phải một hay không, nếu phải thì thao tác giống với thêm nút vào đầu danh sách liên kết
    if (pos == 1) {
        Node* newNode = new Node(data);
        newNode->next = head;
        return newNode;
    }

    // Nếu như tất cả các điều kiện trên đều sai thì tạo một nút tạm duyệt tới vị trí mà người dùng đưa ra
    Node* curr = head;
    for (int i = 1; curr != nullptr && i < pos - 1; i++) curr = curr->next;

    // Kiểm tra nếu curr là NULL thì báo lỗi, vì NULL chỉ xuất hiện ở cuối cùng danh sách
    if (curr == nullptr) {
        std::println("ERROR 001: Position out of range");
        return head;
    }

    // Nếu bình thường thì tiếp tục
    Node* newNode = new Node(data);     // Tạo nút với dữ liệu được cho
    
    // Chèn nút mới vào vị trí curr
    newNode->next = curr->next;
    curr->next = newNode;

    // Trả về danh sách đã được chỉnh sửa
    return head;
}

// Hàm xóa nút đầu trong danh sách liên kết
Node* removeFirst(Node* head) {
    // Kiểm tra nếu danh sách rỗng
    if (head == nullptr) {
        std::println("ERROR 002: List is empty");
        return nullptr;
    }

    // Tạo một nút tạm để xóa nút
    Node* temp = head;

    // Chuyển head đến con trỏ tiếp theo
    head = head->next;

    // Xóa nút đầu trong danh sách
    delete temp;

    // Trả về head
    return head;
}

// Hàm xóa nút cuối trong danh sách liên kết
Node* removeLast(Node* head) {
    // Kiểm tra nếu danh sách rỗng
    if (head == nullptr) {
        std::println("ERROR 002: List is empty");
        return nullptr;
    }

    // Tạo một nút tạm thời và di chuyển nó đến nút sau nút cuối cùng
    Node* temp = head;
    while (temp->next->next != nullptr) temp = temp->next;

    // Xóa nút sau nút tạm
    delete temp->next;

    // Trỏ con trỏ sang NULL
    temp->next = nullptr;

    // Trả về danh sách đã sửa
    return head;
}

// Hàm xóa nút nhất định trong danh sách liên kết
Node* remove(Node* head, int pos) {
    // Điều kiện này cho biết vị trí có ít hơn 1 không, nếu có thì báo lỗi
    if (pos < 1) {
        std::println("ERROR 001: Position out of range");
        return head;
    }

    // Điều kiện này cho biết vị trí có phải một hay không, nếu phải thì thao tác giống với xóa nút vào đầu danh sách liên kết
    if (pos == 1) {
        head = removeFirst(head);
        return head;
    }

    
}

void deleteList(Node* &head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
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
    head = add(head, 2, 10);
    head = add(head, 10, 20);

    // Duyệt danh sách liên kết đơn
    std::print("Before delete: ");
    tranversalList(head);

    head = removeFirst(head);
    head = removeFirst(head);
    head = removeLast(head);
    head = removeLast(head);

    std::print("After delete: ");
    tranversalList(head);

    // Test
    std::println("{} ", (search(head, 12) ? "TRUE" : "FALSE"));
    std::println("{} ", (search(head, 3) ? "TRUE" : "FALSE"));

    std::println("{}", count(head));

    // Giải phóng bộ nhớ
    deleteList(head);

    return 0;
}