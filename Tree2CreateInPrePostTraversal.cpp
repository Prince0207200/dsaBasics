// Online C++ compiler to run C++ program online
#include <iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node *left,*right;
    
    Node(int val){
        data=val;
        left=right=NULL;
    }
};

Node * BinaryTree(){
    int x;
    cin>>x;
    if(x==-1){
        return NULL;
    }
    Node *temp=new Node(x);
    cout<<"Enter the left childof "<<x<<":";
    temp->left=BinaryTree();
    cout<<"Enter the right childof "<<x<<":";
    temp->right=BinaryTree();
    return temp;
}
void PreOrder(Node* root){
    //NLR
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
    
}
void InOrder(Node *root){
    if(root==NULL){
        return;
    }
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}
void PostOrder(Node *root){
    if(root==NULL){
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";
}
void levelOrderTraversal(Node *root){
    if(root==NULL){
        return;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node *temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left!=NULL){
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }
    }
}
int main() {
    // Write C++ code here
    Node *root;
   root=BinaryTree();
   cout<<endl;
   PreOrder(root);
   cout<<endl;
   InOrder(root);
   cout<<endl;
   PostOrder(root);
   cout<<endl;
   levelOrderTraversal(root);
   

    return 0;
}