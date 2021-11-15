#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char number[50];
    char address[50];
} BookEntry; // creating a data structure that stores the name, number and address as a phonebook entry


struct node
{
    BookEntry data; //node will store BookEntry data structures
    struct node *right_child; // right child
    struct node *left_child; // left child
};

void search(struct node *root, char x[50])
{
    if(root==NULL || strcmp(root->data.name, x) == 0) //if root->data is x then the element is found
        printf(" Number: %s Address: %s", root->data.number, root->data.address);
    else if(strcmp(x, root->data.name) > 0) // x is greater, so we will search the right subtree
        return search(root->right_child, x);
    else //x is smaller than the data, so we will search the left subtree
        return search(root->left_child,x);
}

//function to create a node
struct node* new_node(BookEntry x)
{
    struct node *p;
    p = malloc(sizeof(struct node));
    p->data = x;
    p->left_child = NULL;
    p->right_child = NULL;

    return p;
}

struct node* insert(struct node *root, BookEntry x)
{
    //searching for the place to insert
    if(root==NULL)
        return new_node(x);
    else if(strcmp(x.name, root->data.name) > 0) // x is greater. Should be inserted to right
        root->right_child = insert(root->right_child, x);
    else // x is smaller should be inserted to left
        root->left_child = insert(root->left_child,x);
    return root;
}

void inorder(struct node *root) // mostly for testing purposes
{
    if(root!=NULL) // checking if the root is not null
    {
        inorder(root->left_child); // visiting left child
        printf(" Name: %s Number: %s Address: %s\n", root->data.name, root->data.number, root->data.address); // printing data at root
        inorder(root->right_child);// visiting right child
    }
}


int main() {
    printf("Enter an integer (<1,000) for the number of entries you would like to add to the phonebook\n");
    char i;
    fgets(&i, 1000, stdin);
    i = atoi(&i); // receiving input from user for number of entries

    BookEntry arr_entries[i]; // initializing an array of BookEntry structs to add to tree
    int n;
    for (n = 0; n < i; n++) { // getting attributes fom user and adding to structs
        printf("Enter name %i of %i (max 50 chars)\n", n + 1, i);
        fgets(arr_entries[n].name, 50, stdin);
        printf("Enter number %i (max 50 chars)\n", n + 1);
        fgets(arr_entries[n].number, 50, stdin);
        printf("Enter address %i (max 50 chars)\n", n + 1);
        fgets(arr_entries[n].address, 50, stdin);

    }
    struct node *root; // initializing tree
    root = new_node(arr_entries[0]);
    for (n = 1; n < i; n++) { // adding data struct as nodes of tree
        insert(root, arr_entries[n]);

    }
    printf("Enter the exact name you would like to search for or type 'q' (or anything else) to quit\n");
    char name[50];
    fgets(name, 50, stdin);
    while (strcmp(name, "q\n") != 0) { // returning the requested results
        search(root, name);
        fgets(name, 50, stdin);
    }

    return 0;
}
