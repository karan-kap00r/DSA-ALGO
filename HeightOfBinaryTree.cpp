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

int CalciHeight(Node* root)
{
	if(root==NULL)
		return 0;
	int Lheight=CalciHeight(root->left);
	int Rheight=CalciHeight(root->right);
	return max(Lheight,Rheight)	+1;
}

//			1
//		2		3
//	4		5		6
//7		8		9		10

int main()
{
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
    int k=CalciHeight(root);
    cout<<"Height of given Binary Tree is :"<<k<<endl;
    return 0;
}
