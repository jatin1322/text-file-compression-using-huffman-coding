#include <stdio.h>
#include <stdlib.h>
  int main()
{     printf("\n");
    printf("*******************************************************\t\t\n");
    printf("\n");
     printf("HELLO AND WELCOME!! \n");
     
    printf("\n");  
     printf("ENTER NAME OF FILE WHICH YOU WANT TO COMPRESS    "); 
   
    
   
    char filename[20];
    FILE *input, *output;
    scanf("%s", filename);
    input = fopen(filename, "r");
    output = fopen("output.txt", "w");
    char c;
    int totalsize=0;
    int arr1[128] = {0};
    if (input == NULL)
    {
        printf("this can't be open");
    }
    else
    {
        while ((c = fgetc(input)) != EOF)
        {
            arr1[c]++;
            totalsize++;

        }
    }
    int ct = 0;
    for (int i = 0; i < 128; i++)
    {
        if (arr1[i] != 0)
        {
            ct++;
        }
    }
    char arr2[ct];
    int frequency[ct];
    for (int i = 0, j = 0; i < 128; i++)
    {
        if (arr1[i] != 0)
        {
            arr2[j] = (char)i;
            frequency[j] = arr1[i];
            j++;
        }
    }
    struct HuffmannTreenode *root = buildHuffmanTree(arr2, frequency, ct);
    int arrr[MAXIMUM_TREE_HT];
    int node = 0;

    assigncode(root, arrr, node);
    input = fopen(filename, "r");
    char d;
    while ((d = fgetc(input)) != EOF)
    {
        struct LL_node *temp = encoded_code[d];
        while (temp != NULL)
        {
            fprintf(output, "%d", temp->data);
            temp = temp->next;
        }
    }

    int print_decision;
   
    printf(" PRESS 1 : TO CONTINUE    \n");
    printf(" PRESS 2 : TO PRINT CODE OF EVERY CHARACTER   \n");
    scanf("%d", &print_decision);
    if (print_decision == 2)
    {
        printCodes(arr2, ct);
    }
    printf("OUTPUT.TXT IS YOUR ENCODED FILE  \n");
    fclose(output);

    printf(" PRESS 1 : TO CONTINUE    \n");
    printf(" PRESS 2 : TO DECODE OUTPUT.TXT   \n");
    int decrypt_decision;
    scanf("%d", &decrypt_decision);
    if (decrypt_decision == 2)
    {

        FILE *decode = fopen("output.txt", "r");
        FILE *orignal = fopen("decoded.txt", "w");

        char t;
        struct HuffmannTreenode *curr = root;
        while ((t = fgetc(decode)) != EOF)

        {
            if (t == '0')
                curr = curr->left;
            else if (t == '1')
            {
                curr = curr->right;
            }
            if (curr->left == NULL && curr->right == NULL)

            {
                fprintf(orignal, "%c", curr->data);
                curr = root;
            }
        }
            printf("DECODED.TXT IS YOUR DECODED FILE  \n");
    }
    printf(" PRESS 1 : TO EXIT THE PROGRAM    \n");
    printf(" PRESS 2 : TO KNOW HOW MUCH YOUR FILE COPMRESSED   \n");
    int SUMMARY;
    scanf("%d", &SUMMARY);
    if (SUMMARY == 2)
    {
    get_size(arr2,ct);
    int total_bits_endoded=0;
     
    for (int i = 0; i < ct; i++)
    {int d = (int)arr2[i];
      total_bits_endoded=total_bits_endoded+ size_code[d]*frequency[i];

    }
    float a=totalsize*8;
    float b=(a-total_bits_endoded)*100;

    printf(" TOTAL CHARACTER IN GIVEN FILE IS:    ""%d\n",totalsize);
    printf(" TOTAL NUMBER OF BITS USED:           ""%d\n",totalsize*8);
    printf(" TOTAL CHARACTER IN OUTPUT FILE IS:   ""%d\n",total_bits_endoded);
    printf(" TOTAL NUMBER OF BITS USED:           ""%d\n",total_bits_endoded);
    float percentage1=b/a;
    printf("YOUR FILE IS COMPRESSION BY :         ""%0.2f percent \n",percentage1);
    




    }
    return 0;
}
