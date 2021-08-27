#include<bits/stdc++.h>
using namespace std;
class Node
{
	public:
		int data;
		Node* next;
	Node()
	{
		data=0;
		next=NULL;
	}
};
Node* swap(Node* ptr1,Node* ptr2)
{
	Node* temp;
	temp=ptr2->next;
	ptr2->next=ptr1;
	ptr1->next=temp;
	return ptr2;
}
int BubbleSort(Node** head,int count)
{
	Node** h;
	int i,j,swapped;
	for(int i=0;i<=count;i++)
	{
		h=head;
		swapped =0;
		for(int j=0;j<count-1-i;j++)
		{
			Node* p1=*h;
			Node* p2=p1->next;
			if(p1->data > p2->data)
			{
				*h=swap(p1,p2);
				swapped=1;
			}
			h=&(*h)->next;
		}
		if(swapped==0)
		break;
	}
}
void PrintList(Node* n)
{
	while(n!=NULL)
	{
		cout<<n->data<<"-->";
		n=n->next;
	}
	cout<<endl;
}
void InsertAtBegin(Node** start_ref,int data)
{
	Node* ptr1=(Node*)malloc(sizeof(Node));
	ptr1->data=data;
	ptr1->next=*start_ref;
	*start_ref=ptr1;
}

int main()
{
	int arr[]={62,75,79,74,8,89,65};
	int List_size,i;
	Node* start=NULL;
	List_size=sizeof(arr)/sizeof(arr[0]);
	
	for(i=0;i<List_size;i++)
	{
		InsertAtBegin(&start,arr[i]);
	}
	cout<<"list before sorting"<<endl;
	PrintList(start);
	BubbleSort(&start,List_size);
	cout<<"list after sorting"<<endl;
	PrintList(start);
	return 0;
}
