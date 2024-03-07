#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef Node* NodePtr;

NodePtr createNode(int data) {
    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertSorted(NodePtr* head, int value) {
    NodePtr newNode = createNode(value);

    if (*head == NULL || value < (*head)->data) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
    } else {
        NodePtr current = *head;
        while (current->next != NULL && current->next->data < value) {
            current = current->next;
        }

        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }
}

void printList(NodePtr head) {
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    NodePtr head = NULL;
    int numNodes, element;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    printf("Enter the elements: ");
    for (int i = 0; i < numNodes; i++) {
        scanf("%d", &element);
        insertSorted(&head, element);

    }

    printf("Doubly Linked List after insertion: ");
    printList(head);

    return 0;
}
