//{ Driver Code Starts
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* a node of the singly linked list */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct Node*& head_ref, int new_data) {
    /* allocate node */
    struct Node* new_node = new Node(new_data);

    /* link the old list off the new node */
    new_node->next = head_ref;

    /* move the head to point to the new node */
    head_ref = new_node;
}

/* A utility function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends

/* a node of the singly linked list
struct node
{
    int data;
    struct node *next;

    node(int x){
        data = x;
        next = NULL;
    }
}; */

// Solution class with quickSort function
class Solution {
  public:
    Node* partition(Node* head, Node* tail){
        Node* pivot=head, *prev=head, *temp=head;
        while(temp!=tail->next){
            if(pivot->data > temp->data){
                swap(prev->next->data, temp->data);
                prev=prev->next;
            }
            temp=temp->next;
        }
        
        swap(pivot->data, prev->data);
        
        return prev;
    }
  
    void helper(Node* head, Node* tail){
        if(!head || head==tail){
            return;
        }
        
        Node* pivot=partition(head, tail);
        
        helper(head, pivot);
        helper(pivot->next, tail);
        
        return;
    }
  
    struct Node* quickSort(struct Node* head) {
        // code here
        if(!head || !head->next) return head;
        
        Node* tail=head;
        
        while(tail->next){
            tail=tail->next;
        }
        
        helper(head, tail);
        
        return head;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after reading t

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        head = ob.quickSort(head);

        printList(head);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends