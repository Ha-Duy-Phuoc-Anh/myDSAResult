#include <stdio.h>
#include <stdbool.h>
#include "cnarr.h"

// Khởi tạo kiểu dữ liệu của Danh sách liên kết đơn
typedef struct
{
	// Phần dữ liệu của Danh sách liên kết đơn
	int data;
	
	// Con trỏ đến nút tiếp theo
	Node* next;
} Node;

// Hàm khởi tạo nút
Node* init(int data)
{
    Node* head = (Node*) malloc(sizeof(Node)); // Cấp phát bộ nhớ cho nút
    head->data = data;  // Cấp dữ liệu
    head->next = NULL;  // Cấp con trỏ đến nút tiếp theo
    return head;    // Trẩ về nút
}

// Hàm duyệt danh sách liên kết đơn
void print(Node* head) {
    // Khởi tạo một nút tạm
    Node* temp = head;

    // Lặp nếu nút tiếp theo không phải là NULL
    while (temp != NULL) {
        printf("%i ", temp->data);  // In ra cửa sổ dòng lệnh
        temp = temp->next;  // Trỏ đến nút tiếp theo
    }

    printf("\n");   // Xuống dòng sau khi in xong    
}

// Hàm tìm kiếm trong danh sách liên kết đơn
bool search(Node* head, int target) {
    // Khởi tạo một nút tạm
    Node* curr = head;
    
    // Lắp nếu con trỏ nút tạm khôn phải là NULL
    while (curr != NULL) {
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
    while (temp != NULL) {
        length++;                   // Tăng kích thước
        temp = temp->next;          // Trỏ đến nút tiếp theo
    }
    
    return length;      // Trả về kích thước cho chương trình
}

// Hàm thêm nút vào đầu danh sách liên kết
Node* insert(Node* head, int data) {
    // Tạo một nút mới dựa trên dữ liệu đã cho
    Node* newNode = init(data);

    // Trỏ con trỏ của nút mới đến HEAD
    newNode->next = head;

    // Trả về danh sách liên kết đã điều chỉnh, và cho newNode là HEAD mới của nh sách
    return newNode;
}

// Hàm thêm nút vào cuối danh sách liên kết
Node* append(Node* head, int data) {
    // Khởi tạo một nút với giá trị đã cho
    Node* newNode = init(data);
    
    // Kiểm tra nếu danh sách rỗng, nếu rỗng thì chèn thẳng nút vào HEAD và ngắt hàm
    if (head == NULL) return newNode;

    // Tạo một nút tạm
    Node* last = head;

    // Lặp tới khi tới nút cuối cùng
    while (last->next != NULL) last = last->next;

    // Chèn nút tại nút tạm last
    last->next = newNode;

    // Trả về danh sách liên kết đã chỉnh sửa
    return head;
}

// Hàm thêm nút vào một vị trí cụ thể trong danh sách liên kết
Node* add(Node* head, int pos, int data) {
    // Điều kiện này cho biết vị trí của người dùng có ít hơn 1 không, nếu có thì báo lỗi
    if (pos < 1) {
        printf("ERROR 001: Position out of range\n");
        return head;
    }

    // Điều kiện này cho biết vị trí có phải một hay không, nếu phải thì thao tác giống với thêm nút vào đầu danh sách liên kết
    if (pos == 1) {
        Node* newNode = init(data);
        newNode->next = head;
        return newNode;
    }

    // Nếu như tất cả các điều kiện trên đều sai thì tạo một nút tạm duyệt tới vị trí mà người dùng đưa ra
    Node* curr = head;
    for (int i = 1; curr != NULL && i < pos - 1; i++) curr = curr->next;

    // Kiểm tra nếu curr là NULL thì báo lỗi, vì NULL chỉ xuất hiện ở cuối cùng danh sách
    if (curr == NULL) {
        printf("ERROR 001: Position out of range");
        return head;
    }

    // Nếu bình thường thì tiếp tục
    Node* newNode = init(data);     // Tạo nút với dữ liệu được cho
    
    // Chèn nút mới vào vị trí curr
    newNode->next = curr->next;
    curr->next = newNode;

    // Trả về danh sách đã được chỉnh sửa
    return head;
}

// Hàm xóa nút đầu trong danh sách liên kết
Node* removeFirst(Node* head) {
    // Kiểm tra nếu danh sách rỗng
    if (head == NULL) {
        printf("ERROR 002: List is empty\n");
        return NULL;
    }

    // Tạo một nút tạm để xóa nút
    Node* temp = head;

    // Chuyển head đến con trỏ tiếp theo
    head = head->next;

    // Xóa nút đầu trong danh sách
    free(temp);

    // Trả về head
    return head;
}

// Hàm xóa nút cuối trong danh sách liên kết
Node* removeLast(Node* head) {
    // Kiểm tra nếu danh sách rỗng
    if (head == NULL) {
        printf("ERROR 002: List is empty\n");
        return NULL;
    }

    // Tạo một nút tạm thời và di chuyển nó đến nút sau nút cuối cùng
    Node* temp = head;
    while (temp->next->next != NULL) temp = temp->next;

    // Xóa nút sau nút tạm
    free(temp->next);

    // Trỏ con trỏ sang NULL
    temp->next = NULL;

    // Trả về danh sách đã sửa
    return head;
}

// Hàm xóa nút nhất định trong danh sách liên kết
Node* removeNode(Node* head, int pos) {
    // Điều kiện này cho biết vị trí có ít hơn 1 không, nếu có thì báo lỗi
    if (pos < 1) {
        printf("ERROR 001: Position out of range\n");
        return head;
    }

    // Điều kiện này cho biết vị trí có phải một hay không, nếu phải thì thao tác giống với xóa nút vào đầu danh sách liên kết
    if (pos == 1) {
        head = removeFirst(head);
        return head;
    }

    // Tạo một nút tạm để duyệt đến vị trí mà người dùng đưa ra
    Node* curr = head;
    for (int i = 1; curr != NULL && i < pos - 1; i++) curr = curr->next;

    // Kiểm tra nếu curr là NULL thì báo lỗi, vì NULL chỉ xuất hiện ở cuối cùng danh sách
    if (curr == NULL || curr->next == NULL) {
        printf("ERROR 001: Position out of range\n");
        return head;
    }

    // Tạo một nút tạm để xóa nút
    Node* temp = curr->next;

    // Chuyển con trỏ của nút tạm đến nút tiếp theo
    curr->next = temp->next;

    // Xóa nút tạm
    free(temp);

    // Trả về danh sách đã sửa
    return head;
}

// Hàm đảo ngược danh sách liên kết
Node* reverse(Node* head) {
    Node* prev = NULL;   // Tạo nút đứng trước
    Node* curr = head;      // Tạo nút hiện tại
    Node* next = NULL;   // Tạo nút kiểm soát con trỏ

    // Lặp khi curr không phải là NULL
    while (curr) {
        next = curr->next;  // Chuyển next đến con trỏ tiếp theo của danh sách liên kết
        curr->next = prev;  // Chuyển con trỏ tiếp theo của danh sách liên kết đến nút đứng trước
        prev = curr;        // Nối con trỏ nút đứng trước đến nút hiện tại
        curr = next;        // Nối nút hiện tại đến nút kiểm soát con trỏ
    }

    // Trả về danh sách đã được chỉnh sửa
    return prev;
}

// Hàm sửa đổi Danh sách liên kết đơn
Node* modify(Node* head) {
    // Kiểm tra nếu nút tiếp theo là NULL thì thoát
    if (!head->next) {
        return head;
    }

    // Khởi tạo các nút hỗ trợ thao tác
    Node* slow = head;
    Node* fast = head;
    Node* mid;

    // Tìm nút ở giữa Danh sách liên kết
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    mid = slow;

    // Tạo nút đánh dấu điểm đảo ngược
    Node* reverseList = mid->next;

    // Tách danh sahcs liên kết thành hai nửa
    mid->next = NULL;

    // Tạo hai nút tạm để duyệt danh sách
    Node* curr1 = head;
    Node* curr2 = reverseList;
    Cnarr* firstHalf = Cnarr_init(8);
    Cnarr* secondHalf = Cnarr_init(8);

    // Sao chép hết dữ liệu của hai nút vào hai vector
    while (curr1) {
        Cnarr_append(firstHalf, curr1->data);
        curr1 = curr1->next;
    }

    while (curr2) {
        Cnarr_append(secondHalf, curr2->data);
        curr2 = curr2->next;
    }

    // Chỉnh sửa dữ liệu của vector
    for (int i = 0; i < Cnarr_getSize(secondHalf); i++) {
        int x = firstHalf->data[i];
        firstHalf->data[i] = secondHalf->data[i] - x;
        secondHalf->data[i] = x;
    }

    // Chuyẻn Vector trở về Danh sách liên kết
    curr1 = head;
    for (int i = 0; i < Cnarr_getSize(firstHalf); i++) {
        curr1->data = firstHalf->data[i];
        curr1 = curr1->next;
    }

    curr2 = reverseList;
    for (int i = 0; i < Cnarr_getSize(secondHalf); i++) {
        curr2->data = secondHalf->data[i];
        curr2 = curr2->next;
    }

    // Đảo ngược hai nửa và ráp lại hai danh sách liên kết
    mid->next = reverse(reverseList);

    // Giải phóng bộ nhớ hai mảng
    Cnarr_free(firstHalf);
    Cnarr_free(secondHalf);

    // Trả về danh sách đã được chỉnh sửa
    return head;
}

void deleteList(Node** head) {
    while (*head != NULL) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main() {
    // Khởi tạo danh sách liên kết đơn
    Node* head = init(1);
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
    printf("Before delete: ");
    print(head);

    head = removeFirst(head);
    head = removeFirst(head);
    head = removeLast(head);
    head = removeLast(head);
    head = removeNode(head, 2);
    head = removeNode(head, 5);

    printf("After delete: ");
    print(head);

    head = reverse(head);
    printf("After reverse: ");
    print(head);

    head = modify(head);
    printf("After modified: ");
    print(head);

    // Test
    printf("%s\n", (search(head, 12) ? "TRUE" : "FALSE"));
    printf("%s\n", (search(head, 3) ? "TRUE" : "FALSE"));

    printf("%i\n", count(head));

    // Giải phóng bộ nhớ
    deleteList(&head);

    return 0;
}