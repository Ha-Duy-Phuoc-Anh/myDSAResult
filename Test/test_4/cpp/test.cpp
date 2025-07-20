#include <iostream>
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

// Hàm thêm nút vào cuối Danh sách liên kết
Node* append(Node* last, int data) {
    // Kiểm tra nếu danh sách là rỗng
    if (last == nullptr) {
        last = insertEmpty(last, data);
        return last;
    }

    // Tạo một nút mới với dữ liệu được cho
    Node* newNode = new Node(data);

    // Cập nhật con trỏ đên thêm nút vào Danh sách
    newNode->next = last->next;
    last->next = newNode;
    last = newNode;

    // Trả về Danh sách liên kết đã được chỉnh sửa
    return last;
}

// Hàm thêm nút ở vị trí cụ thể trong danh sách liên kết
Node* add(Node* last, int pos, int data) {
    // Kiểm tra nếu danh sách rỗng và vị trí người dùng đưa ra không phải là 0
    if (last == nullptr) {
        if (pos != 0) {
            std::cout << "ERROR 001: Position out of range\n";
            return last;
        }
        last = insertEmpty(last, data);
        return last;
    }
    // Nếu vị trí người dùng đưa ra là 1
    if (pos == 1) {   
        last = insert(last, data);
        return last;
    }

    // Nếu hai điều kiện trên đều là FALSE
    // Tạo một nút tạm và duyệt đến vị trí người dùng đưa ra (kèm theo việc kiểm tra nếu vị trí người dùng vượt quá kích thước danh sách)
    Node* temp = last;
    for (int i = 1; i < pos; ++i) {
        temp = temp->next;
        if (temp == last) {
            std::cout << "ERROR 001: Position out of range\n";
            return last;
        }
    }

    // Tạo nút với dữ liệu đã cho và chèn nút
    Node* newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;

    // Nếu nút được chèn ở vi trí cuối cùng thì update nút
    if (newNode->next == last->next) last = newNode;
    
    // Trả về danh sách đã được chỉnh sửa
    return last;
}

// Hàm xóa nút ở đầu danh sách liên kết
Node* remove(Node* last) {
    // Kiểm tra nếu Danh sách rỗng
    if (last == nullptr) {
        std::cout << "ERROR 002: Nothing to delete\n";
        return nullptr;
    }

    // Kiểm tra nếu nút tiếp theo là nullptr
    if (last->next == nullptr) {
        delete last;
        return nullptr;
    }

    // Nếu không thì xóa như bình thường
    Node* head = last->next;
    last->next = head->next;
    delete head;
    return last;
} 

// Xóa nút ở cuối danh sách liên kết
Node* delette(Node* last) {
    // Kiểm tra nếu Danh sách rỗng
    if (last == nullptr) {
        std::cout << "ERROR 002: Nothing to delete\n";
        return nullptr;
    }

    // Kiểm tra nếu nút tiếp theo là nullptr
    if (last->next == nullptr) {
        delete last;
        return nullptr;
    }

    // Nếu không thì tạo nút duyệt đến nút trước nút cuối cùng và xóa
    Node* head = last->next;
    Node* temp = last;
    while (temp->next != last) temp = temp->next;

    // Chỉnh con trỏ để tránh lỗi không thể truy cập bộ nhớ
    temp->next = head;
    delete last;
    last = temp;

    // Trả về Danh sách đã được chỉnh sửa
    return last;
}

// Xóa nút ở nút cụ thể trong danh sách liên kết
Node* delAt(Node* last, int val) {
    // Kiểm tra nếu Danh sách rỗng
    if (last == nullptr) {
        std::cout << "ERROR 002: Nothing to delete\n";
        return nullptr;
    }

    // Tạo nút duyệt đến vị trí người dùng đưa ra
    Node* tmp = last->next;
    Node* prev = last;

    // Nếu nút để xóa là nút duy nhất trong danh sách
    if (tmp == last && prev->data == val) {
        delete tmp;
        last = nullptr;
        return last;
    }

    // Nêu nút để xóa là nút đâu tiên
    if (tmp->data == val) {
        last->next = tmp->next;
        delete tmp;
        return last;
    }

    // Duyệt tới nút dự định sẽ xóa
    while (tmp != last && tmp->data != val) {
        prev = tmp;
        tmp = tmp->next;
    }

    // Nếu nút bị xóa được tìm thấy
    if (tmp->data == val) {
        prev->next = tmp->next;
        if (tmp == last) {
            last = prev;
        }
        delete tmp;
    }
    else {
        std::cout << "Node with data " << val << " was not found\n";
    }
    return last;
}

// Hàm tìm kiếm trong danh sách liên kết đơn
bool search(Node* last, int target) {
    // Khởi tạo một nút tạm
    Node* curr = last->next;
    
    // Lắp nếu con trỏ nút tạm khôn phải là NULL
    while (curr != last) {
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

void deleteList(Node* last) {
    if (last == nullptr) return;

    Node* current = last->next;
    Node* temp;

    while (current != last) {
        temp = current;
        current = current->next;
        delete temp;
    }
    delete last; // Free the last node
    last = nullptr; // Avoid dangling pointer
}

void print(Node* last) {
    if (last == nullptr) return;

    Node* current = last->next;
    do {
        std::cout << current->data << " ";
        current = current->next;
    } while (current != last->next);
    std::cout << std::endl;
}



int main() {
    // Khởi tạo danh sách liên kết vòng tròn
    Node* last = nullptr;
    last = insertEmpty(last, 1);
    last = insert(last, 2);
    last = insert(last, 3);
    last = insert(last, 4);
    last = insert(last, 5);
    last = append(last, 2);
    last = append(last, 3);
    last = append(last, 4);
    last = append(last, 5);
    last = add(last, 2, 10);
    last = add(last, 10, 10);

    std::cout << "Before delete: ";
    print(last);

    last = remove(last);
    last = remove(last);
    last = delette(last);
    last = delette(last);
    last = delAt(last, 3);
    last = delAt(last, 3);

    std::cout << "After delete: ";
    print(last);

    std::cout << (search(last, 4) ? "TRUE" : "FALSE") << std::endl;
    std::cout << (search(last, 3) ? "TRUE" : "FALSE") << std::endl;

    // Giải phóng bộ nhớ
    deleteList(last);

    return 0;
}