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
 
 void LeftView(Node* root)
 {	
 	if(root==NULL)
 	return ;
 	
 	queue<Node*>q;
 	q.push(root);
 	while(!q.empty())
 	{
 		int n=q.size();
 		for(int i=0;i<n;i++)
 		{
 			Node* curr=q.front();
 			q.pop();
 			
 			if(i==0)			//LEFT VIEW CONDITION
 			{
 				cout<<curr->data<<" ";
			}
			if(curr->left)
			q.push(curr->left);
			
			if(curr->right)
			q.push(curr->right);
		 }
	 }
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
	
	cout<<endl<<"LEFT VIEW : "<<endl;
	LeftView(root);
	return 0;
 }
