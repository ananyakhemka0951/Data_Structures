// BINARY SEARCH TREE
// CREATE AND INSERT

#include <stdio.h>
#include <stdlib.h> // introductory 
 
struct node { //creating a structure with val, left and right pointers 
    int val;
    struct node *left; // left pointer to smaller numbers 
    struct node*right; // right pointer to larger numbers
}; typedef struct node * NodeAddress; // making a shortcut for accessing the above structure 
 
// creating or adding a new node to BST 
 NodeAddress Add_Node(int val) // add the integer value of val
{
     NodeAddress new = malloc(sizeof(struct node)); // allocating memory for the new node which is of size node 
    new->val = val; // adding value to the new node created 
    new->left =NULL;  // left of new node will be empty 
    new->right = NULL; // right of new node will be empty 
    return new; 
}
 
// didnt understand, had to copy to run the code 
// will meet with TA to understand the following lines 25- 32
void inorder(NodeAddress root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d \n", root->val);
        inorder(root->right);
    }
}
 
// inserting a new node to an existing BST
NodeAddress insert_node(NodeAddress node, int val)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return Add_Node(val); // if node = NULL then add a node with value there by previously defined function
 
    // if node is not equal to NULL then traverse down the tree to find where node = NULL
    if ( val < node->val) 
        node->left = insert_node(node->left, val); // if value is lesser than the root then move to the left and carry out the process again till the time root = NULL with the (changed) root and (to be insterted) value as inputs
    else if (val > node->val)
        node->right = insert_node(node->right, val); // repeat the same thing with greater than case
    return node;
}
 
// calling all functions 
int main()
{
    struct node* root = NULL;
    root = insert_node(root, 5);
    insert_node(root, 3);
    insert_node(root, 2);
    insert_node(root, 4);
    insert_node(root, 7);
    insert_node(root, 6);
    insert_node(root, 8);
 
    // print inoder traversal of the BST
    inorder(root); // didnt understand, had to copy to run the code 
 
    return 0;
}
