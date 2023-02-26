#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to perform Inorder Traversal
void inorderTraversal(struct Node* root) {
    struct Node* current = root;
    struct Node* stack[100];
    int top = -1;
    while (current != NULL || top >= 0) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

// Function to perform Preorder Traversal
void preorderTraversal(struct Node* root) {
    struct Node* current = root;
    struct Node* stack[100];
    int top = -1;
    while (current != NULL || top >= 0) {
        while (current != NULL) {
            printf("%d ", current->data);
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        current = current->right;
    }
}

// Function to display the number of leaf nodes
int countLeafNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    int count = 0;
    struct Node* stack[100];
    int top = -1;
    stack[++top] = root;
    while (top >= 0) {
        struct Node* current = stack[top--];
        if (current->left == NULL && current->right == NULL)
            count++;
        if (current->right != NULL)
            stack[++top] = current->right;
        if (current->left != NULL)
            stack[++top] = current->left;
    }
    return count;
}

// Function to create the mirror image of the binary tree
void mirrorImage(struct Node* root) {
    if (root == NULL)
        return;
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirrorImage(root->left);
    mirrorImage(root->right);
}

int countNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    int count = 0;
    struct Node* stack[100];
    int top = -1;
    stack[++top] = root;
    while (top >= 0) {
        struct Node* current = stack[top--];
        count++;
        if (current->right != NULL)
            stack[++top] = current->right;
        if (current->left != NULL)
            stack[++top] = current->left;
    }
    return count;
}

// Function to calculate the height of the binary tree
int getHeight(struct Node* root) {
    if (root == NULL)
        return 0;
    int height = 0;
    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        int size = rear - front;
        while (size--) {
            struct Node* current = queue[front++];
            if (current->left != NULL)
                queue[rear++] = current->left;
            if (current->right != NULL)
                queue[rear++] = current->right;
        }
        height++;
    }
    return height;
}

// Function to perform postorder traversal
void postorderTraversal(struct Node* root) {
    struct Node* current = root;
    struct Node* stack[100];
    int top = -1;
    struct Node* prev = NULL;
    do {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        while (current == NULL && top >= 0) {
            current = stack[top];
            if (current->right == NULL || current->right == prev) {
                printf("%d ", current->data);
                top--;
                prev = current;
                current = NULL;
            } else {
                current = current->right;
            }
        }
    } while (top >= 0);
}

void levelOrder(struct Node* root) {
    if (root == NULL)
        return;
    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        int size = rear - front;
        while (size--) {
            struct Node* current = queue[front++];
            printf("%d ", current->data);
            if (current->left != NULL)
                queue[rear++] = current->left;
            if (current->right != NULL)
                queue[rear++] = current->right;
        }
        printf("\n");
    }
}

int findMax(struct Node* root) {
    if (root == NULL)
        return -1; // Return -1 (or any other appropriate value) if the tree is empty
    int max = root->data;
    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        struct Node* current = queue[front++];
        if (current->data > max) {
            max = current->data;
        }
        if (current->left != NULL)
            queue[rear++] = current->left;
        if (current->right != NULL)
            queue[rear++] = current->right;
    }
    return max;  // Return the largest element found
}



int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Number of Leaf Nodes: %d\n", countLeafNodes(root));

    mirrorImage(root);
    printf("Mirror Image: ");
    inorderTraversal(root);
    printf("\n");

    printf("Level order non recursion" );
    levelOrder(root);
    
    printf("\nmax %d\n", findMax(root));
    return 0;
}

