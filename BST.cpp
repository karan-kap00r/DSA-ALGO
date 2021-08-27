#include<bits/stdc++.h>
using namespace std;

//	SWAP
	void Swap(int &a, int &b)
	{
		int temp=b;
		b=a;
		a=temp;
	}

class BSTnode{
	public:
		int data;
		BSTnode* left;
		BSTnode* right;
		BSTnode()
		{
			data=0;
			left=NULL;
			right=NULL;
		}
};
BSTnode* CreateNode(int data)
{
	BSTnode* n=(BSTnode*)malloc(sizeof(BSTnode));
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	return n;
}
BSTnode* Insert(BSTnode* root , int data)
{
	if(root==NULL)
	{
		root=CreateNode(data);
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



bool Search(BSTnode* root, int data)
{
	if(root==NULL)
	return false;
	if(root->data==data)
	return true;
	else if(data<=root->data)
	{
		return Search(root->left,data);
	}
	else
	{
		return Search(root->right,data);
	}
}

void MinHeap(BSTnode* root)
{
	if(root==NULL)
	{
		cout<<endl<<"Tree is Empty..."<<endl;
		return;
	}
	else
	{
		if(root->data > root->left->data)
		{
			Swap(root->data,root->left->data);
		}
		if(root->data > root->right->data)
		{
			Swap(root->data,root->right->data);
		}
//			MinHeap(root->left);
//			MinHeap(root->right);
	}

}

void InOrderTraversal(BSTnode* n)
{
	if(n!=NULL)
{
	InOrderTraversal(n->left);
	cout<<" "<<n->data;
	InOrderTraversal(n->right);
	
}
 } 
void PreOrderTraversal(BSTnode* n)
{
	if(n!=NULL)
	{
		cout<<" "<<n->data;
		PreOrderTraversal(n->left);
		PreOrderTraversal(n->right);
	}
}

void PostOrderTraversal(BSTnode* n)
{
	if(n!=NULL)
	{
		PostOrderTraversal(n->left);
		PostOrderTraversal(n->right);
		cout<<" "<<n->data;
	}
}

int main()
{
	BSTnode* root=NULL;
	root=Insert(root,15);
	root=Insert(root,10);
	root=Insert(root,20);
	root=Insert(root,25);
	root=Insert(root,5);
	int n;
	
	cout<<endl<<"PREORDER TRAVERSAL:		"<<endl;
	PreOrderTraversal(root);
	cout<<endl<<"INORDER TRAVERSAL:		"<<endl;
	InOrderTraversal(root);
	cout<<endl<<"POSTORDER TRAVERSAL:		"<<endl;
	PostOrderTraversal(root);
	
	cout<<endl<<"MIN HEAP--: "<<endl;
	MinHeap(root);
	InOrderTraversal(root);
	
	cout<<endl<<"enter the number you want to search"<<endl;
	cin>>n;
	if(Search(root,n)==true)
	cout<<endl<<"Search successful"<<endl;
	else
	cout<<endl<<"Search unsuccessful"<<endl;
	return 0;
}
