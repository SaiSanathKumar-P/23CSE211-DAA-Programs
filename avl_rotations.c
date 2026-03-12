#include <stdio.h>
#include <stdlib.h>
/* ----------- sAVL TREE NODE ----------- */
struct AVLNode {
    int value;
    int h;
    struct AVLNode *leftChild;
    struct AVLNode *rightChild;
};
int findMax(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}
int getHeight(struct AVLNode *node) {
    if (node == NULL)
        return 0;
    return node->h;
}
struct AVLNode* createAVLNode(int val) {
    struct AVLNode *temp = (struct AVLNode*)malloc(sizeof(struct AVLNode));
    temp->value = val;
    temp->leftChild = NULL;
    temp->rightChild = NULL;
    temp->h = 1;
    return temp;
}
struct AVLNode* rotateRight(struct AVLNode *y) {
    struct AVLNode *x = y->leftChild;
    struct AVLNode *temp = x->rightChild;
    x->rightChild = y;
    y->leftChild = temp;
    y->h = findMax(getHeight(y->leftChild), getHeight(y->rightChild)) + 1;
    x->h = findMax(getHeight(x->leftChild), getHeight(x->rightChild)) + 1;
    return x;
}
struct AVLNode* rotateLeft(struct AVLNode *x) {
    struct AVLNode *y = x->rightChild;
    struct AVLNode *temp = y->leftChild;
    y->leftChild = x;
    x->rightChild = temp;
    x->h = findMax(getHeight(x->leftChild), getHeight(x->rightChild)) + 1;
    y->h = findMax(getHeight(y->leftChild), getHeight(y->rightChild)) + 1;
    return y;
}
int balanceFactor(struct AVLNode *node) {
    if (node == NULL)
        return 0;
    return getHeight(node->leftChild) - getHeight(node->rightChild);
}
struct AVLNode* insertNode(struct AVLNode *root, int val) {
    if (root == NULL)
        return createAVLNode(val);
    if (val < root->value)
        root->leftChild = insertNode(root->leftChild, val);
    else if (val > root->value)
        root->rightChild = insertNode(root->rightChild, val);
    else
        return root;
    root->h = 1 + findMax(getHeight(root->leftChild), getHeight(root->rightChild));
    int balance = balanceFactor(root);
    if (balance > 1 && val < root->leftChild->value)
        return rotateRight(root);
    if (balance < -1 && val > root->rightChild->value)
        return rotateLeft(root);
    if (balance > 1 && val > root->leftChild->value) {
        root->leftChild = rotateLeft(root->leftChild);
        return rotateRight(root);
    }
    if (balance < -1 && val < root->rightChild->value) {
        root->rightChild = rotateRight(root->rightChild);
        return rotateLeft(root);
    }
    return root;
}
void printInorder(struct AVLNode *root) {
    if (root != NULL) {
        printInorder(root->leftChild);
        printf("%d ", root->value);
        printInorder(root->rightChild);
    }
}
int main() {
    struct AVLNode *root = NULL;
    int values[] = {157, 110, 147, 122, 111, 149, 151, 141, 123, 112, 117, 133};
    int n = sizeof(values) / sizeof(values[0]);
    for (int i = 0; i < n; i++)
        root = insertNode(root, values[i]);
    printf("Inorder Traversal of AVL Tree:\n");
    printInorder(root);
    return 0;
}
