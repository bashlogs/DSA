#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *left, *right;
};
struct node *createnode(int key)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->info = key;
    newnode->left = NULL;
    newnode->right = NULL;
    return(newnode);
}
void inorder(struct node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf(" %d ",root->info);
        inorder(root->right);
    }
}
void smallest(struct node *root)
{
    while(root != NULL && root->left != NULL)
    {
        root = root->left;
    }
    printf("\nSmallest value is %d\n", root->info);
}
void largest(struct node *root)
{
    while (root != NULL && root->right != NULL)
    {
        root = root->right;
    }
    printf("\nLargest value is %d", root->info);
}

int main()
{

    struct node *newnode = createnode(25);
    newnode->left = createnode(17);
    newnode->right = createnode(35);
    newnode->left->left = createnode(13);
    newnode->left->right = createnode(19);
    newnode->right->left = createnode(27);
    newnode->right->right = createnode(55);

    printf("Inorder traversal of tree 1 :");
    inorder(newnode);
    largest(newnode);
    smallest(newnode);
    
    struct node *node = createnode(1);
    node->right = createnode(2);
    node->right->right = createnode(3);
    node->right->right->right = createnode(4);
    node->right->right->right->right = createnode(5);

    printf("\nInorder traversal of tree 2 :");
    inorder(node);
    largest(node);
    smallest(node);
    struct node *root = createnode(15);
    printf("\nInorder traversal of tree 3 :");
    inorder(root);
    largest(root);
    smallest(root);
    return 0;
}