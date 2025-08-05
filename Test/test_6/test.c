#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Tạo kiểu dữ liệu Queue
 * 
 */
typedef struct Queue {
    int head, tail;
    int capacity;
    int* data;
} Queue;

/**
 * @brief Hàm khởi tạo Queue
 * 
 * @param size Đầu vào kích thước của Queue
 * @return Queue đã được cấp bộ nhớ đầy đủ
 */
Queue* Queue_init(int size) {
    Queue* tmp = (Queue*) malloc(sizeof(Queue) * size);
    tmp->data = (int*) malloc(sizeof(int) * size);
    tmp->capacity = size;
    tmp->head = 0;
    tmp->tail = -1;
    return tmp;
}

/**
 * @brief Hàm thêm dữ liệu vào Queue (enqueue)
 * 
 * @param queue Queue cần được thêm dữ liệu
 * @param value Giá trị của dữ liệu mà người dùng đưa vào
 * @return Queue đã được thêm dữ liệu
 */
Queue* Queue_enqueue(Queue* queue, int value) {
    if (queue->tail >= queue->capacity - 1) {
        printf("ERROR 002: Queue is full\n");
        return queue;
    }
    queue->data[++queue->tail] = value;
    return queue;
}

/**
 * @brief Hàm Xóa dữ liệu khỏi Queue
 * 
 * @param queue Queue cần xóa dữ liệu
 * @return Queue đã được xóa dữ liệu
 */
Queue* Queue_dequeue(Queue* queue) {
    if (queue->head > queue->tail) {
        printf("ERROR 001: Queue is empty\n");
        return queue;
    };
    for (int i = queue->head; i < queue->tail; i++) {
        queue->data[i] = queue->data[i + 1];
    }
    queue->tail--;
    return queue;
}

/**
 * @brief Hàm lấy giá trị của FRONT
 * 
 * @param queue Queue cần được lấy giá trị
 * @return Giá trị của FRONT trong Queue
 */
int Queue_peek(Queue* queue) {
    return queue->data[queue->head];
}

/**
 * @brief Hàm lấy kích thước của Queue
 * 
 * @param queue Queue mà ta muốn lấy kích thước
 * @return Kích thước của Queue
 */
int Queue_size(Queue* queue) {
    return queue->tail;
}

/**
 * @brief Hàm kiểm tra Queue rỗng
 * 
 * @param queue Queue mà ta muốn kiểm tra
 * @return `true` nếu như rỗng 
 * @return `false` nếu như không rỗng
 */
bool Queue_isEmpty(Queue* queue) {
    return queue->head > queue->tail;
}

/**
 * @brief Hàm kiểm tra Queue đầy
 * 
 * @param queue Queue mà người dùng muốn kiểm tra
 * @return `true` nếu như đầy 
 * @return `false` nếu như không
 */
bool Queue_isFull(Queue* queue) {
    return queue->tail >= queue->capacity - 1;
}

/**
 * @brief Hàm hiển thị dữ liệu trong Queue
 * 
 * @param queue Hàng đợi mà người dùng muốn hiển thị
 */
void Queue_display(Queue* queue) {
    for (int i = queue->head; i <= queue->tail; i++) {
        printf("%i ", queue->data[i]);
    }
    printf("\n");
}

/**
 * @brief Hàm xóa hàng đợi để giải phóng bộ nhớ
 * 
 * @param queue Hàng đợi cần xóa
 */
void Queue_free(Queue* queue) {
    free(queue->data);
    free(queue);
}

int main() {
    Queue* newQueue = Queue_init(4);
    newQueue = Queue_enqueue(newQueue, 31);
    newQueue = Queue_enqueue(newQueue, 28);
    newQueue = Queue_enqueue(newQueue, 54);
    newQueue = Queue_enqueue(newQueue, 49);

    printf("Before delete: ");
    Queue_display(newQueue);

    printf("Is queue full: %s\n", (Queue_isFull(newQueue) ? "TRUE" : "FALSE"));
    printf("Is queue empty: %s\n", (Queue_isEmpty(newQueue) ? "TRUE" : "FALSE"));

    newQueue = Queue_dequeue(newQueue);
    newQueue = Queue_dequeue(newQueue);

    printf("Size after 2 dequeue: %i\n", Queue_size(newQueue));
    printf("The FRONT element: %i\n", Queue_peek(newQueue));

    newQueue = Queue_dequeue(newQueue);
    newQueue = Queue_dequeue(newQueue);

    printf("Is queue full after dequeue: %s\n", (Queue_isFull(newQueue) ? "TRUE" : "FALSE"));
    printf("Is queue empty after dequeue: %s\n", (Queue_isEmpty(newQueue) ? "TRUE" : "FALSE"));

    Queue_free(newQueue);

    return 0;
}