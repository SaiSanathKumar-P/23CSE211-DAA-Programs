#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* Structure for a Huffman Tree Node */
struct HuffNode {
    char ch;
    int freq;
    struct HuffNode *left;
    struct HuffNode *right;
};

/* Structure for Min Heap */
struct Heap {
    int size;
    struct HuffNode *data[MAX];
};

/* Function to create a new node */
struct HuffNode* createNode(char ch, int freq) {
    struct HuffNode *node = (struct HuffNode*)malloc(sizeof(struct HuffNode));

    node->ch = ch;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;

    return node;
}

/* Swap two nodes */
void swapNodes(struct HuffNode **a, struct HuffNode **b) {
    struct HuffNode *temp = *a;
    *a = *b;
    *b = temp;
}

/* Heapify function to maintain min heap */
void heapify(struct Heap *heap, int i) {

    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < heap->size && heap->data[left]->freq < heap->data[smallest]->freq)
        smallest = left;

    if (right < heap->size && heap->data[right]->freq < heap->data[smallest]->freq)
        smallest = right;

    if (smallest != i) {
        swapNodes(&heap->data[i], &heap->data[smallest]);
        heapify(heap, smallest);
    }
}

/* Remove the smallest node from heap */
struct HuffNode* getMin(struct Heap *heap) {

    struct HuffNode *temp = heap->data[0];

    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;

    heapify(heap, 0);

    return temp;
}

/* Insert a node into heap */
void insertHeap(struct Heap *heap, struct HuffNode *node) {

    int i = heap->size;
    heap->size++;

    while (i > 0 && node->freq < heap->data[(i-1)/2]->freq) {
        heap->data[i] = heap->data[(i-1)/2];
        i = (i-1)/2;
    }

    heap->data[i] = node;
}

/* Function to build Huffman Tree */
struct HuffNode* buildHuffmanTree(char letters[], int freq[], int n) {

    struct Heap heap;
    heap.size = 0;

    /* Create initial heap nodes */
    for (int i = 0; i < n; i++) {
        heap.data[heap.size++] = createNode(letters[i], freq[i]);
    }

    /* Build the min heap */
    for (int i = (heap.size/2) - 1; i >= 0; i--) {
        heapify(&heap, i);
    }

    /* Repeat until only one node remains */
    while (heap.size > 1) {

        struct HuffNode *left = getMin(&heap);
        struct HuffNode *right = getMin(&heap);

        struct HuffNode *parent = createNode('*', left->freq + right->freq);

        parent->left = left;
        parent->right = right;

        insertHeap(&heap, parent);
    }

    return getMin(&heap);
}

/* Function to print Huffman Codes */
void printCodes(struct HuffNode *root, int code[], int top) {

    if (root->left) {
        code[top] = 0;
        printCodes(root->left, code, top + 1);
    }

    if (root->right) {
        code[top] = 1;
        printCodes(root->right, code, top + 1);
    }

    /* Leaf node means character found */
    if (!root->left && !root->right) {

        printf("%c : ", root->ch);

        for (int i = 0; i < top; i++)
            printf("%d", code[i]);

        printf("\n");
    }
}

/* Main function */
int main() {

    char chars[] = {'A','B','C','D','E','F'};
    int freq[] = {5,9,12,13,16,45};

    int n = sizeof(chars)/sizeof(chars[0]);

    struct HuffNode *root = buildHuffmanTree(chars, freq, n);

    int code[MAX];
    int top = 0;

    printf("Huffman Codes:\n");

    printCodes(root, code, top);

    return 0;
}
