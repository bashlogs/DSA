#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node* insert_node(struct node* root, int data) {
    if (root == NULL) {
        return create_node(data);
    }
    if (data < root->data) {
        root->left = insert_node(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert_node(root->right, data);
    }
    return root;
}

struct node* delete_node(struct node* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = delete_node(root->left, data);
    }
    else if (data > root->data) {
        root->right = delete_node(root->right, data);
    }
    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = root->right;
        while (temp && temp->left != NULL) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }
    return root;
}

void inorder_traversal(struct node* root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

int height(struct node* head){
  if(head == NULL)
    return 0;
  else{
    int lheight = height(head->left);
    int rheight = height(head->right);
    if(lheight > rheight)
      return (lheight+1);
    else
      return (rheight+1);
  }
}

void printlevel(struct node* head, int n, int space){
  if(head == NULL){
    return;
  }
  if(n == 1){
    for(int i=0;i<space;i++){
      printf(" ");
    }
    printf("%d\t",head->data);
    return;
  }
  printlevel(head->left, n-1, space-n);
  printlevel(head->right, n-1, space-n);
}


void display(struct node* root){
  if(root == NULL)
    return;
  else{
    for(int i=1;i<=height(root);i++){
      int a=15-i*2;
      printf("Level %d: ",i);
      printlevel(root, i, a);
      printf("\n");
    }
  }
  printf("\n");
}



int main() {
    struct node* root = NULL;
    root = insert_node(root, 50);
    insert_node(root, 30);
    insert_node(root, 20);
    insert_node(root, 40);
    insert_node(root, 70);
    insert_node(root, 60);
    insert_node(root, 80);
    printf("Inorder traversal of the binary tree: ");
    inorder_traversal(root);
    printf("\nDeleting node 20 from the binary tree.\n");
    root = delete_node(root, 20);
    printf("Inorder traversal of the binary tree: ");
    inorder_traversal(root);
    
    printf("\nDisplay\n");
    display(root);

    return 0;
}

/*
        50
       /  \
     30    70
    /  \   / \
  20   40 60  80


After deleting 20 
        50
       /  \
     30    70
       \   / \
       40 60  80


*/
