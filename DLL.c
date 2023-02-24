#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * prev;
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

void insertStart(struct Node** head, int data){
    
    // creating memory for newNode
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    
    // assigning newNode's next as the current head 
    // Assign data & and make newNode's prev as NULL
    newNode->data = data;
    newNode->next = *head;
    newNode->prev = NULL;
    
    // if list already had item(s)
    // We need to make current head previous node as this new node
    if(*head != NULL)
        (*head)->prev = newNode;
    
    // change head to this newNode
    *head = newNode;
    
}
int calcSize(struct Node* node){
    int size=0;

    while(node!=NULL){
        node = node->next;
        size++;
    }
    return size;
}

void insertAt(int pos, int data, struct Node** head){
        int size = calcSize(*head);

    //If pos is 0 then should use insertStart method
    //If pos is less than 0 then can't enter at all
    //If pos is greater than size then bufferbound issue
    if(pos<1 || size < pos) 
    { 
        printf("Can't insert, %d is not a valid position\n",pos); 
    } 
    else{ 
        struct Node* temp = *head; 
        struct Node* newNode = (struct Node*) malloc(sizeof(struct Node)); 

        newNode->data = data;
        newNode->next = NULL;
        
        // traverse till pos
        while(--pos)
        {
            temp=temp->next;
        }
        
        // assign prev/next of this new node
        newNode->next = temp->next;
        newNode->prev = temp;
        
        // change next of temp node
        temp->next = newNode;
    }
}

struct Node* insertLast(struct Node*head , int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    struct Node *temp = head;

    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = NULL;
    return head;
}
struct Node* deleteFirst(struct Node* head){
    struct Node* p = head;
    head = p->next;
    head->prev = NULL;
    free(p);
    return head;
}

struct Node *deleteLast(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next!= NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->prev = p;
    p->next = NULL;
    free(q);
    return head; 
}


void main(){
    struct Node *head =createNode(10);
    struct Node *second = createNode(20);
    struct Node *third = createNode(30);
    
    head->prev = NULL;
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = NULL;
    int af,ai,al,a;
    display(head);
   printf("\n\t_-_-_-_-_-_-_-_-INSERTION-_-_-_-_-_-_-_-");
    printf("\n\nEnter the node to be inserted at first:");
    scanf("%d",&af);
    insertStart(&head , af );
     printf("\nAfter Insertion at first\n");
     display(head);
     printf("Enter the position at which you want to insert :");
     scanf("%d",&a);
     printf("Enter the node to be inserted:");
    scanf("%d",&ai);
    insertAt(a , ai,&head);
    printf("\nAfter Insertion of new node:\n");
     display(head);
     printf("Enter the node to be inserted at Last:");
    scanf("%d",&al);
    head = insertLast(head,al);
    printf("\nAfter Insertion at last\n");
    display(head);
    
    printf("_-_-_-_-_-_-_-_-DELETION-_-_-_-_-_-_-_-");
    
    head = deleteFirst(head);
     printf("\nAfter Delition at first\n");
     display(head);
     
    head = deleteLast(head);
    printf("\nAfter Deleted at last\n");
    display(head);
}
