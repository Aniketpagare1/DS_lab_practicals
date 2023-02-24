#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

struct Node* createNode(int data){
    struct Node *n;
    n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    return n;
}

void display(struct Node *ptr){
    while(ptr != NULL){
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
}

struct Node *insertAtFirst(struct Node *head, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    
    ptr->data = data;
    ptr->next = head;
}

struct Node *insertAtIndex(struct Node *head, int index, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    for(int i=0;i<index-1;i++){
        p = p->next;
    }
    
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

struct Node *insertAtLast(struct Node *head, int data){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node *p = head;
    while(p->next!=NULL){
        p = p->next;
    }
    
    ptr->data = data;
    ptr->next = NULL;
    p->next = ptr;
    
    return head;
}
struct Node* deleteFirst(struct Node *head){
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;   
    int i=0;
    while (i!= index - 1)
    {
        p = p->next;
        i++;
    }
    struct Node *q = p->next;
    p->next = q->next;
    free(q);
    
    return head;
}

struct Node *deleteAtLast(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next!= NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);

    return head; 
}

void main(){
    struct Node *head = createNode(5);
    struct Node *second = createNode(10);
    struct Node *third = createNode(15);
    
    head->next = second;
    second->next = third;
    third->next = NULL;
    int a,af,ai,al;
    display(head);
    printf("\n\t_-_-_-_-_-_-_-_-INSERTION-_-_-_-_-_-_-_-");
    printf("\n\nEnter the node to be inserted at first:");
    scanf("%d",&af);
    head = insertAtFirst(head , af );
     printf("\nAfter Insertion at first\n");
     display(head);
     printf("Enter the index:");
     scanf("%d",&a);
     printf("Enter the node to be inserted at Index:");
    scanf("%d",&ai);
    head = insertAtIndex(head , a , ai);
    printf("\nAfter Insertion at index\n");
     display(head);
     printf("Enter the node to be inserted at Last:");
    scanf("%d",&al);
    head = insertAtLast(head,al);
    printf("\nAfter Insertion at last\n");
    display(head);
    
    printf("_-_-_-_-_-_-_-_-DELETION-_-_-_-_-_-_-_-");
    
    head = deleteFirst(head);
     printf("\nAfter Delition at first\n");
     display(head);
     printf("Enter the index from which node to be Deleted:");
     scanf("%d",&a);
    head = deleteAtIndex(head , a);
    printf("\nAfter Delition at index\n");
     display(head);
     
    head = deleteAtLast(head);
    printf("\nAfter Deleted at last\n");
    display(head);

}
