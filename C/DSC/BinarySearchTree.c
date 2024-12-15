#include<stdio.h>
#include<stdlib.h>

struct node {
        int data;
        struct node * left;
        struct node * right;
};

struct node * newnode (int data) {
        struct node * nn = (struct node *) malloc (sizeof(struct node));
        nn -> data = data;
        nn -> left = NULL;
        nn -> right = NULL;
        return nn;
}

struct node * insert (struct node * root, int data) {
        if (root == NULL) {
                return newnode(data);
        }
        else if (data < root -> data) {
                root -> left = insert(root->left, data);
        }
        else {
                root -> right = insert(root->right, data);
        }
        return root;
}

void inorder (struct node * root) {
        if (root != NULL) {
                inorder(root -> left);
                printf("%d ", root -> data);
                inorder(root -> right);
        }
}

void preorder (struct node * root) {
        if (root != NULL) {
                printf("%d ", root -> data);
                preorder(root -> left);
                preorder(root -> right);
        }
}

void postorder (struct node * root) {
        if (root != NULL) {
                postorder(root -> left);
                postorder(root -> right);
                printf("%d ", root -> data);
        }
}

int countLeafs (struct node * root) {
        if (root == NULL) {
                return 0;
        }
        else if (root -> left == NULL && root -> right == NULL) {
                return 1;
        }
        else {
                return countLeafs(root -> left) + countLeafs(root -> right);
        }
}

void printPaths(struct node *node, char *path) {
        if (node == NULL) return;
        char newPath[100];
        if (path[0] == '\0') {
                sprintf(newPath, "%d", node->data);
        } else {
                sprintf(newPath, "%s -> %d", path, node->data);
        }
        if (node->left == NULL && node->right == NULL) {
                printf("%s\n", newPath);
        } else {
                printPaths(node->left, newPath);
                printPaths(node->right, newPath);
        }
}

int main() {
        int n, x;
        struct node * root = NULL;
        printf("!! Binary Search Tree !!");
        printf("\n How many elements do you want to enter : ");
        scanf("%d", &n);
        printf("Enter the elements : \n");
        for (int i=0; i<n; i++) {
                scanf("%d", &x);
                root = insert(root, x);
        }
        printf("\nINORDER TRAVERSAL\n");
        inorder(root);
        printf("\nPREORDER TAVERSAL\n");
        preorder(root);
        printf("\nPOSTORDER TRAVERSAL\n");
        postorder(root);
        printf("\nHere are the number of leaf Node in this BST : %d", countLeafs(root));
        printf("\nHere are all the paths from Root to Leaf : \n");
        printPaths(root, "");
        printf("\n\n");

}
