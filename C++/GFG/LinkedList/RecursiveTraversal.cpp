#include <iostream>
using namespace std; 

struct Node {
    int data; 
    Node * next; 
    Node (int x) {
        data = x; 
        next = NULL; 
    }
}; 

void RecursiveTraversal(Node * head) {
    if (head == NULL) {
        return; 
    }
    cout << head -> data << " " ; 
    RecursiveTraversal(head -> next); 
}

Node * Insert (Node * head) {
    int x; 
    cin >> x; 
    Node * ptr = new Node (x); 
    ptr -> next = head; 
    return ptr; 
}

int main () {
    int n; 
    cout << "Enter the number of Nodes : " ; 
    cin >> n; 
    cout << "Enter the Nodes : " << endl; 
    Node * head = NULL; 
    for (int i=0; i<n; i++) {
        head = Insert(head); 
    }
    RecursiveTraversal(head); 
    cout << endl; 
}
