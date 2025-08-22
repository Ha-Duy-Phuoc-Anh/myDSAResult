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
        Node* next;

        // Khởi tạo một đối tượng nút
        Node(int data) : key(data), next(nullptr) {};
    };

    // Nút head của Danh sách liên kết
    Node* head = nullptr;

public:
    // Hàm hiển thị Danh sách liên kết
    void display() const {
        // Tạo nút tạm duyệt và in từng nút
        Node* curr = head;
        while (curr) {
            std::cout << curr->key << " -> ";
            curr = curr->next;
        }

        // In ra NULLPTR ở cuối danh sách
        std::cout << "nullptr" << std::endl; 
    }

    // Hàm thêm nút vào đầu Danh sách liên kết 
    void push_front(int data) {
        // Khởi tạo nút mới
        Node* newNode = new Node(data);

        // Gán con trỏ nút mới vào head
        newNode->next = head;

        // Chuyển head sang nút mới
        head = newNode;
    }

    // Hàm thêm nút vào cuối Danh sách liên kết
    void push_back(int data) {
        // Tạo nút mới với dữ liệu được cho
        Node* newNode = new Node(data);

        // Nếu danh sách rỗng thì thay head với nút mới
        if (head == nullptr) {
            head = newNode;
            return;
        }

        // Tạo một nút tạm và duyệt đến cuối danh sách
        Node* curr = head;
        while (curr->next != nullptr)
            curr = curr->next;

        // Gán nút mới vào kế vị trí nút tạm
        curr->next = newNode;
    }

    // Hàm thêm nút vào vị trí cụ thể trong Danh sách liên kết
    void push_at(int data, int position) {
        // Tạo nút mới để tránh gọi object quá nhiều lần
        Node* newNode = new Node(data);
        
        // Nếu vị trí bé hơn 0
        if (position < 0) {
            std::cerr << "ERROR 001: Invalid Position" << ENTER;
            delete newNode;
            return;
        }

        // Nếu danh sách rỗng và vị trí là 0 thì gán nút vào head
        if (!head && !position) {
            newNode->next = head;
            head = newNode;
            return;
        }

        // Nếu khác thì tạo nút tạm di chuyển đến trước ví trị mà người dùng đưa ra
        Node* current = head;
        for (int i = 0; i < position - 1 && current != nullptr; i++)
            current = current->next;
        
        // Nếu current là nullptr thì xóa nút mới để tránh leak bộ nhớ (là nullptr thì đã out of range)
        if (!current) {
            std::cerr << "ERROR 001: Invalid Position" << ENTER;
            delete newNode;
            return;
        }

        // Tạo nút tạm để giữ nút tiếp theo của nút current nếu nút tiếp theo của current ko phải nullptr
        newNode->next = current->next;
        current->next = newNode;
    }

    // Hàm xóa nút ở đầu Danh sách liên kết
    int pop_front() {
        // Kiểm tra nếu Danh sách rỗng
        if (!head) {
            std::cout << "ERROR 002: List is empty" << std::endl;
            return -1;
        }

        // Nếu không thì tách head ra chỗ khác và xóa nó (lưu dữ liệu của nút chuẩn bị xóa để trả về nữa)
        Node* willBeDelete = head;
        int popedNodeData = willBeDelete->key;

        head = head->next;
        delete willBeDelete;

        return popedNodeData;
    }

    // Hàm xóa nút ở cuối Danh sách liên kết
    int pop_back() {
        // Nếu danh sách rỗng
        if (!head) {
            std::cout << "ERROR 002: List is empty" << ENTER;
            return -1;
        }

        // Nếu danh sách chỉ có một nút
        if (head->next == nullptr) {
            int val = head->key;
            delete head;
            head = nullptr;
            return val;
        }

        // Nếu ko thì duyệt đến nút cuối
        Node* current = head;
        while (current->next->next != nullptr)
            current = current->next;

        // Lấy giá trị của nút đó, xóa nút đó đi và trả về giá trị của nút đã xóa
        int popedValue = current->next->key;
        delete current->next;
        current->next = nullptr;
        return popedValue;
    }

    // Hàm xóa nút ở vị trí cụ thể trong Danh sách liên kết
    int pop_at(int position) {
        // Nếu danh sách rỗng
        if (!head) {
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
        Node* current = head;
        for (int i = 0; i < position - 1 && current != nullptr; i++)
            current = current->next;
        
        // Kiểm tra nếu current là nullptr (hoặc nút được xóa là nullptr) thì báo lỗi
        if (current == nullptr || current->next == nullptr) {
            std::cout << "ERROR 001: Invalid Position\n";
            return -1;
        }

        // Nếu ko thì tạo nút tạm tách nút được xóa với dữ liệu liệu của nút được xóa ra
        // Sau đó nối con trỏ curr vào nút tiếp theo của nút tiếp theo và xóa nút tạm đó
        Node* tmp = current->next;
        int popedValue = tmp->key;
        
        current->next = tmp->next;
        delete tmp;
        
        return popedValue;
    }

    // Hàm tìm kiếm nút trong Danh sách liên kết
    bool search(int data) const {
        // Tạo nút tạm duyệt đến khi tìm thấy giá trí đầu vào
        Node* current = head;
        while (current != nullptr) {
            if (current->key == data)
                return true;

            current = current->next;
        }

        // Nếu tới đây mà vẫn chưa thoát hàm thì coi như chưa tìm thấy
        return false;
    }

    // Hàm lấy kích thước danh sách liên kết
    size_t size() const {
        size_t length = 0;
        Node* curr = head;
        while (curr != nullptr) {
            length++;
            curr = curr->next;
        }

        return length;
    }

    // Hàm giải phóng bộ nhớ Danh sách liên kết
    ~LinkedList() {
        // Tạo một nút tạm duyệt từng nút và xóa
        Node* curr = head;
        while (curr) {
            Node* tmp = curr;
            curr = curr->next;
            delete tmp;
        }
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

    std::cout << (newList.search(12) ? "TRUE" : "FALSE")
              << ENTER;

    std::cout << (newList.search(3) ? "TRUE" : "FALSE") 
              << ENTER;

    std::cout << newList.size()
              << ENTER;

    return 0;
}