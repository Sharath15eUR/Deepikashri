#include <stdio.h>
#include <stdlib.h>


struct QueueNode {
    int data;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode* front; 
    struct QueueNode* rear;
};

struct QueueNode* createNode(int data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void initializeQueue(struct Queue* queue) {
    queue->front = queue->rear = NULL;
}

int isEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

void enqueue(struct Queue* queue, int data) {
    struct QueueNode* newNode = createNode(data);
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        exit(1);
    }
    struct QueueNode* temp = queue->front;
    int data = temp->data;

    if (queue->front == queue->rear) {

        queue->front = queue->rear = NULL;
    } else {
        queue->front = queue->front->next;
    }

    free(temp);
    return data;
}


int countElements(struct Queue* queue) {
    int count = 0;
    struct QueueNode* current = queue->front;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void displayQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    struct QueueNode* current = queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Queue myQueue;
    initializeQueue(&myQueue);

    printf("Initialize a queue!\n");

    if (isEmpty(&myQueue)) {
        printf("Check the queue is empty or not? Yes\n");
    } else {
        printf("Check the queue is empty or not? No\n");
    }

    printf("Number of elements in queue: %d\n", countElements(&myQueue));

    printf("\nInsert some elements into the queue:\n");


    enqueue(&myQueue, 1);
    enqueue(&myQueue, 2);
    enqueue(&myQueue, 3);

    printf("Queue elements are: ");
    displayQueue(&myQueue);

    printf("Number of elements in queue: %d\n", countElements(&myQueue));

    printf("\nDelete two elements from the said queue:\n");

    dequeue(&myQueue);
    dequeue(&myQueue);

    printf("Queue elements are: ");
    displayQueue(&myQueue);

    printf("Number of elements in queue: %d\n", countElements(&myQueue));

    printf("\nInsert another element into the queue:\n");


    enqueue(&myQueue, 4);

    printf("Queue elements are: ");
    displayQueue(&myQueue);

    printf("Number of elements in the queue: %d\n", countElements(&myQueue));

    return 0;
}

