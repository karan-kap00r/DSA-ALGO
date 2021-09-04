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
void PreOrderTraversal(Node* n)
{
	if(n!=NULL)
	{
		cout<<" "<<n->data;
		PreOrderTraversal(n->left);
		PreOrderTraversal(n->right);
	}
}
 
// 		1
// 	   / \
// 	  2   3
// 	 / \ / \
// 	4  5 6  7
// BINARY TREE
 
 int Sum(Node* root)
 {
 	if(root==NULL)
 	return 0;
 	
 	root->data=Sum(root->left)+Sum(root->right)+root->data;
 	return root->data;
 }
 
int main()
{
	Node* root=CreateNode(1);
	root->left=CreateNode(2);
	root->right=CreateNode(3);
	root->left->left=CreateNode(4);
	root->left->right=CreateNode(5);
	root->right->left=CreateNode(6);
	root->right->right=CreateNode(7);
	cout<<endl<<"Preorder Traversal : "<<endl;
	PreOrderTraversal(root);
	
	int x=Sum(root);
	cout<<endl<<"SUM is : "<<endl<<x;
	
	cout<<endl<<"Preorder Traversal After Replacement : "<<endl;
	PreOrderTraversal(root);
	return 0;
}
