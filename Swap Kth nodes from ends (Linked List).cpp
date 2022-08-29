//{ Driver Code Starts
#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



Node *swapkthnode(Node* head, int num, int K);

void addressstore(Node **arr, Node* head)
{
    Node* temp = head;
    int i = 0;
    while(temp){
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(Node ** before, Node **after, int num, int K)
{
    if(K > num)
        return 1;
    return (before[K-1] == after[num - K]) && (before[num-K] == after[K-1]);
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        int num, K , firstdata;
        cin>>num>>K;
        int temp;
        cin>>firstdata;
        Node* head = new Node(firstdata);
        Node* tail = head;
        for(int i = 0; i<num - 1; i++){
            cin>>temp;
            tail->next = new Node(temp);
            tail = tail->next;
        }
        
        Node *before[num];
        addressstore(before, head);
        
        head = swapkthnode(head, num, K);
        
        Node *after[num];
        addressstore(after, head);
        
        if(check(before, after, num, K))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}

// } Driver Code Ends


//User function Template for C++

/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
     Node(int x) {
        data = x;
        next = NULL;
  }
  }
*/

//Function to swap Kth node from beginning and end in a linked list.
Node *swapkthnode(Node* head, int num, int K)
{
   // Your Code here
   int M = num - K + 1;        //second node position
   if(M < K) swap(M, K);       //K always less then M
   if(num == 1 || K > num || M > num || M == K) return head; //edge cases
   Node * temp;
   Node * node1 = head;
   Node * node2 = head;
   K--; M--;                   //go to previous node positions
   for(int i = 1; i < K; i++) node1 = node1->next;
   for(int i = 1; i < M; i++) node2 = node2->next;
   
   if(!K)                      //if the first position is the head
   {
       temp = node2->next;
       temp->next = head->next;
       node2->next = head;
       head->next = NULL;
       head = temp;
   }
   else
   {
       temp = node1->next;
       node1->next = node2->next;
       node2->next = temp;
       temp = temp->next;
       node2->next->next = node1->next->next;
       node1->next->next = temp;
   }
   return head;
}

