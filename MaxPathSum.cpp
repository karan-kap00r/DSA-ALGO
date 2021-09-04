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

int MaxSumUtil(Node* root,int &ans)
{
	if(root==NULL)
		return 0;
	int left=MaxSumUtil(root->left,ans);
	int right=MaxSumUtil(root->right,ans);
	int NodeMax=max(max(root->data,root->data+left+right),max(root->data+left,root->data+right));
	
	ans=max(ans,NodeMax);
	int SingleMax=max(root->data,max(root->data+left,root->data+right));
	return SingleMax;
}

int MaxSum(Node* root)
{
	int ans=INT_MIN;
	MaxSumUtil(root,ans);
	return ans;
}

void InOrderTraversal(Node* n)
{
	if(n!=NULL)
	{
	InOrderTraversal(n->left);
	cout<<" "<<n->data;
	InOrderTraversal(n->right);
	
	}
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
    cout<<endl;
    InOrderTraversal(root);
   
	cout<<endl<< "Max Path Sum of given BT is :  "<<MaxSum(root);
    return 0;
}
