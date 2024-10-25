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

Node *binaryTree(){
    int x;
    cin>>x;
    if(x==-1){
        return NULL;
    }
    Node *temp=new Node(x);
    cout<<"Enter left child for "<<x<<" : ";
    temp->left=binaryTree();
    cout<<"Enter right child for "<<x<<" : ";
    temp->right=binaryTree();
    return temp;
}
void pre(Node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    pre(root->left);
    pre(root->right);
}
int count(Node* root,int &c){
    if(root==NULL){
        return 0;
        
    }
    c++;
    count(root->left,c);
    count(root->right,c);
    return c;
    
}
void level(Node* root){
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

int count1(Node *root){
    if(root==NULL){
        return 0;
    }
    return 1+count1(root->left)+count1(root->right);
}
int sumBT(Node *root,int &sum){
    if(root==NULL){
        return 0;
    }
    sum=sum+root->data;
    sumBT(root->left,sum);
    sumBT(root->right,sum);
    return sum;
}
int sum1(Node *root){
    if(root==NULL){
        return 0;
    }
    
    return root->data+sum1(root->left)+sum1(root->right);
}
int countLeafNode(Node *root,int &count0){
    if(root==NULL){
        return 0;
    }
    if((root->left==NULL) && (root->right==NULL)){
        count0 ++;
    }
    countLeafNode(root->left,count0);
    countLeafNode(root->right,count0);
    return count0;
}
int main() {
    Node *root;
    root=binaryTree();
    cout<<endl;
    cout<<"PreOrder: ";
    pre(root);
    cout<<endl;
    int c=0;
    int co=count(root,c);
    cout<<"Node count:"<<co<<endl;
    cout<<"Level order traversal : ";
    level(root);
    cout<<endl;
    int totalNode=count1(root);
    cout<<"Total Node count: "<< totalNode<<endl;
    int sum=0;
    int s=sumBT(root,sum);
    cout<<"Sum : "<<s<<endl;
    int su=sum1(root);
    cout<<"Another way also give sum = "<<su<<endl;
    int count0=0;
    int leafTotal=countLeafNode(root,count0);
    cout<<"Total leaf node : "<<leafTotal;
    
    
    
    

    return 0;
}