#include<stdio.h>
#include<stdlib.h>

typedef struct Node 
{
    int data;
    struct Node *next;
    struct Node *prev;
}node;

void insert(node **head,int value)
{
    node *n;
    n=(node*)malloc(sizeof(node));
    if(n==NULL)
    {
        printf("Memory not allocated");
        exit(1);
    }
    n->data=value;
    n->next=NULL;
    
    if(*head==NULL)
    {
        n->prev=NULL;
        *head=n;
    }
    else
    {
        node *current=*head;
        while(current->next!=NULL)
        {
            current=current->next;
        }
        current->next=n;
    }
}


void printlist(node *head)
{
    node *current=head;
    while(current!=NULL)
    {
        printf("%d<->",current->data);
        current=current->next;
    }
    printf("NULL \n");
        
}

void rotate(node **head, int n1, int n)
{
    int i;
    if (*head == NULL || n == 0)
    {
        exit(1);
    }
    n1 = n1 % n;
    
    if (n1 == 0)
    {
        return;  
    }

    node *current = *head;
 
    for(i=0;i<n1-1;i++)
    {
        current = current->next;
    }
    
    node *newHead = current->next;
    current->next = NULL;
    newHead->prev = NULL;

    current = newHead;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = *head;
    (*head)->prev = current;
    *head = newHead;
}
int main()
{
    int i,d,n,n1;
    node *list=NULL;
    printf("Enter the number of nodes in the list: \n");
    scanf("%d",&n);
    printf("Enter the nodes: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&d);
        insert(&list,d);
        printlist(list);
    }
    printf("Enter the number of nodes to be rotated in the list: \n");
    scanf("%d",&n1);
    rotate(&list,n1,n);
    printf("The list after rotation: \n");
    printlist(list);
    return 0;
}