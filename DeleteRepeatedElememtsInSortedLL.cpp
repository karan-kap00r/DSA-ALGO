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
void InsertNode(Node** start_ref,int data)
{
	Node* n=(Node*)malloc(sizeof(Node));
	n->data=data;
	n->next=*start_ref;
	*start_ref=n;
}
void PrintList(Node* ptr)
{
	while (ptr!=0)
	{
		cout<<ptr->data<<"-->";
		ptr=ptr->next;
	}
	cout<<endl;
}
Node* swap(Node* ptr1,Node* ptr2)
{
	Node* temp;
	temp=ptr2->next;
	ptr2->next=ptr1;
	ptr1->next=temp;
	return ptr2;
}
Node* Sort(Node** head,int count)
{
	Node** h;
	int i,j,swapped;
	for(i=0;i<=count;i++)
	{
		h=head;
		swapped=0;
		for(j=0;j<count-1-i;j++)
		{
			Node* p1=*h;
			Node* p2=p1->next;
			if(p1->data>p2->data)
			{
				*h=swap(p1,p2);
				swapped=1;
			}
			h=&(*h)->next;
		}
		if( swapped==0)
		break;
	}
}
void Test(Node* head)
{
	Node* n1=head;
	Node* n2;
	while (n1->next!=NULL)
	{
		if(n1->data==n1->next->data)
		{
			n2=n1->next->next;
			free(n1->next);
			n1->next=n2;
		}
		else
		n1=n1->next;
	}
}
int main()
{
	Node* start=NULL;
	InsertNode(&start,3);
	InsertNode(&start,9);
	InsertNode(&start,9);
	InsertNode(&start,9);
	InsertNode(&start,5);
	cout<<"The list before sorting :"<<endl;
	PrintList(start);
	Sort(&start,5);
	cout<<endl<<"The list after sorting :"<<endl;
	PrintList(start);
	Test(start);
	cout<<endl<<"The list with distinct elements :"<<endl;
	PrintList(start);
	return 0;
}
