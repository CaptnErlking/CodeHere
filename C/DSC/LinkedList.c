#include <stdio.h>
#include <stdlib.h>

struct Node {
        int data;
        struct Node *next;
};
struct Node *createLinkedList(int n) {
        struct Node *start = NULL, *temp, *newnode;
        int data, i;
        for (i = 0; i < n; i++) {
                newnode = (struct Node *)malloc(sizeof(struct Node));
                printf("Enter data for node %d: ", i + 1);
                scanf("%d", &data);
                newnode->data = data;
                newnode->next = NULL;
                if (start == NULL) {
                    start = newnode;
                    temp = start;
                }
                else {
                    temp->next = newnode;
                    temp = temp->next;
                }
        }
        return start;
        }
        struct Node *insertAtStart(struct Node *start, int data) {
        struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
        newnode->data = data;
        newnode->next = start;
        start = newnode;
        return start;
}

struct Node *insertAtPos(struct Node *start, int data, int pos) {
        struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
        newnode->data = data;
        if (start == NULL && pos > 1) {
                printf("Invalid position\n");
                return start;
        }
        else if (start == NULL && pos == 1) {
                newnode->next = NULL;
                start = newnode;
                return start;
        }
        struct Node *ptr = start, *temp;
        int count = 1;
        while (ptr != NULL && count < pos) {
                temp = ptr;
                ptr = ptr->next;
                count++;
        }
        if (count < pos) {
                printf("Invalid position\n");
                free(newnode);
                return start;
        }
        temp->next = newnode;
        newnode->next = ptr;
        return start;
}
struct Node *deleteAtPos(struct Node *start, int pos) {
        if (start == NULL && pos >= 1) {
                printf("Invalid Position\n");
                return start;
        }
            struct Node *ptr = start, *temp;
            int count = 1;
            if (pos == 1) {
                start = ptr->next;
                free(ptr);
                return start;
        }
        while (ptr != NULL && count < pos) {
                temp = ptr;
                ptr = ptr->next;
                count++;
        }
        if (ptr == NULL || count < pos) {
                printf("Invalid Position\n");
                return start;
        }
        temp->next = ptr->next;
        free(ptr);
        return start;
}

struct Node *search(struct Node *start, int key) {
        struct Node *ptr = start;
        int count = 1;
        while (ptr != NULL && ptr->data != key) {
                ptr = ptr->next;
                count++;
        }
        if (ptr == NULL) {
                printf("Not found\n");
        }
        else {
                printf("It was found at %d\n", count);
        }
        return start;
}
void display(struct Node *start) {
        struct Node *ptr = start;
        while (ptr != NULL) {
                printf("%d ", ptr->data);
                ptr = ptr->next;
        }
        printf("\n");
}
int main() {
        struct Node *start = NULL;
        int choice, data, pos, n;
        printf("Enter the number of nodes to create: ");
        scanf("%d", &n);
        start = createLinkedList(n);
        while (1) {
                printf("1. Insert at start\n2. Insert at position\n3. Delete at position\n4. Search\n5. Display\n6. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                switch (choice) {
                        case 1:
                        printf("Enter data: ");
                        scanf("%d", &data);
                        start = insertAtStart(start, data);
                        display(start);
                        break;
                case 2:
                        printf("Enter data and position: ");
                        scanf("%d %d", &data, &pos);
                        start = insertAtPos(start, data, pos);
                        display(start);
                        break;
                case 3:
                        printf("Enter position: ");
                        scanf("%d", &pos);
                        start = deleteAtPos(start, pos);
                        display(start);
                        break;
                case 4:
                        printf("Enter key to search: ");
                        scanf("%d", &data);
                        start = search(start, data);
                        display(start);
                        break;
                case 5:
                        display(start);
                        break;
                case 6:
                        exit(0);
                default:
                        printf("Invalid choice\n");
                }
        }
        return 0;
}
