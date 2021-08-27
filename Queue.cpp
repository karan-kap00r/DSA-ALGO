
//	QUEUE

#include<bits/stdc++.h>
using namespace std;

class Queue{
	private:
		int front;
		int rear;
		int arr[5];
	public:
		Queue()
		{
			front=-1;
			rear=-1;
			for(int i=0;i<5;i++)
			{
				arr[i]=0;
			}
		}
		bool isEmpty(Queue q)
		{
			if(front==-1 && rear==-1)
			return true;
			else 
			return false;
		}
		bool isFull(Queue q)
		{
			if(rear==sizeof(arr)-1)
			return true;
			else 
			return false;
		}
		void Enqueue(Queue q,int item)
		{
			if(isFull(q)){
			cout<<endl<<"Queue is full"<<endl;
			return ;}
			else if(isEmpty(q))
			rear=front=0;
			else
			rear++;
			
			arr[rear]=item;
		}
		int Dequeue(Queue q)
		{
			int x=0;
			if (isEmpty(q)){
				cout<<endl<<"Queue is empty"<<endl;
			return 0;
		}
			else if(rear==front)
			{
				x=arr[front];
				arr[front]=0;
				front=rear=-1;
			}
			else
			{
				x=arr[front];
				arr[front]=0;
				front++;
			}
			return x;
		}
		void Display(Queue q)
		{
			cout<<endl<<"Values are: "<<endl;
			for(int i=0;i<5;i++)
			{
				cout<<arr[i]<<" ";
			}
		}
		int count(Queue q)
		{
			return ((rear-front )+1);
		}
};

int main()
{
	int opt;
	Queue Q;
	do{
	cout<<endl<<"choose the option"<<endl;
	cout<<endl<<"1 for enqueue"<<endl<<"2 for dequeue"<<endl<<"3 for check if the queue is empty"<<endl<<"4 for check if the queue is full"<<endl<<"5  for display"<<endl<<"6 for clear screen"<<endl<<"7 for size pf the Queue"<<endl<<"0 for EXIT";
	cin>>opt;
	switch(opt)
	{
		case 1:
			{
				int data;
				cout<<"enter the element you want to add into the queue"<<endl;
				cin>>data;
				Q.Enqueue(Q,data);
				break;
			}
		case 2:
			{
				int y=Q.Dequeue(Q);
				cout<<"deleted element is : "<<y;
				break;
			}
		case 3:
			{
				if(Q.isEmpty(Q))
				cout<<endl<<"Queue is Empty"<<endl;
				else
				cout<<endl<<"Queue is not Empty"<<endl;
				break;
			}
		case 4:
			{
				if(Q.isFull(Q))
				cout<<endl<<"Queue is Full"<<endl;
				else
				cout<<endl<<"Queue is not Full"<<endl;
				break;
			}
		case 5:
			{
				Q.Display(Q);
				break;
			}
		case 6:
			{
				system("cls");
				break;
			}
		case 7:
		{
				int s=Q.count(Q);
				cout<<"size of the queue is : "<<s;
				break;
		}
		case 0:
			{
				cout<<endl<<"EXIT"<<endl;
				break;
			}
		default:
			{
				cout<<"WRONG INPUT";
			}
		}
	}while(opt!=0);
	return 0;
}
