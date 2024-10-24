#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int main() {
    int x;
    cout << "Enter root element: ";
    cin >> x;

    int first, second;
    queue<Node*> q; 
    Node *root = new Node(x);
    q.push(root);

    // Building binary tree
    while (!q.empty()) {
        // Creating a temp node by adding the value at the front of the queue
        Node *temp = q.front();
        q.pop();
        
        // Left child
        cout << "Enter left node of " << temp->data << " (-1 for no node): ";
        cin >> first;  // first node value
        if (first != -1) {
            temp->left = new Node(first);
            q.push(temp->left);
        }

        // Right child
        cout << "Enter right node of " << temp->data << " (-1 for no node): ";
        cin >> second;  // second node value
        if (second != -1) {
            temp->right = new Node(second);
            q.push(temp->right);
        }
    }

    return 0;
}
