#include <stdio.h>
#include <stdlib.h>
#define RED 1
#define BLACK 0
struct RBNode {
    int key;
    int color;
    struct RBNode *left;
    struct RBNode *right;
    struct RBNode *parent;
};
struct RBNode *treeRoot = NULL;
struct RBNode* newRBNode(int value) {
    struct RBNode *temp = (struct RBNode*)malloc(sizeof(struct RBNode));
    temp->key = value;
    temp->color = RED;       
    temp->left = NULL;
    temp->right = NULL;
    temp->parent = NULL;

    return temp;
}
void rotateLeft(struct RBNode *node) {
    struct RBNode *child = node->right;
    node->right = child->left;
    if(child->left != NULL)
        child->left->parent = node;
    child->parent = node->parent;
    if(node->parent == NULL)
        treeRoot = child;
    else if(node == node->parent->left)
        node->parent->left = child;
    else
        node->parent->right = child;
    child->left = node;
    node->parent = child;
}
void rotateRight(struct RBNode *node) {
    struct RBNode *child = node->left;
    node->left = child->right;
    if(child->right != NULL)
        child->right->parent = node;
    child->parent = node->parent;
    if(node->parent == NULL)
        treeRoot = child;
    else if(node == node->parent->left)
        node->parent->left = child;
    else
        node->parent->right = child;
    child->right = node;
    node->parent = child;
}
void balanceTree(struct RBNode *node) {
    while(node != treeRoot && node->parent->color == RED) {
        if(node->parent == node->parent->parent->left) {
            struct RBNode *uncle = node->parent->parent->right;
            if(uncle != NULL && uncle->color == RED) {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            }
            else {
                if(node == node->parent->right) {
                    node = node->parent;
                    rotateLeft(node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                rotateRight(node->parent->parent);
            }
        }
        else {
            struct RBNode *uncle = node->parent->parent->left;
            if(uncle != NULL && uncle->color == RED) {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            }
            else {
                if(node == node->parent->left) {
                    node = node->parent;
                    rotateRight(node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                rotateLeft(node->parent->parent);
            }
        }
    }
    treeRoot->color = BLACK;
}
void addNode(int value) {
    struct RBNode *newNode = newRBNode(value);
    struct RBNode *parent = NULL;
    struct RBNode *current = treeRoot;
    while(current != NULL) {
        parent = current;
        if(value < current->key)
            current = current->left;
        else
            current = current->right;
    }
    newNode->parent = parent;
    if(parent == NULL)
        treeRoot = newNode;
    else if(value < parent->key)
        parent->left = newNode;
    else
        parent->right = newNode;
    balanceTree(newNode);
}
void displayInorder(struct RBNode *node) {
    if(node != NULL) {
        displayInorder(node->left);
        printf("%d(%c) ", node->key,
               node->color == RED ? 'R' : 'B');
        displayInorder(node->right);
    }
}
int main() {
    int values[] = {157, 110, 147, 122, 111, 149, 151, 141, 123, 112, 117, 133};
    int n = sizeof(values) / sizeof(values[0]);
    for(int i = 0; i < n; i++)
        addNode(values[i]);
    printf("Inorder Traversal of Red-Black Tree:\n");
    displayInorder(treeRoot);
    return 0;
}
