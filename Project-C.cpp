#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Queue {
    int items[MAX];
    int front;
    int rear;
} Queue;

// Функция для создания очереди
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Функция для проверки, является ли очередь пустой
int isEmpty(Queue* q) {
    return q->front == -1;
}

// Функция для проверки, является ли очередь полной
int isFull(Queue* q) {
    return q->rear == MAX - 1;
}

// Функция для добавления элемента в очередь
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("The line is full!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
    printf("Added: %d\n", value);
}

// Функция для удаления элемента из очереди
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("The line is empty!\n");
        return -1; // Возвращаем -1, если очередь пуста
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1; // Сбрасываем очередь
    }
    return item;
}

// Функция для отображения элементов очереди
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("The line is empty!\n");
        return;
    }
    printf("Elements in the queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

// Главная функция
int main() {
    Queue* q = createQueue();
    
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);
    
    printf("Deleted: %d\n", dequeue(q));
    display(q);
    
    enqueue(q, 40);
    display(q);
    
    return 0;
}
