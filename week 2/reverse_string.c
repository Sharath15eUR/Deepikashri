#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackNode {
    char data;
    struct StackNode* next;
} StackNode;

typedef StackNode* StackNodePtr;

StackNodePtr createNode(char data) {
    StackNodePtr newNode = (StackNodePtr)malloc(sizeof(StackNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int isEmpty(StackNodePtr root) {
    return (root == NULL);
}

void push(StackNodePtr* root, char data) {
    StackNodePtr newNode = createNode(data);
    newNode->next = *root;
    *root = newNode;
}

char pop(StackNodePtr* root) {
    if (isEmpty(*root)) {
        printf("Stack is empty\n");
        exit(1);
    }
    StackNodePtr temp = *root;
    *root = (*root)->next;
    char popped = temp->data;
    free(temp);
    return popped;
}

void reverseString(char* str) {
    int length = strlen(str);
    StackNodePtr stack = NULL;

    for (int i = 0; i < length; i++) {
        push(&stack, str[i]);
    }

    for (int i = 0; i < length; i++) {
        str[i] = pop(&stack);
    }
}

int main() {
    char inputString[100];

    printf("Enter a string: ");
    fgets(inputString, sizeof(inputString), stdin);
    inputString[strcspn(inputString, "\n")] = '\0';

    reverseString(inputString);

    printf("Reversed String: %s\n", inputString);

    return 0;
}
