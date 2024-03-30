#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new tree node
struct Node* newNode(char data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}


void inorder_find_data(struct Node* root, char d, char l, char r) {
    if (root != NULL) {
        inorder_find_data(root->left, d, l, r);
        if (root->data == d){
            if (l != '.') {
                struct Node* left_node = newNode(l);
                root->left = left_node;
            }
            if (r != '.') {
                struct Node* right_node = newNode(r);
                root->right = right_node;
            }
        }
        inorder_find_data(root->right, d, l, r);
    }
}

void preorder(struct Node* root){
    if (root != NULL) {
        printf("%c", root->data);  // Visit 
        preorder(root->left);
        preorder(root->right);
    }
}

// Function to perform inorder traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%c", root->data);  // Visit 
        inorder(root->right);
    }
}

void postorder(struct Node* root){
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->data);  // Visit 
    }
}

int main() {
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->data = 0;
    root->left = root->right = NULL;

    int n=0;
    char p,l,r;

    scanf("%d",&n);
    getchar();

    for (int i=0;i<n;i++){
        scanf("%c %c %c",&p,&l,&r);
        getchar();    
        if (i==0){
            root->data = p;
        }        
        inorder_find_data(root, p, l, r);

    }


    //printf("preorder Traversal: ");
    preorder(root);
    printf("\n");
    //printf("inorder Traversal: ");
    inorder(root);
    printf("\n");
    //printf("postorder Traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}