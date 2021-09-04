#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int val)
    {
    	data=val;
    	left=right=NULL;
	}
};

Node* LeafToDLL(Node* root,Node* &head,Node* &tail)
{
    if(!root)
        return NULL;
    if(!root->left && !root->right)
    {
        if(!head)
        {
            head=root;
        }
        else
        {
            root->left=tail;
            tail->right=root;
        }
        tail=root;
        return NULL;
    }
    
    root->right=LeafToDLL(root->right,head,tail);
    root->left=LeafToDLL(root->left,head,tail);
    return root;
}

//Node * convertToDLL(Node *root){
//    Node* head = NULL;
//    Node* tail=NULL;
//    root=LeafToDLL(root,head,tail);
//    return head;
//}
// Utility function for printing tree in In-Order.
void print(Node *root)
{
    if (root != NULL)
    {
        print(root->left);
        cout<<root->data<<" ";
        print(root->right);
    }
}
 
// Utility function for printing double linked list.
void printList(Node *node)
{
    Node *prev = NULL;
    while (node!=NULL)
    {
        cout << node->data << " ";
        prev = node;
        node = node->right;
    }
    cout << endl;
    while (prev!=NULL)
    {
        cout << prev->data << " ";
        prev = prev->left;
    }
    cout << endl;
}

int main()
{
    Node* head = NULL;
    Node* tail=NULL;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->left->left = new Node(7);
    root->left->left->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);
 
    cout << "Inorder Trvaersal of given Tree is:\n";
    print(root);
    
 	root=LeafToDLL(root,head,tail);
 
    cout << "\nExtracted Double Linked list is:\n";
    printList(head);
 
    cout << "\nInorder traversal of modified tree is:\n";
    print(root);
    return 0;
}

