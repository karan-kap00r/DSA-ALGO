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

int SumAtK(Node* root,int k)
{
	queue<Node*> q;
	if(root==NULL)
		return -1;
	q.push(root);
	q.push(NULL);
	int level=0;
	int sum=0;
	int maxSum=0;
	while(!q.empty())
	{
		Node* node=q.front();
		q.pop();
		if(node!=NULL)
		{
			sum+=node->data;
			cout<<node->data<<" ";
			if(level==k)
			{
				maxSum=sum;
			}
			if(node->left)
				q.push(node->left);
			if(node->right)
				q.push(node->right);
		}
		else if(!q.empty())
		{
			cout<<" -> ";
			q.push(NULL);
			level++;
		}	
	}
	return maxSum;
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
    int k;
    cout<<"Enter the value of K:"<<endl;
    cin>>k;
    if(SumAtK(root,k)!=0)
    cout << "\nSum of elements upto Kth Level is : "<<SumAtK(root,k);
    else
    cout<<endl<<"Wrong Input..."<<endl;
    return 0;
}
