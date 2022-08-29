//{ Driver Code Starts
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

void append(struct Node** headRef, struct Node** tailRef, int newData) {
    struct Node* new_node = new Node(newData);

    if (*headRef == NULL) {
        *headRef = new_node;
    }

    else {
        (*tailRef)->next = new_node;
    }
    *tailRef = new_node;
}

void printList(struct Node* head) {
    while (head) {
        cout << head->data << ' ';
        head = head->next;
    }
}


// } Driver Code Ends
/*
Structure of the node of the linked list is as
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
  public:
  
        
    // your task is to complete this function
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        // Code here
        if(!head1 or !head2)
            return 0;
        int cnt=0;
        Node* tmp1=head1, *tmp2=head2;
        unordered_set<int> s1,s2;
        while(tmp1)
        {
            s1.insert(tmp1->data);
            tmp1=tmp1->next;
        }
        while(tmp2)
        {
            s2.insert(tmp2->data);
            tmp2=tmp2->next;
        }
        for(auto it: s1)
        {
            if(s2.find(x-it)!=s2.end())
                cnt++;
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        struct Node* head1 = NULL;
        struct Node* tail1 = NULL;
        struct Node* tail2 = NULL;
        struct Node* head2 = NULL;
        int n1, n2, tmp, x;
        cin >> n1;
        while (n1--) {
            cin >> tmp;
            append(&head1, &tail1, tmp);
        }
        cin >> n2;
        while (n2--) {
            cin >> tmp;
            append(&head2, &tail2, tmp);
        }
        cin >> x;
        Solution obj;
        cout << obj.countPairs(head1, head2, x) << '\n';
    }
    return 0;
}
// } Driver Code Ends
