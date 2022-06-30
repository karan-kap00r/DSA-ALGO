// { Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
int postIndex;
int search(int arr[], int start, int end, int val)
{
    for(int i=start;i<=end;i++)
    {
        if(arr[i]==val) return i;
    }
}

Node *constructTree(int in[], int post[], int inStrt, int inEnd)
{
    if(inStrt>inEnd) return NULL;
    Node *newNode = new Node(post[postIndex--]);
    if(inStrt==inEnd) return newNode;
    
    int inIndex = search(in,inStrt, inEnd, newNode->data);
    newNode->right = constructTree(in,post,inIndex+1,inEnd);
    newNode->left = constructTree(in,post,inStrt,inIndex-1);
    
    return newNode;
}
Node *buildTree(int in[], int post[], int n) 
{
    postIndex=n-1;
    return constructTree(in,post,0,n-1);
}

