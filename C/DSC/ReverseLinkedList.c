#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
        int data;
        struct Node * next;
}Node;
Node * createLinkedList(int n){
        struct Node * start = NULL, *temp, *newnode;
        int data;
        for (int i=0; i<n; i++){
                Node * newnode = (Node *)malloc(sizeof(struct Node)) ;
                printf(": ");
                scanf("%d", &data);
                newnode->data=data;
                newnode->next=NULL;
                if (start==NULL){
                        start=newnode;
                        temp=start;
                } else {
                        temp->next=newnode;
                        temp=temp->next;
                }
        } return start;
}
Node * reverseLinkedList(Node * start){
        Node * prev = NULL;
        Node * ptr = start;
        while(ptr!=NULL){
                Node * temp = ptr->next;
                ptr->next = prev;
                prev = ptr;
                ptr = temp;
        }
        return prev;
}
void display (Node * start){
        Node * ptr = start;
        while (ptr!=NULL){
                printf("%d ", ptr->data);
                ptr = ptr->next;
        }
        printf("\n");
}
int main() {
        printf("Enter the size of LinkedList : ");
        int n ;
        scanf("%d", &n);
        Node * head = createLinkedList(n);
        display(head);
        head = reverseLinkedList(head);
        display(head);
        return 0;
}
