#include <stdio.h>
#include <stdlib.h>

/* Defining the structure Node*/
struct Node
{
    int data;
    struct Node *next;
};

/* Insert in the beginning by push */
void push(struct Node** head_ref,int new_data) // for head_ref, we need 2 pointers, pointing to a pointer
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); //dynamic allocation
    new_node -> data = new_data; // new node's data is the new_data
    new_node -> next = (*head_ref); // the next of the new node will be the head because it is before the head
    (*head_ref) = new_node; // at the position of the head_ref, a new_node will be put
}

/*Insert after a given node*/
void insertAfter(struct Node* prev_node, int new_data)
{
    if(prev_node == NULL)
    {
        printf("The previous node cannot be null\n");
        return;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); //dynamic allocation
    new_node -> data = new_data;
    new_node -> next = prev_node -> next;
    prev_node -> next = new_node; // this is because the new node if created will be put at the next of the previous node
}

/*Insert at the end*/
void append(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node *last = *head_ref;
    new_node -> data = new_data;
    new_node -> next = NULL;
    
    if(*head_ref == NULL) // if the Linked List is empty
    {
        *head_ref = new_node; // head referrence is assigned the value of new node
        return;
    }
    
    while(last->next!=NULL) // if Linked list is not empty
    {
        last = last -> next; // keep updating the last with the last -> next
    }
    
    last -> next = new_node; // when the pointer reaches the last, then put the new node there
    return;
}

void printList(struct Node *node)
{
    while(node!=NULL) // as long as the last is not reached
    {
        printf(" %d",node -> data); // print the data of the nodes
        node = node -> next; // and keep updating the node with the next of the node.
        
    }
}

int main()
{
    struct Node* head = NULL;  // initialize the head to NULL to avoid any garbage value in the code
    push(&head,5);
    
    append(&head,7);
    
    insertAfter(head->next,9);
    
    
    printf("The Linked List is\n");
    printList(head);
    /*expected output :  5 --> 7 --> 9*/
    return 0;
}