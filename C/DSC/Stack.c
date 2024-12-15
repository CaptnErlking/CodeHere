#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int stack[MAX];
int top = -1;
void push(int x){
        if(top<MAX-1) stack[++top]=x;
        else printf("Stack Overflow\n");
}
void pop(){
        if(top>=0) top--;
        else printf("Stack Underflow\n");
}
void display(){
        for (int i=top; i>=0; i--) printf("%d\n",stack[i]);
}
int main(){
        int c,x;
        printf("Options:\n1.Push\n2.Pop\n3.OverFlow & Underflow\n4.Status\n5.Exit\n");
        while(1){
                printf(": ");
                scanf("%d",&c);
                switch(c){
                        case 1:
                                printf("Push : ");
                                scanf("%d",&x);
                                push(x);
                                break;
                        case 2:
                                pop();
                                break;
                        case 3:
                                printf("You can push %d elements before Overflow\n",MAX-top-1);
                                printf("You can pop %d elements before Underflow\n",top+1);
                                break;
                        case 4:
                                display();
                                break;
                        case 5:
                                exit(0);
                        default:
                                printf("Invalid Choice\n");
                }
        }
}
