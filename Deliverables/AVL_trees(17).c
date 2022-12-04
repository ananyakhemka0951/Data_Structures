#include <stdio.h>
#include <stdlib.h>

struct node
{
 int val;
 struct node* left;
 struct node* right;
 int height; //stores the height/number of children following the node
};

typedef struct node * Nodeaddress; // creating a new data type called NodeAddress which is the address of the node



/* ================================================== */
//Function to extract the maximum between the two numbers
int findmax(int x, int y)
{
    if(x>y)
    return x;
    else
    return y;
}


//Function to extract the height of the node
int findHeight(Nodeaddress n)//returns the height of a node
{
    if(n==NULL)
        return 0;
    return n->height;
}



//Function to allocate space and initialize a node
Nodeaddress create(int val) 
{
    Nodeaddress newnode = malloc(sizeof(struct node));//To allocate the required space for a node
    newnode->val = val;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->height = 1; //new leaf node always has height one

    return newnode;
}




//Function to find out the balance factor (left height - right height) of n 
int bf(Nodeaddress n) 
{
    if(n==NULL)
        return 0;
    return (findHeight(n->left) - findHeight(n->right)); 
}







/* ================================================== */
//Rotation 



//Function to left rotate
Nodeaddress Lrotate(Nodeaddress x)
{
    Nodeaddress y = x->right;
    Nodeaddress a = y->left;

    y->left = x;
    x->right = a;

    x->height = findmax(findHeight(x->left), findHeight(x->right)) + 1; 
    y->height = findmax(findHeight(y->left), findHeight(y->right)) + 1; 
    
    return y;

}


//Function to right rotate
Nodeaddress Rrotate(Nodeaddress y) //right rotate
{
    Nodeaddress x = y->left;
    Nodeaddress b = x->right;

    x->right = y;
    y->left = b;

    y->height = findmax(findHeight(y->left), findHeight(y->right)) + 1; 
    x->height = findmax(findHeight(x->left), findHeight(x->right)) + 1; 

    return x;
}


//Function to insert the val in the tree and recursively balance out the tree via rotation
Nodeaddress insert(Nodeaddress node, int val)
{
    if(node==NULL)
        create(val);//Function to allocate space for a new node and initialize it
    
    if(val<node->val)
        insert(node->left, val);

    else if(val>node->val)
        insert(node->right, val);

    node->height = 1 + findmax(findHeight(node->left), findHeight(node->right));
    int bal = bf(node);

//left left
    if(bal>1 && val<node->right->val)
    {
        return R(node);
    }

//right right 
    if(bal<-1 && val>node->left->val)
    {
        return L(node);
    }

//left right   
    if(bal>1 && val>node->right->val)
    {
        node->left = L(node);
        return R(node);
    }

//right left    
    if(bal<-1 && val<node->left->val)
    {
        node->right = R(node);
        return L(node);
    }

    return node;
}





/* ================================================== */
void prefixPrint(address root)
{

    printf("%d ",root->val);
    if(root->left)
    prefixPrint(root->left);
    if(root->right)
    prefixPrint(root->right);
}

int main()
{
    address head = NULL;

    head = insert(head, 50);
    head = insert(head, 5);
    head = insert(head, 20);
    head = insert(head, 2);
    head = insert(head, 65);
    head = insert(head, 90);
    prefixPrint(head);

    return 0;
}
