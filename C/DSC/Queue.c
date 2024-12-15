#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX], front = -1, rear = -1;

void insert(int n) {
        if (rear==MAX-1) {
                printf("Queue is Full!!\n");
                return;
        }
        else if (front == -1 && rear == -1) {
                front = rear = 0;
        }
        else rear++;
        queue[rear] = n;
}
void  pop() {
        if (front == -1 || front > rear) {
                printf("Queue is Empty\n");
                return;
        }
        printf("You just popped : %d\n", queue[front++]);
        return ;
}
void display() {
        int it = front;
        if (it == -1) {
                printf("Empty\n");
                return;
        }
        while (it  <= rear)
                printf("%d ", queue[it++]);
        printf("\n");
}
int main() {
        printf("Here is the Implementation of Queue: \n");
        int c, x;
        printf("Options :\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        while (1) {
                scanf("%d", &c);
                switch(c) {
                        case 1:
                                printf("Insert : ");
                                scanf("%d", &x);
                                insert(x);
                                break;
                        case 2:
                                pop();
                                break;
                        case 3:
                                printf("Queue :\n");
                                display();
                                break;
                        case 4:
                                exit(0);
                        default :
                                printf("Invalid Choice :/\n");
                }
        }
}
