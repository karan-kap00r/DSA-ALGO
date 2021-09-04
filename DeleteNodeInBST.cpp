#include<bits/stdc++.h>
using namespace std;
class BST{
	public:
		int data;
		BST* left;
		BST* right;
		BST()
		{
			data=0;
			left=right=NULL;
		}
};
BST* Create(int data)
{
	BST* n=(BST*)malloc(sizeof(BST));
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	return n;
}
BST* Insert(BST* root,int data)
{
	if(root==NULL)
	{
		root=Create(data);
		return root;
	}
	else if(data<=root->data)
	{
		root->left=Insert(root->left,data);
	}
	else
	{
		root->right=Insert(root->right,data);
	}
	return root;
}
BST* MinValueNode(BST* k)
{
	BST* tem=k;
	while(tem->left!=NULL)
	{
		tem=tem->left;
	}
	return tem;
}

BST* Delete(BST* n,int v)
{
	if(n==NULL)
	return n;
	else if(v<n->data)
	{
		n->left=Delete(n->left,v);
	}
	else if(v>n->data)
	{
		n->right=Delete(n->right,v);
	}
	else
	{
		if(n->right==NULL)
		{
			BST* temp=n->left;
			delete n;
			return temp;
		}
		else if(n->left==NULL)
		{
			BST* temp=n->right;
			delete n;
			return temp;
		}
		else
		{
			BST* temp=MinValueNode(n->right);
			n->data=temp->data;
			n->right=Delete(n->right,temp->data);
		}
	}
	return n;
}
void InOrderTraversal(BST* n)
{
	if(n!=NULL)
{
	InOrderTraversal(n->left);
	cout<<" "<<n->data;
	InOrderTraversal(n->right);
	
}
 } 
int main()
{
	BST* root=NULL;
	root=Insert(root,30);
	root=Insert(root,10);
	root=Insert(root,48);
	root=Insert(root,56);
	root=Insert(root,42);
	InOrderTraversal(root);
	int l;
	cout<<endl<<" Enter the element you want  to delete"<<endl;
	cin>>l;
	Delete(root,l);
	cout<<endl<<"AFTER DELETING "<<l<<endl;
	InOrderTraversal(root);
	return 0;
}
