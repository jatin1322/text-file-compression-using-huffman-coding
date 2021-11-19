
// Function to min heapify
// Result of this function is minHeap modified such that index roots a Min-Heap
void minHeapify(struct HuffmannTree *minHeap, int index)
{

    int smallest = index;
    // Setting the left and right of the node minHeeap[index]
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // Checking for the smallest element
    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    // Updating the minHeap/Huffmann tree
    if (smallest != index)
    {
        swapHFtreenode(&minHeap->array[smallest], &minHeap->array[index]);
        minHeapify(minHeap, smallest);
    }
}









struct HuffmannTreenode *extractMin(struct HuffmannTree *minHeap)
{

    struct HuffmannTreenode *temp = minHeap->array[0];
    // Copying the last value in the array to the root or first value in array
    minHeap->array[0] = minHeap->array[minHeap->size - 1];

    --minHeap->size;        // Decrease heap's size by 1
    minHeapify(minHeap, 0); // Calling the minheapify such that 0 roots the minheap/huffmann tree

    return temp; // Returning the min value node
}
// Function to insert a new Huffmann tree node to our huffmann tree
void INSERT(struct HuffmannTree *minHeap, struct HuffmannTreenode *minHeapNode)
{

    ++minHeap->size; // Increase heap's size by 1
    int i = minHeap->size - 1;
    // Comparing the added element with its parent
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq)
    {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = minHeapNode; // Assigning the new node to its proper place in the array/heap
}


// Function to build the Huffmann Tree
void BuildHeap(struct HuffmannTree *minHeap)
{
    int n = minHeap->size - 1;
    int i;
    // Perform reverse level order traversal from last non-leaf node and heapify each node
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

////////////////////////////////////
struct HuffmannTree *CreateHFtree(char data[], int freq[], int size)
{
    struct HuffmannTree *minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);

    minHeap->size = size;
    BuildHeap(minHeap);

    return minHeap;
}


// Function that builds our tree
struct HuffmannTreenode *buildHuffmanTree(char data[], int freq[], int size)
{
    struct HuffmannTreenode *left, *right;
    struct HuffmannTreenode *node;
    // Create a Huffmann Tree of capacity equal to size
    struct HuffmannTree *minHeap = CreateHFtree(data, freq, size);

    // Iterate till the size of Tree doesn't become 1
    while (!IsSize(minHeap))
    {
        // Get the two minimum frequency HuffmannTreenode from Huffmann Tree
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        // Create a new internal HuffmannTreenode with frequency equal to the sum of the two nodes frequencies.
        // Make the two extracted node as left and right children of this new node and add this node to the Huffmann Tree

        node = newNode('$', left->freq + right->freq); //'$' is a special value for internal nodes, not used

        node->left = left;
        node->right = right;

        INSERT(minHeap, node);
    }
    // The remaining HuffmannTreenode is the root node and the Huffmann Tree is complete.
    return extractMin(minHeap);
}
