//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
  
  Node* midNode(Node* head)
  {
      if(!head or ! head->next)
        return head;
      
      Node* slow=head,*fast=head;
      while(!fast->next and ! fast->next->next)
      {
          slow=slow->next;
          fast=fast->next->next;
      }
      return slow;
  }
  
  Node* mergeTwoLists(Node* a,Node* b)
  {
      if(!a or !b)
         return (!a?b:a);
    
      Node* dummy=new Node(-1);
      Node* prev=dummy;
      Node* c1=a, *c2=b;
      
      while(c1 && c2)
      {
          if(c1->data <= c2->data)
          {
              prev->next=c1;
              c1=c1->next;
          }
          else
          {
              prev->next=c2;
              c2=c2->next;
          }
          prev=prev->next;
      }
      if(c1!=NULL)
         prev->next=c1;
      else
         prev->next=c2;
         
      return dummy->next;
  }
  
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        if(!head or !head->next)
            return head;
            
        Node* mid=midNode(head);
        Node* Nhead=mid->next;
        mid->next=NULL;
        Node* l1=mergeSort(head);
        Node* l2=mergeSort(Nhead);
        return mergeTwoLists(l1,l2);
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends
