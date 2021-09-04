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
 
 int Sum(Node* root)
 {
 	if(root==NULL)
 	return 0;
 	
 	int sum=Sum(root->left)+Sum(root->right)+root->data;
 	return sum;
 }
 
// 		1
// 	   / \
// 	  2   3
// 	 / \ / \
// 	4  5 6  7
// BINARY TREE
 
 
int main()
{
	Node* root=CreateNode(1);
	root->left=CreateNode(2);
	root->right=CreateNode(3);
	root->left->left=CreateNode(4);
	root->left->right=CreateNode(5);
	cout<<endl<<"Inorder Traversal : "<<endl;
	InOrderTraversal(root);
	
	int x=Sum(root);
	cout<<endl<<"SUM is : "<<endl<<x;
	
	return 0;
}
