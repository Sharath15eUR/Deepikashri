#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef Node* NodePtr;

typedef struct Queue {
    NodePtr front;
    NodePtr rear;
} Queue;

NodePtr createNode(int data) {
    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void initializeQueue(Queue* queue) {
    queue->front = queue->rear = NULL;
}

int isEmpty(Queue* queue) {
    return (queue->front == NULL);
}

void enqueue(Queue* queue, int data) {
    NodePtr newNode = createNode(data);
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        exit(1);
    }
    NodePtr temp = queue->front;
    int data = temp->data;
    if (queue->front == queue->rear) {
        queue->front = queue->rear = NULL;
    } else {
        queue->front = queue->front->next;
    }
    free(temp);
    return data;
}

void sortQueue(Queue* queue) {
    int temp;
    NodePtr current, compare;

    for (current = queue->front; current != NULL; current = current->next) {
        for (compare = current->next; compare != NULL; compare = compare->next) {
            if (current->data > compare->data) {
                temp = current->data;
                current->data = compare->data;
                compare->data = temp;
            }
        }
    }
}

void displayQueue(Queue* queue) {
    NodePtr current = queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Queue myQueue;
    initializeQueue(&myQueue);

    int numElements, element;

    printf("Enter the number of elements in the queue: ");
    scanf("%d", &numElements);

    printf("Enter the elements: ");
    for (int i = 0; i < numElements; i++) {
        scanf("%d", &element);
        enqueue(&myQueue, element);
    }

    sortQueue(&myQueue);

    printf("Sorted Queue: ");
    displayQueue(&myQueue);

    return 0;
}
