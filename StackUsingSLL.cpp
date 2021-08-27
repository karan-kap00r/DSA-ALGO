
//IMPLEMENTATION OF STACK USING SINGLY LINKED LIST:

#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		int data;
		int key;
		Node* next;
		Node()
		{
			data=0;
			next=NULL;
			key=0;
		}
		Node(int data , int key)
		{
			data=data;
			key=key;
		}
};
class Stack{
	public:
		Node* head;
		Stack()
		{
			head=NULL;
		}
		Stack(Node* n)
		{
			head=n;
		}
		
		//	1. Chech if a Node exists using key value or not :
		Node* nodeExists(int k)
		{
			Node* temp=NULL;
			Node* ptr=head;
			while(ptr!=NULL)
			{
				if(ptr->key==k)
				{
					temp=ptr;
				}
				ptr=ptr->next;
			}
			return temp;
		}
		
		//	2. Push :
		void Push(Node* n)
		{
			if(nodeExists(n->key)!=NULL)
			{
				cout<<"Unable to Push a node with key value : "<<n->key<<" .Try with different key value."<<endl;
			}
			else{
				if(head==NULL)
				{
					head=n;
					cout<<"Node Pushed"<<endl;
				}
				else
				{
					Node* temp=head;
					while(temp->next!=NULL)
					{
						temp=temp->next;
					}
					temp->next=n;
					n->next=NULL;
					cout<<endl<<"Node Pushed.."<<endl;
				}
			}
		}
		
//		3.Pop :
		int Pop()
		{
			if(head==NULL)
			{
				cout<<endl<<"Can not pop an item ..as Stack is already Empty"<<endl;
				return -1;
			}
			else
			{
				if(head->next!=NULL)
				{
					Node* temp=head;
					while(temp->next->next!=NULL)
					{
						temp=temp->next;	
					}
					int x=temp->next->data;
					temp->next=NULL;
					return x;
				}
				else
				{
					int x=head->data;
					head=NULL;
					cout<<endl<<"Item Popped...and Stack is Empty now"<<endl;
					return x;
				}
			}
		}
		
//		4.Peek:
		int Peek()
		{
			Node* temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			int c=temp->data;
			return c;
		}
		
//		5. Size:
		int Size()
		{
			Node* temp=head;
			int count=-1;
			while(temp!=NULL)
			{
				count++;
				temp=temp->next;
			}
			return count;
		}
		
	//	7.Printing the list:
	void printList()
	{
		if(head==NULL)
		{
			cout<<"The List is Empty";
		}
		else
		{
			Node* ptr=head;
			cout<<" the list has values : "<<endl;
			while(ptr!=NULL)
			{
				cout<<"( "<<ptr->key<<","<<" "<<ptr->data<<")-->";
				ptr=ptr->next;
			}
		}
	}
	
//	8. IsEmpty:
		int IsEmpty()
		{
			if(head==NULL)
			return 1;
			else
			return 0;
		}
};

int main()
{
	Stack s;
	int option;
	int key1,k1,data1;
	do
	{
		cout<<endl<<"Select the operation you want to perform OR Press 0 to EXIT."<<endl;
		cout<<"1. Push()"<<endl;	
		cout<<"2. Pop()"<<endl;	
		cout<<"3. Peek()"<<endl;	
		cout<<"4. Size()"<<endl;	
		cout<<"5. IsEmpty()"<<endl;
		cout<<"6. printList()"<<endl;	
		cout<<"7. Clear Screen()"<<endl;	
		
		cin>>option;
		Node* n1=new Node();		//DYNAMIC MEMORY ALLOCATION
		
		switch(option)
		{
			case 0:
				{
				break;
				}
			case 1:
				{
				cout<<"PUSH Operation"<<endl<<"Enter the value of Key , Data of a Node to be Pushed."<<endl;
				cin>>key1;
				cin>>data1;
				n1->key=key1;
				n1->data=data1;
				s.Push(n1);
				break;
				}
			case 2:
				{
				cout<<endl<<"POP Operation"<<endl;		
				int l=s.Pop();
				cout<<"Popped item is "<<l<<endl;
				break;
				}
			case 3:
				{
				cout<<endl<<"PEEK Operation"<<endl;			
				int j=s.Peek();
				cout<<"Element at the Top is "<<j<<endl;
				break;
				}
			case 4:
				{
				cout<<endl<<"SIZE Operation"<<endl;
				int f=s.Size();
				cout<<"Size of the Stack is : "<<f<<endl;
				break;
				}
			case 5:
				{
				if(s.IsEmpty()==1)
				cout<<endl<<"Stack is Empty"<<endl;
				else
				cout<<endl<<"Stack is not Empty"<<endl;
				break;
				}
			case 6:
				{
				cout<<endl<<"Print List Operation"<<endl;
				s.printList();
				break;
				}
			case 7:
				{
				system("cls");
				break;
				}
			default :
				cout<<"Enter the Valid Option"<<endl;
			}
		}
		while(option!=0);
		return 0;
}


