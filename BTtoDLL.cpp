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

 void BTtoDLL(Node* root,Node* &head,Node* &tail)
    {
        if(root==NULL)
            return ;
        
        BTtoDLL(root->left,head,tail);
        if(tail==NULL)
        {
            head=root;
        }
        else
        {
            root->left=tail;
            tail->right=root;

        }
        tail=root;
        
        BTtoDLL(root->right,head,tail);
    }

 Node* bToDLL(Node *root)
    {
        // your code here
        Node* head=NULL;
        Node* tail=NULL;
        BTtoDLL(root,head,tail);
        return head;
    }
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
void printList(Node *head)
{
    while (head)
    {
        cout<<head->data<<" ";
        head = head->right;
    }
}

int main()
{
    
//    Node* tail=NULL;
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
    
 	Node* head1 =bToDLL(root);
 
    cout << "\nExtracted Double Linked list is:\n";
    printList(head1);
 
    cout << "\nInorder traversal of modified tree is:\n";
    print(root);
    return 0;
}

