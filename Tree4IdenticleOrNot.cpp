// Online C++ compiler to run C++ program online
#include <iostream>
#include<queue>
using namespace std;

struct Node{
    public:
  int data;
  Node *left ,*right;
  
  Node(int val){
      data=val;
      left=right=NULL;
      
  }
};

Node* BinaryTree(){
    int x;
    cin>>x;
    if(x==-1){
        return NULL;
    }
    Node *temp=new Node(x);
    cout<<"Enter left child of "<<temp->data<<" : ";
    temp->left=BinaryTree();
    cout<<"Enter right child of "<<temp->data<<" : ";
    temp->right=BinaryTree();
    return temp;
};

bool isIdentical(Node * root1,Node*root2){
    if(!root1&&!root2){
        return 1;
    }
    if((!root1&&root2)||(root1&&!root2)){
        return 0;
    }
    if(root1->data!=root2->data){
        return 0;
    }
    return isIdentical(root1->left,root2->left)&&isIdentical(root1->right,root2->right);
}
int main() {
   Node* r1,*r2;
   cout<<"Enter root-1 element : ";
  r1=BinaryTree();
  cout<<"Enter root-2 element : ";
  r2=BinaryTree();
  cout<<"Identical or not : ";
  isIdentical(r1,r2);
   

    return 0;
}