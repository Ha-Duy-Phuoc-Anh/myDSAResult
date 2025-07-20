#file [[Ngăn xếp]]

## FULL Mẫu Method
---
``` cpp
class Stack {
private:
    // Tạo nút head là nút đầu
    Node* head;

public:
    // Hàm khởi tạo Stack
    Stack() : head(nullptr) {};

    // Hàm thêm dữ liệu vào Stack
    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;        
    } 

    // Hàm xóa dữ liệu khỏi Stack
    void pop() {
        if (head == nullptr) {
            std::cout << "ERROR 001: Stack is empty" << std::endl;
        }
        else {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    // Hàm lấy dữ liệu của TOP
    int peek() {
        if (!head) {
            std::cout << "ERROR 001: Stack is empty" << std::endl;
            return INT_MIN;
        }
        else {
            return head->data;
        }
    }

    // Hàm kiểm tra Stack rỗng
    bool isEmpty() {
        return head == nullptr;
    }

    // Hàm ghi Stack ra CLI
    void print() {
        Node* curr = head;
        while (curr != nullptr) {
            std::cout << curr->data << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }


    // Hàm xóa Stack giải phóng bộ nhớ
    ~Stack() {
        Node* curr = this->head;
        while (curr != nullptr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
};
```
