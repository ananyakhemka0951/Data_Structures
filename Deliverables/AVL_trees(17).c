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
Nodeaddress Lrotate(Nodeaddress r)
{
    Nodeaddress y = r->right;
    Nodeaddress a = y->left;

    
    y->left = r; // As x is less than y, x will come to the left of y 
    x->right = a; // As a is less than y and y is greater than x, it will come to the right of x after the rotation

    //As we will have to update the heights of the nodes according to its new position,
    r->height = findmax(findHeight(r->left), findHeight(r->right)) + 1; 
    y->height = findmax(findHeight(y->left), findHeight(y->right)) + 1; 
    
    return y; // y which was the right root of r, has been replaced by r thus we will return the newnode y

}


//Function to right rotate
Nodeaddress Rrotate(Nodeaddress r) //right rotate
{
    Nodeaddress y = r->left;
    Nodeaddress a = y->right;

    y->right = r;
    x->left = a;
    
 
    //As we will have to update the heights of the nodes according to its new position,
    r->height = findmax(findHeight(r->left), findHeight(r->right)) + 1; 
    y->height = findmax(findHeight(y->left), findHeight(y->right)) + 1; 

    return y; // y which was the left root of r, has been replaced by r thus we will return the newnode y
}






/* ================================================== */

//Function to insert the val in the tree and recursively balance out the tree via rotation
Nodeaddress insert(Nodeaddress node, int val)
{
    if(node==NULL)
        create(val);//Function to allocate space for a new node and initialize it
    
    //To find the correct position of the val, we will compare the val with the node's value and recursively call the function.
    if(val<node->val)
    {
        node->left=insert(node->left, val);
    }

    else if(val>node->val)
    {
        node->right=insert(node->right, val);
    }
 
    else
    {
     return node; //If val is equal to nodes val, an extra node will not be added. Therefore, this returns the correct position for the val.
    }
 
    
/* ================================================== */
 //After inserting the val in the tree, we will calculate the balance factor and thereby balance the tree out accordingly.

 
    //Finds the updated height of the node
    node->height = 1 + findmax(findHeight(node->left), findHeight(node->right));
    int bal = bf(node);

 
 //Following are the four cases for rotation along with its cases
//left left
    if(bal>1 && val<node->right->val)
    {
        return Rrotate(node);
    }

//right right 
    if(bal<-1 && val>node->left->val)
    {
        return Lrotate(node);
    }

//left right   
    if(bal>1 && val>node->right->val)
    {
        node->left = Lrotate(node);
        return Rrotate(node);
    }

//right left    
    if(bal<-1 && val<node->left->val)
    {
        node->right = Rrotate(node);
        return Lrotate(node);
    }

    return node;
}





/* ================================================== */
//Preorder traversal of the tree. [root - left - right]
void prefixPrint(Nodeaddress root)
{

    printf("%d ",root->val);
    if(root->left)
    prefixPrint(root->left);
    if(root->right)
    prefixPrint(root->right);
}



/* ================================================== */
int main(int argc, char **argv)
{
    Nodeaddress root = NULL;
 
    	printf("Enter the size\n");
    int n;
    scanf("%d",&n);
    
	if(n<=0)
 {
        printf("Size should be greater than 0");
        return 0;
    }
 
   int x=0;
  printf("Enter the elements \n");
   
   for(i=0; i<n; i++) {
    scanf("%d",&x);
    root=insert(root,x);
   }
    
    printf("The preorder traversal:");
    prefixPrint(root);

    return 0;
}
