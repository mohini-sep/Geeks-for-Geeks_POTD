//{ Driver Code Starts
// C++ program to find predecessor and successor in a BST
#include "bits/stdc++.h"
using namespace std;

// BST Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};


// } Driver Code Ends

/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    void inorder(Node* root, vector<Node*>& result) {
        if (!root) {
            return;
        }
        inorder(root->left, result);         // Traverse left subtree
        result.push_back(root);              // Visit current node
        inorder(root->right, result);        // Traverse right subtree
    }
    // Function to find predecessor and successor of given key
    vector<Node*> findPreSuc(Node* root, int key) {
        vector<Node*> result;                // Vector to store inorder traversal result

        inorder(root, result);               // Fill the vector with inorder traversal

        Node* pre = NULL;                    // Pointer to store predecessor
        Node* suc = NULL;                    // Pointer to store successor

        for (int i = 0; i < result.size(); i++) {
            if (result[i]->data < key) {
                pre = result[i];             // Keep updating predecessor until key is found
            } else if (result[i]->data > key) {
                suc = result[i];             // First greater element after key is the successor
                break;
            } else {
                if (i - 1 >= 0) {
                    pre = result[i - 1];     // Element before key is predecessor
                }
                if (i + 1 < result.size()) {
                    suc = result[i + 1];     // Element after key is successor
                }
                break;                       // Break after finding key
            }
        }
        return { pre, suc };   
    }
};


//{ Driver Code Starts.

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

    // Create the root of the tree
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

// Driver program to test above functions
int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        getline(cin, s);
        int key = stoi(s);

        Solution ob;
        vector<Node*> result = ob.findPreSuc(root, key);
        Node* pre = result[0];
        Node* suc = result[1];

        if (pre != nullptr)
            cout << pre->data << " ";
        else
            cout << -1 << " ";

        if (suc != nullptr)
            cout << suc->data << endl;
        else
            cout << -1 << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends