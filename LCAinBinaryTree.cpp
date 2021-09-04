#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
		
		Node()
		{
			data=0;
			left=right=NULL;
		}	
};
Node* CreateNode(int data)
{
	Node* n=(Node*)malloc(sizeof(Node));
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	return n;
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
 
 Node* LCA(Node* root,int n1,int n2)
 {
 	if(root==NULL)
 	return NULL;
 	if(root->data==n1 || root->data==n2)
 	{
 		return root;
	 }
	 Node* Left=LCA(root->left,n1,n2);
	 Node* Right=LCA(root->right,n1,n2);
	 
	 if(Left!=NULL && Right!=NULL)
	 return root;
	 if(Left==NULL && Right==NULL)
	 return NULL;
	 if(Left!=NULL)
	 {
	 	return LCA(root->left,n1,n2);
	 }
	 return LCA(root->right,n1,n2);
 }
 
// 		1
// 	   / \
// 	  2   3
// 	 / \ / \
// 	4  5 6  7
// /
//8
// BINARY TREE
 
int main()
{
	Node* res;
	Node* root=CreateNode(1);
	root->left=CreateNode(2);
	root->right=CreateNode(3);
	root->left->left=CreateNode(4);
	root->left->right=CreateNode(5);
	root->left->left->left=CreateNode(8);
	cout<<endl<<"Inorder Traversal : "<<endl;
	InOrderTraversal(root);
	
	int n1,n2;
	cout<<endl<<"Enter the value of n1 and n2"<<endl;
	cin>>n1>>n2;
	res=LCA(root,n1,n2);
	cout<<endl<<"LCA of "<<n1<<"and "<<n2<<" is : "<<endl<<res->data;
	
	return 0;
}
