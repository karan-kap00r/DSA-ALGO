#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
		Node(int val)
		{
			data=val;
			left=right=NULL;
		}
};

Node* ConstructBst(int preOrder[],int* preIdx,int key,int min,int max,int n)
{
	if(*preIdx>=n)
	return NULL;
	
	Node* root=NULL;
	if(key>min && key<max)
	{
		root=new Node(key);
		*preIdx=*preIdx+1;
		if(*preIdx<n)
		{
			root->left=ConstructBst(preOrder,preIdx,preOrder[*preIdx],min,key,n);
		}
		if(*preIdx<n)
		{
			root->right=ConstructBst(preOrder,preIdx,preOrder[*preIdx],key,max,n);
		}
	}
	
	return root;
}

void PreOrder(Node* root)
{
	if(root==NULL)
	return;
	cout<<root->data<<" ";
	PreOrder(root->left);
	PreOrder(root->right);
}

int main()
{
	int preO[5]={10,2,1,13,11};
	int preIdx=0;
	Node* root=ConstructBst(preO,&preIdx,preO[preIdx],INT_MIN,INT_MAX,5);
	PreOrder(root);
	return 0;
}
