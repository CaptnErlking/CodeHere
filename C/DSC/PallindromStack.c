#include<stdio.h>
#include<string.h>
#define MAX 20
int stack[MAX];
int top = -1;
char str[MAX];
char revstr[MAX];
void push(char c){
        if (top<MAX-1) stack[++top]=c;
        else printf("Stack Overflow\n");
}
char pop(){
        if (top>=0) return stack[top--];
        else printf("Stack Underflow\n");
}
int main(){
        printf("Enter a string : ");
        scanf("%s",&str);
        int n = strlen(str);
        for (int i=0; i<n; i++) printf("%c", str[i]); printf("\n");
        for (int i=0; i<n; i++) push(str[i]);
        for (int i=0; i<n; i++) revstr[i] = pop(); revstr[n]='\0';
        if (strcmp(str,revstr)==0) printf("Pallindrome\n");
        else printf("Not Pallindrome\n");
}
