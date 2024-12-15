#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
        int data;
        struct Node *next;
} Node;

Node *createLinkedList(int n) {
        Node *start = NULL, *temp, *newnode;
        int data, i;
        for (i = 0; i < n; i++) {
                newnode = (Node *)malloc(sizeof(Node));
                printf("Enter data for node %d: ", i + 1);
                scanf("%d", &data);
                newnode->data = data;
                newnode->next = NULL;
                if (start == NULL) {
                        start = newnode;
                        temp = start;
                } else {
                        temp->next = newnode;
                        temp = temp->next;
                }
        }
        temp->next = start;
        return start;
}

Node *insertAtStart(Node *start, int data) {
        Node *newnode = (Node *)malloc(sizeof(Node));
        newnode->data = data;
        if (start == NULL) {
                newnode->next = newnode;
                return newnode;
        }
        Node *ptr = start;
        while (ptr->next != start) {
                ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->next = start;
        return newnode;
}

Node *insertAtEnd(Node *start, int data) {
        Node *newnode = (Node *)malloc(sizeof(Node));
        newnode->data = data;
        if (start == NULL) {
                newnode->next = newnode;
                return newnode;
        }
        Node *ptr = start;
        while (ptr->next != start) {
                ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->next = start;
        return start;
}

Node *deleteFromStart(Node *start) {
        if (start == NULL) {
                printf("List is empty\n");
                return NULL;
        }
        Node *ptr = start;
        while (ptr->next != start) {
                ptr = ptr->next;
        }
        if (ptr == start) {
                free(start);
                return NULL;
        }
        Node *temp = start;
        ptr->next = start->next;
        start = start->next;
        free(temp);
        return start;
}

Node *deleteFromEnd(Node *start) {
        if (start == NULL) {
                printf("List is empty\n");
                return NULL;
        }
        Node *ptr = start;
        Node *prev = NULL;
        while (ptr->next != start) {
                prev = ptr;
                ptr = ptr->next;
        }
        if (ptr == start) {
                free(start);
                return NULL;
        }
        prev->next = start;
        free(ptr);
        return start;
}

void display(Node *start) {
        if (start == NULL) {
                printf("List is empty\n");
                return;
        }
        Node *ptr = start;
        do {
                printf("%d ", ptr->data);
                ptr = ptr->next;
        } while (ptr != start);
        printf("\n");
}

int main() {
        int n;
        printf("Enter the number of nodes: ");
        scanf("%d", &n);
        Node *start = createLinkedList(n);
        display(start);

        int atBegin;
        printf("What do you want to insert at the start: ");
        scanf("%d", &atBegin);
        start = insertAtStart(start, atBegin);
        display(start);

        int atEnd;
        printf("What do you want to insert at the end: ");
        scanf("%d", &atEnd);
        start = insertAtEnd(start, atEnd);
        display(start);

        printf("Deleting from the start: \n");
        start = deleteFromStart(start);
        display(start);

        printf("Deleting from the end: \n");
        start = deleteFromEnd(start);
        display(start);

        return 0;
}
