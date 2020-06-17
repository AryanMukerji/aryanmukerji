#include <iostream>
using namespace std;

class Node 
{
    public:
    
    int key;
    Node *left;
    Node *right;
    int height;
};

int max(int a, int b) 
{
    return (a > b) ? a : b;
}

int height(Node *N) // Calculate height
{
    if(N == NULL)
    {
        return 0;
    }
    
    return N->height;
}

Node *newNode(int key) // New node creation
{
    Node *node = new Node();
    
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    
    return (node);
}

Node *rightRotate(Node *y) // Rotate right
{
    Node *x = y->left;
    Node *T2 = x->right;
    
    x->right = y;
    y->left = T2;
    
    y->height = max( height(y->left), height(y->right) ) + 1;
    x->height = max( height(x->left), height(x->right) ) + 1;
    
    return x;
}

Node *leftRotate(Node *x) // Rotate left
{
    Node *y = x->right;
    Node *T2 = y->left;
    
    y->left = x;
    x->right = T2;
    
    x->height = max( height(x->left), height(x->right) ) + 1;
    y->height = max( height(y->left), height(y->right) ) + 1;
        
    return y;
}

int getBalanceFactor(Node *N) // Get the balance factor of each node
{
    if (N == NULL)
    {
        return 0;
    }    
    return height(N->left) - height(N->right);
}