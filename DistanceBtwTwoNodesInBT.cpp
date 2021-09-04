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

int FindDist(Node* root,int k ,int dist)
{
	if(root==NULL)
		return -1;
	if(root->data==k)
		return dist;
	int Left=FindDist(root->left,k,dist+1);
	if(Left!=-1)
		return Left;
	return FindDist(root->right,k,dist+1);
}

Node* LCA(Node* root,int n1,int n2)
{
	if(root==NULL)
		return NULL;
	if(root->data==n1 || root->data==n2)
		return root;
	Node* Left=LCA(root->left,n1,n2);
	Node* Right=LCA(root->right,n1,n2);
	
	if(Left!=NULL && Right!=NULL)
		return root;
	if(Left==NULL && Right==NULL)
		return NULL;
	if(Left!=NULL)
		return LCA(root->left,n1,n2);
	return LCA(root->right,n1,n2);
}

int DistBtwNodes(Node* root,int n1,int n2)
{
	Node* Lca=LCA(root,n1,n2);
	
	int d1=FindDist(Lca,n1,0);
	int d2=FindDist(Lca,n2,0);
	return d1+d2;
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
    
    cout << "\nDistance between 8 and 10  is : "<<DistBtwNodes(root,8,10);
    return 0;
}

