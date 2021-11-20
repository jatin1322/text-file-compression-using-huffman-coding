#include <stdio.h>
#include <stdlib.h>

#define MAXIMUM_TREE_HT 100 

struct LL_node // Designing A Linked List to store the formed encoded bits of each corresponding character
{
    int data;             // Single bit either 0 or 1
    struct LL_node *next; // next node pointing to next bit
};
// Insert function to insert data in the node
struct LL_node *insert(struct LL_node *head, int x)
{
    struct LL_node *newnode = (struct LL_node *)malloc(sizeof(struct LL_node)); // dynamically allocating a newnode
    newnode->data = x;                                                          // Updating its data value  to x
    newnode->next = NULL;                                                       // And updating its next pointer to NULL
    // If head pointer is NULL then simply eqaute head to newnode and return the head
    if (head == NULL)
    {
        head = newnode;
        return head;
    }
    else // Else we want to add value x to the tail of our linked list
    {
        struct LL_node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next; // Therfore we travel till the the end
        }
        temp->next = newnode; // And there add our newnode
        return head;          // And return the head value
    }
}
// Print Function to print a Linked List
void print_LL(struct LL_node *head)
{
    struct LL_node *temp = head;
    while (temp != NULL) // To traverse the whole list and printing the data
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
    return;
}

// Globalyy Declaring an array of head pointers of size 0-127 (the ascii value of respective
// characters) and each charater is pointing to its encoded bit code
struct LL_node *encoded_code[128] = {0}; // Initiating all pointers to NULL


struct HuffmannTreenode // Basically declaring structure of a Minheap node for huffmann tree
{
    char data; // Charcater in the node

    unsigned freq; // Frequency of the corresponding character

    struct HuffmannTreenode *left, *right; // Leaft and Right Child of the node
};

struct HuffmannTree // Basically it is a collection of all huffmanntree nodes or minheap nodes
{

    unsigned size; // Corresponding to current size value of our collection of nodes

    unsigned capacity; // Corresponding to current capacity limit value of our collection of nodes

    struct HuffmannTreenode **array; // Array of huffmann tree node pointers
};

// Function to create a new huffmann tree node of given character data and its frequency value
struct HuffmannTreenode *newNode(char data, unsigned freq)
{
    struct HuffmannTreenode *temp = (struct HuffmannTreenode *)malloc(
        sizeof(struct HuffmannTreenode)); // Dynamically allocation of temp node of huffmann tree node type

    temp->left = temp->right = NULL; // Initiating its left and right node pointers to avoid garbage values
    temp->data = data;               // Updating temp's data value to given data value
    temp->freq = freq;               // Updating temp's frequency value to given frequency value

    return temp; // Returning the temp node
}

// Function to create the collection of huffmanntree nodes of a given capacity
struct HuffmannTree *createMinHeap(unsigned capacity)
{
    // Dynamically allocation of minheap huffmann tree
    struct HuffmannTree *minHeap = (struct HuffmannTree *)malloc(sizeof(struct HuffmannTree));

    minHeap->size = 0; // Initiating the size to 0

    minHeap->capacity = capacity; // Updating minheap's capacity value to given capacity value

    // Dynamically declaring the array
    minHeap->array = (struct HuffmannTreenode **)malloc(minHeap->capacity * sizeof(struct HuffmannTreenode *));
    return minHeap;
}

// Function to swap two HuffmannTree nodes
void swapHFtreenode(struct HuffmannTreenode **a, struct HuffmannTreenode **b)
{
    // Basic swapping process of two pointers using third pointer
    struct HuffmannTreenode *t = *a;
    *a = *b;
    *b = t;
}
