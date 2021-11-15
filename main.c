#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct {
    char name[50];
    char number[50];
    char address[50];
} BookEntry;


//struct node
//{
//    BookEntry data; //node will store an integer
//    struct node *right_child; // right child
//    struct node *left_child; // left child
//};
//
//struct node* search(struct node *root, BookEntry x)
//{
//    if(root==NULL || root->data.name==x.name) //if root->data is x then the element is found
//        return root;
//    else if(x>root->data) // x is greater, so we will search the right subtree
//        return search(root->right_child, x);
//    else //x is smaller than the data, so we will search the left subtree
//        return search(root->left_child,x);
//}
//
////function to find the minimum value in a node
//struct node* find_minimum(struct node *root)
//{
//    if(root == NULL)
//        return NULL;
//    else if(root->left_child != NULL) // node with minimum value will have no left child
//        return find_minimum(root->left_child); // left most element will be minimum
//    return root;
//}
//
////function to create a node
//struct node* new_node(int x)
//{
//    struct node *p;
//    p = malloc(sizeof(struct node));
//    p->data = x;
//    p->left_child = NULL;
//    p->right_child = NULL;
//
//    return p;
//}
//
//struct node* insert(struct node *root, int x)
//{
//    //searching for the place to insert
//    if(root==NULL)
//        return new_node(x);
//    else if(x>root->data) // x is greater. Should be inserted to right
//        root->right_child = insert(root->right_child, x);
//    else // x is smaller should be inserted to left
//        root->left_child = insert(root->left_child,x);
//    return root;
//}
//
//void inorder(struct node *root)
//{
//    if(root!=NULL) // checking if the root is not null
//    {
//        inorder(root->left_child); // visiting left child
//        printf(" %d ", root->data); // printing data at root
//        inorder(root->right_child);// visiting right child
//    }
//}


int main() {
    printf("Enter an integer (<1,000) for the number of entries you would like to add to the phonebook\n");
    char i;
    fgets(&i, 1000, stdin);
    i = atoi(&i);

    BookEntry arr_entries[i];
    int n;
    for (n = 0; n < i; n++) {
        printf("Enter name %i of %i (max 50 chars)\n", n + 1, i);
        fgets(arr_entries[i].name, 50, stdin);
        printf("Enter number %i (max 50 chars)\n", n + 1);
        fgets(arr_entries[i].number, 50, stdin);
        printf("Enter address %i (max 50 chars)\n", n + 1);
        fgets(arr_entries[i].address, 50, stdin);

    }

    for (n = 0; n < i; n++) {
        printf(" Name: %s Number: %s Address: %s\n", arr_entries[i].name, arr_entries[i].number, arr_entries[i].address);
    }
    char name[4] = "Alex";
    if (arr_entries[0].name == name) {
        printf("True");
    }
    else {
        printf("False");
    }
    return 0;
}
