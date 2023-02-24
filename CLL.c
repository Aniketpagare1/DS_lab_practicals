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

void display(struct Node *head){
    struct Node* ptr = head;
    do
    {
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }while(ptr != head);
}

struct Node *insertAtFirst(struct Node *head, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head->next;
    while(p->next!=head){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;

    return head;
}

struct Node *insertAtIndex(struct Node *head, int index, int data)
{
	int i;
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    for(i=0;i<index-1;i++){
        p = p->next;
    }
    
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

struct Node *insertAtLast(struct Node *head, int data){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    
    struct Node *p = head->next;
    do
    {
        p = p->next;
    }while(p->next!=head);
    
    p->next = ptr;
    ptr->next = head;
    
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


void main(){
    struct Node *head = createNode(5);
    struct Node *second = createNode(10);
    struct Node *third = createNode(20);
    
    head->next = second;
    second->next = third;
    third->next = head;

    display(head);
    int a,b;
    
    
    printf("\nEnter the Index in which you want to insert : ");
    scanf("%d",&a);
    printf("\nEnter the Value of Node : ");
    scanf("%d",&b);
     head = insertAtIndex(head , a , b);
    printf("\nAfter Insertion\n");
    display(head);
    printf("\nEnter the Index in which you want to Delete : ");
    scanf("%d",&a);
    head = deleteAtIndex(head , a);
    printf("\nAfter Deletion\n");
    display(head);
    

}

