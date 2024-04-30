//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    Node *reverse(Node *head){
        Node *prev=NULL,*curr=head,*nxt=NULL;
        while(curr){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        // code here
        Node *temp=NULL;
        while(num1 and num1->data==0){
            temp=num1;
            num1=num1->next;
        }
        if(temp)temp->next=NULL;
        temp=NULL;
        while(num2 and num2->data==0){
            temp=num2;
            num2=num2->next;
        }
        if(temp)temp->next=NULL;
        if(!num1 and !num2)return new Node(0);
        if(!num1)return num2;
        if(!num2)return num1;
        num1=reverse(num1);
        num2=reverse(num2);
        temp=new Node(1);
        Node *head1=num1,*head2=num2,*ans=temp;
        int carry=0;
        while(head1 and head2){
            int sum = head1->data+head2->data+carry;
            carry=sum/10;
            temp->next=new Node(sum%10);
            temp=temp->next;
            head1=head1->next;
            head2=head2->next;
        }
        while(head1){
            int sum = head1->data+carry;
            carry=sum/10;
            temp->next=new Node(sum%10);
            temp=temp->next;
            head1=head1->next;
        }
        while(head2){
            int sum = head2->data+carry;
            carry=sum/10;
            temp->next=new Node(sum%10);
            temp=temp->next;
            head2=head2->next;
        }
        if(carry)temp->next=new Node(carry);
        return reverse(ans->next);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends