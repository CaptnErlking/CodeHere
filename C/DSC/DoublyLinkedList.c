#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
        int data;
        struct Node * next;
        struct Node * prev;
} Node ;
Node * createnode(int data){
        Node * newnode = (Node*) malloc (sizeof(Node));
        newnode -> data = data;
        newnode -> next = NULL;
        newnode -> prev = NULL;
        return newnode;
}
Node * insertAtFront(Node * head, int data){
        Node * newnode = createnode(data);
        newnode -> next = head;
        if ( head != NULL ) head -> prev = newnode;
        head = newnode;
        return head;
}
Node * insertOnLeft(Node * head, int key, int data){
        Node * ptr = head;
        while (ptr!=NULL && ptr->data!=key) ptr = ptr->next;
        if(ptr == NULL){
                printf("Key not Found\n");
                return head;
        }
        Node * newnode = createnode(data);
        newnode -> next = ptr;
        newnode -> prev = ptr -> prev;
        if (ptr->prev!=NULL) ptr -> prev -> next = newnode;
        else head = newnode;
        ptr -> prev = newnode;
        return head;
}
Node * deleteNode(Node * head, int key){
        Node * ptr = head;
        while ( ptr!=NULL && ptr->data!=key ) ptr = ptr->next;
        if (ptr==NULL){
                printf("Node not found\n");
                return head;
        }
        if (ptr->prev!=NULL) ptr->prev->next = ptr->next;
        else head = ptr->next;
        if (ptr->next!=NULL) ptr->next->prev = ptr->prev;
        free (ptr);
        printf("Node with data %d DELETED\n",key);
        return head;
}
void display(Node * head){
        Node * ptr = head;
        if (head==NULL){
                printf("NULL\n");
                return;
        }
        printf("NULL <- ");
        while( ptr->next!=NULL){
                printf("%d <-> ",ptr->data);
                ptr = ptr->next;
        }
        printf("%d -> NULL",ptr->data);
        printf("\n");
}
int main() {
        Node *head = NULL;
        int choice, data, key;
        while (1) {
                printf("1. Insert at front\n2. Insert on left\n3. Delete node\n4. Display\n5. Exit\n");
                scanf("%d", &choice);
                switch (choice) {
                case 1:
                        printf("Enter data: ");
                        scanf("%d", &data);
                        head = insertAtFront(head, data);
                        break;
                case 2:
                        printf("Enter key: ");
                        scanf("%d" , & key);
                        printf("Enter data: ");
                        scanf("%d", &data);
                        head = insertOnLeft(head, key, data);
                        break;
                case 3:
                        printf("Enter key to delete: ");
                        scanf("%d", &key);
                        head = deleteNode(head, key);
                        break;
                case 4:
                        display(head);
                        break;
                case 5:
                        exit(0);
                default:
                        printf("Invalid choice\n");
                }
        }
        return 0;
}
