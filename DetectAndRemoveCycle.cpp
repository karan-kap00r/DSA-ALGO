#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		Node()
		{
			data=0;
			next=NULL;
		}
};
Node* InsertNode(Node** start_ref , int data)
{
	Node* n=(Node*)malloc(sizeof(Node));
	n->data=data;
	n->next=*start_ref;
	*start_ref=n;	
}
void PrintList(Node* ptr)
{
	while(ptr!=0)
	{
		cout<<ptr->data<<"-->";
		ptr=ptr->next;
	}
	cout<<endl;
}

void FormCycle(Node* head,int k)
{
	Node* temp=head;
	Node* ptr;
	while( temp->next!=NULL)
	{
		temp=temp->next;
		if(temp->data==k)
		{
			ptr=temp;
		}
	}
	temp->next=ptr;
}

void DetectAndRemoveCycle(Node* &head)
{
	Node* slow=head;
	Node* fast=head;
	do{								//Detect Cycle --Hare and Tortoise Algo
		slow=slow->next;
		fast=fast->next->next;
		
	}while(slow!=fast);
	
	fast=head;
	while(slow->next!=fast->next)
	{
		slow=slow->next;
		fast=fast->next;
	}
	slow->next=NULL;
}

int main()
{
	Node* head=NULL;
	InsertNode(&head,1);
	InsertNode(&head,2);
	InsertNode(&head,3);
	InsertNode(&head,4);
	InsertNode(&head,5);
	InsertNode(&head,6);
	FormCycle(head,4);
	DetectAndRemoveCycle(head);
	PrintList(head);
}
