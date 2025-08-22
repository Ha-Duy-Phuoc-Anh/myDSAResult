#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedlist.h"

// Khởi tạo kiểu dữ liệu
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Queue* Queue_init() {
    Queue* tmp = malloc(sizeof(Queue));
    tmp->front = NULL;
    tmp->rear = NULL;
    return tmp;
}

Queue* Queue_enqueue(Queue* queue, int value) {
    Node* newNode = Node_init(value);
    if (queue->front == NULL && queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return queue;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
    return queue;
}

Queue* Queue_dequeue(Queue* queue) {
    if (queue->front == NULL && queue->rear == NULL) {
        printf("ERROR 001: Queue is empty\n");
        return queue;
    }
    Node* tmp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) queue->rear = NULL;
    free(tmp->data);
    free(tmp);
    return queue;
}

int Queue_peek(Queue* queue) {
    return *(queue->front->data);
}

int Queue_size(Queue* queue) {
    Node* curr = queue->front;
    int length = 0;
    while (curr != NULL) {
        curr = curr->next;
        length++;
    }
    return length;
}

bool Queue_isEmpty(Queue* queue) {
    return queue->front == NULL && queue->rear == NULL;
}

void Queue_display(Queue* queue) {
    Node* curr = queue->front;
    while (curr != NULL) {
        printf("%i ", *(curr->data));
        curr = curr->next;
    }
    printf("\n");
}

void Queue_free(Queue* queue) {
    while (queue->front != queue->rear && queue->front != NULL && queue->rear != NULL) {
        Node* tmp = queue->front;
        queue->front = queue->front->next;
        if (queue->front == NULL) queue->rear = NULL;
        free(tmp->data);
        free(tmp);
    }
    free(queue);
}

int main() {
    Queue* newQueue = Queue_init();
    newQueue = Queue_enqueue(newQueue, 31);
    newQueue = Queue_enqueue(newQueue, 28);
    newQueue = Queue_enqueue(newQueue, 54);
    newQueue = Queue_enqueue(newQueue, 49);

    printf("Before delete: ");
    Queue_display(newQueue);

    printf("Is queue empty: %s\n", (Queue_isEmpty(newQueue) ? "TRUE" : "FALSE"));

    newQueue = Queue_dequeue(newQueue);
    newQueue = Queue_dequeue(newQueue);

    printf("Size after 2 dequeue: %i\n", Queue_size(newQueue));
    printf("The FRONT element: %i\n", Queue_peek(newQueue));

    newQueue = Queue_dequeue(newQueue);
    newQueue = Queue_dequeue(newQueue);

    printf("Is queue empty after dequeue: %s\n", (Queue_isEmpty(newQueue) ? "TRUE" : "FALSE"));

    Queue_free(newQueue);

    return 0;
}