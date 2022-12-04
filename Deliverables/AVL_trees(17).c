#include <stdio.h>
#include <stdlib.h>

struct node
{
 int val;
 struct node* left;
 struct node* right;
 int height; //new attribute, stores the number of children following the node
};

typedef struct node* address;

int max(int a, int b)
{
    if(a>b)
    return a;
    else
    return b;
}

int findHeight(address n)//returns the height of a node
{
    if(n==NULL)
        return 0;
    return n->height;
}

address create(int val) //allocates memory space for a node
{
    address node = malloc(sizeof(struct node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; //new leaf node always has height one

    return node;
}

int bf(address n) //finds the balance factor
{
    if(n==NULL)
        return 0;
    return findHeight(n->left) - findHeight(n->right); 
}

address L(address x)//left rotate
{
    address y = x->right;
    address a = y->left;

    y->left = x;
    x->right = a;

    x->height = max(findHeight(x->left), findHeight(x->right)) + 1; 
    y->height = max(findHeight(y->left), findHeight(y->right)) + 1; 
    
    return y;

}

address R(address y) //right rotate
{
    address x = y->left;
    address b = x->right;

    x->right = y;
    y->left = b;

    y->height = max(findHeight(y->left), findHeight(y->right)) + 1; 
    x->height = max(findHeight(x->left), findHeight(x->right)) + 1; 

    return x;
}

address insert(address node, int val)
{
    if(node==NULL)
        create(val);
    
    if(val<node->val)
        insert(node->left, val);

    else if(val>node->val)
        insert(node->right, val);

    node->height = 1 + max(findHeight(node->left), findHeight(node->right));
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
