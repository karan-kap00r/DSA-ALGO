
#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

class Solution
{
    public:
   struct Node* reverse(struct Node* head)
{
    struct Node* prev = NULL;
    struct Node* curr = head;
    while (curr) {
        struct Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
 
Node* reverseBetween(Node* head, int m, int n)
{
    if (m == n)
        return head;
 

    Node *revs = NULL, *revs_prev = NULL;
    Node *revend = NULL, *revend_next = NULL;
 
    int i = 1;
    Node* curr = head;
    while (curr && i <= n) {
        if (i < m)
            revs_prev = curr;
        if (i == m)
            revs = curr;
        if (i == n) {
            revend = curr;
            revend_next = curr->next;
        }
        curr = curr->next;
        i++;
    }
    revend->next = NULL;
    revend = reverse(revs);
    
    if (revs_prev)
        revs_prev->next = revend;
  
    else
        head = revend;
    revs->next = revend_next;
    return head;
}
};


/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";

	}
	return 0;
}
