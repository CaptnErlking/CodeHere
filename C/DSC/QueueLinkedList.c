#include <stdio.h>
#include <stdlib.h>
struct Node {
        int data;
        struct Node *next;
};
struct Node *front = NULL;
struct Node *rear = NULL;
void insert(int value) {
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        if (front == NULL) {
                front = rear = newNode;
                rear->next = front;
        }
        else {
                rear->next = newNode;
                rear = newNode;
                rear->next = front;
        }
        printf("%d inserted into the queue.\n", value);
}
void delete() {
        if (front == NULL) {
                printf("Queue is empty!\n");
        }
        else if (front == rear) {
                printf("Element %d removed from the queue.\n", front->data);
                free(front);
                front = rear = NULL;
        }
        else {
                struct Node *temp = front;
                printf("Element %d removed from the queue.\n", temp->data);
                front = front->next;
                rear->next = front;
                free(temp);
        }
}
void display() {
        if (front == NULL) {
                printf("Queue is empty!\n");
        }
        else {
                struct Node *temp = front;
                printf("Queue elements are:\n");
                while (temp->next != front) {
                        printf("%d ", temp->data);
                        temp = temp->next;
                }
                printf("%d\n", temp->data);
        }
}
int main() {
        int choice, value;
        while(1) {
                printf("\nCircular Queue Operations:\n");
                printf("1. Insert\n");
                printf("2. Delete\n");
                printf("3. Display\n");
                printf("4. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                switch(choice) {
                        case 1:
                                printf("Enter the value to be inserted: ");
                                scanf("%d", &value);
                                insert(value);
                                break;
                        case 2:
                                delete();
                                break;
                        case 3:
                                display();
                                break;
                        case 4:
                                return 0;
                        default:
                                printf("Invalid choice, please try again.\n");
                }
        }
}
