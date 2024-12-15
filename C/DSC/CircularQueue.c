#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int q[MAX];
int front = -1;
int rear = -1;
int curr_size = 0;

int isEmpty() {
        return curr_size == 0;
}
int peek() {
        if(isEmpty()) {
                printf("Queue is Empty!");
        }
        return q[front];
}
void insert(int x) {
        if(curr_size == MAX) {
                printf("Queue is full!");
                return;
        }
        if(curr_size == 0) {
                front = 0;
                rear = 0;
        }
        else {
                rear = (rear + 1) % MAX;
        }
        q[rear] = x;
        curr_size++;
}
int pop() {
        if(isEmpty()) {
                printf("Queue is Empty!");
                return -1;
        }
        int popped = q[front];
        if(curr_size == 1) {
                front = -1;
                rear = -1;
        }
        else {
                front = (front + 1) % MAX;
        }
        curr_size--;
        return popped;
}

int main() {
        int op;
        printf("1.Insert\n2. Delete\n3.Display\n4.Exit\n");
        while(1) {
                printf("Enter your choice:- ");
                scanf("%d",&op);
                switch(op) {
                        case 1 :
                                int a;
                                printf("Enter a value:- ");
                                scanf("%d",&a);
                                insert(a);
                                break;
                        case 2 :
                                int popped = pop();
                                if(popped != -1) printf("The popped value from the queue is:- %d\n", popped);
                                break;
                        case 3 :
                                int val = peek();
                                if(val != -1) printf("The front value of the queue is:- %d\n", val);
                                break;
                        case 4 :
                                exit(0);
                        default :
                                printf("Invalid Choice! Try Again!");
                }
        }
}
