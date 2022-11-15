#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node* left;
    struct node* right;
};

typedef struct node* address;

address search(address root, int val )
{
    if(root == NULL)
    return NULL;

    if(val > root->val)
    {
        search(root->right, val);
    }
    else if(val < root->val )
    {
        search(root->left, val);
    }
    

        return root;
    
}

void create(address root, int val)
{
    root = malloc(sizeof(struct node));
    root->val = val;
}

address insert(address root, int val)
{
    if(root == NULL)
    {
        create(root, val);
        return root;
    }

    else if(val > root->val)
    {
        if(root->right)
            insert(root->right, val);
        else
            create(root->right, val);
    }

    else if(val < root->val)
    {
        if(root->left)
            insert(root->left, val);
        else
            create(root->left, val);
    }

    
        return root;
}

void inorder(address root)
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
    printf("enter the size of array, that will be made into a binary tree.");
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

    address root = malloc(sizeof(struct node));

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
