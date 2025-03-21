#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the Binary Search Tree
struct node {
    int key;
    struct node *left, *right;
};

// A utility function to create a new BST node
struct node* newNode(int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// A utility function to do inorder traversal of BST
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);  // Traverse left subtree
        printf("%d \n", root->key);  // Print the node
        inorder(root->right);  // Traverse right subtree
    }
}

/* A utility function to insert a new node with the given key in BST */
struct node* insert(struct node* node, int key) {
    // If the tree is empty, return a new node
    if (node == NULL)
        return newNode(key);

    // Otherwise, recur down the tree
    if (key < node->key)
        node->left = insert(node->left, key);  // Insert in the left subtree
    else if (key > node->key)
        node->right = insert(node->right, key);  // Insert in the right subtree

    // Return the (unchanged) node pointer
    return node;
}

// Driver code
int main() {
    struct node* root = NULL;  // Initialize the root of the tree as NULL

    // Insert nodes to form the following BST
    //              50
    //           /     \
    //          30      70
    //         /  \    /  \
    //       20   40  60   80
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Print inorder traversal of the BST
    printf("Inorder Traversal of BST:\n");
    inorder(root);

    return 0;
}

