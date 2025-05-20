/*
class Node {
  public:
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
    int minTime(Node* root, int target) {
        // code here
        queue<Node*> que;

        que.push(root);

        unordered_map<Node*, Node*> parent; // To store parent of each node
        parent[root] = nullptr;

        Node* tar = nullptr; // Pointer to store target node

        while (!que.empty()) {
            Node* curr = que.front();
            que.pop();

            if (curr->data == target) {
                tar = curr;
            }

            if (curr->left) {
                que.push(curr->left);
                parent[curr->left] = curr;
            }

            if (curr->right) {
                que.push(curr->right);
                parent[curr->right] = curr;
            }
        }

        unordered_map<Node*, bool> visited; 
        int t = -1;                         
        que.push(tar);                  

        while (!que.empty()) {
            int n = que.size();

            while (n--) {
                Node* curr = que.front();
                que.pop();

                visited[curr] = true; 

                if (curr->left && !visited[curr->left]) {
                    que.push(curr->left);
                }

                if (curr->right && !visited[curr->right]) {
                    que.push(curr->right);
                }

                if (parent[curr] && !visited[parent[curr]]) {
                    que.push(parent[curr]);
                }
            }
            t++; 
        }
        return t;
    }
};