//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree.....
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    void store_left(Node* root,stack<Node*>& st){
        Node* curr = root;
        while(curr != NULL){
            st.push(curr);
            curr = curr->left;
        }
    }
    vector<int> merge(Node *root1, Node *root2) {
        stack<Node*> st1,st2;
        
        vector<int> ans;
        
        store_left(root1,st1);
        store_left(root2,st2);
        
        while(!st1.empty() && !st2.empty()){
            
            if(st1.top()->data < st2.top()->data){
                Node* curr = st1.top();
                st1.pop();
                ans.push_back(curr->data);
                store_left(curr->right,st1);
            }
            else if(st2.top()->data < st1.top()->data){
                Node* curr = st2.top();
                st2.pop();
                ans.push_back(curr->data);
                store_left(curr->right,st2);
            }
            else{
                Node* curr1 = st1.top();
                Node* curr2 = st2.top();
                
                st1.pop();
                st2.pop();
                
                ans.push_back(curr1->data);
                ans.push_back(curr2->data);
                
                
                store_left(curr1->right,st1);
                store_left(curr2->right,st2);
            }
        }
        
        while(!st1.empty()){
            Node* curr1 = st1.top();
            st1.pop();
            ans.push_back(curr1->data);
            store_left(curr1->right,st1);
        }
        while(!st2.empty()){
            Node* curr2 = st2.top();
            st2.pop();
            ans.push_back(curr2->data);
            store_left(curr2->right,st2);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root1 = buildTree(s);

        getline(cin, s);
        Node* root2 = buildTree(s);

        // getline(cin, s);
        Solution obj;
        vector<int> vec = obj.merge(root1, root2);
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;
        /// cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends