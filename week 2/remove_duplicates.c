#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}node;

void insert(node **head,int value)
{
   node *n;
   n=(node*)malloc(sizeof(node));
   
   n->data=value;
   n->next=NULL;
   
   if(*head==NULL)
   {
       *head=n;
   }
   else
   {
       node* current=*head;
       while(current->next!=NULL)
       {
           current=current->next;
       }
       current->next=n;
   }
}

void find(node *head)
{
    node *current=head;
    node *next=NULL;
    node* temp;
    
    while(current && current->next!=NULL)
    {
        if(current->data == current->next->data)
        {
            temp=current->next->next;
            free(current->next);
            current->next=temp;
        }
        else
        {
            current=current->next;
        }
    }
}

void printlist(node *head)
{
   
    node* current= head;
    while(current!=NULL)
    {
        printf("%d->",current->data);
        current=current->next;
    }
    printf("NULL \n");
}

int main()
{
    node* list=NULL;
    int i,n,d;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    printf("Enter in sorted linked list: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&d);
        insert(&list,d);
        printlist(list);
    }
    printf("After removing the duplicates \n");
    find(list);
    printlist(list);
    return 0;
}










