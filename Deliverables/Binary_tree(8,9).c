#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node* left;
    struct node* right;
};


// creating a new data type NodeAddress
typedef struct node* Nodeaddress;


// Tp search the correct position of the element for insertion
Nodeaddress search(Nodeaddress root, int val)
{
    if(root == NULL)
    return NULL;

    
    //if the value is grater than the parent/root, we move to the right side of the tree
    if(val > root->val)
    {
        search(root->right, val);
    }
    //If the valuye is less than the parent/root, we move to the left side of the tree
    else if(val < root->val )
    {
        search(root->left, val);
    }
    

        return root;
    
}

//To allocate space for a new node and assign the val to it.
void create(Nodeaddress root, int val)
{
    root = malloc(sizeof(struct node)); // memory allocation for the node
    root->val = val;
}


//To insert every element in a form of a binary search tree
Nodeaddress insert(Nodeaddress root, int val)
{
    //Case for the root of the tree
    if(root == NULL)
    {
        create(root, val);
        return root;
    }

    //if the value is grater than the parent/root, we move to the right side of the tree
    else if(val > root->val)
    {
        //if there exists a node right of the parent/root, we recursively call insert again to campare it with the value on the right of the parent
        if(root->right)
            insert(root->right, val);
        else
            //If the right node does not exist, we will call create to allocate space fopr that node and add the element to its right position
            create(root->right, val);
    }

    
    //if the value is greater than the parent/root, we move to the left side of the tree
    else if(val < root->val)
    {
        //if there exists a node left of the parent/root, we recursively call insert again to campare it with the value on the left of the parent
        if(root->left)
            insert(root->left, val);
        else
            //If the left node does not exist, we will call create to allocate space fopr that node and add the element to its left position
            create(root->left, val);
    }

    
        return root;
}

void inorder(Nodeaddress root)
{
    if(root->left)
    {
        inorder(root->left);
    }
    if(root)
    {
        printf("%d", root->val);
    }
    if(root->right)
    {
        inorder(root->right);
    }
}

void delete(address d)
{
    d = NULL;   
}


int main()
{
    int n;
    printf("enter the size of array, that will be made into a binary search tree.");
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i<n; i++)
    {
        printf("enter number: ");
        scanf("%d", &arr[n]);
    }

       for(int i = 0; i<n; i++)
    {
        printf("%d, ", arr[i]);
    }

    //case for the root of the binary search tree
    Nodeaddress root = malloc(sizeof(struct node));

    for(int i=0; i<n; i++)
    {
        if(i == 0)
        {
            root->val = arr[i];
        }
        insert(root, arr[i]);
    }
    
    inorder(root);

/*
    int k;
    printf("Do you want to delete any value? 1/0 : ");
    scanf("%s", &k);
    if(k==1)
    {
        int d;
        printf("enter value to delete: ");
        scanf("%d ", &d);
        if(search(root, d))
        {
            address d = search(root, d);
            delete(d);
        }
        else
        {
            printf("element does not exist");
    }
    }
*/
    return 0;
}
