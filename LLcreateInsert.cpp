#include <iostream>
using namespace std;


struct Node{
  
  int data;
  Node* next;
  
  Node(int val){
    data=val;
    next=NULL;
  }
  
};
int main() 
{
  Node* n1=new Node(2);
  Node* n2=new Node(4);
  Node* n3=new Node(6);
  Node* n4=new Node(8);
  Node* n5=new Node(10);
  
  
  n1->next=n2;
  n2->next=n3;
  n3->next=n4;
  n4->next=n5;
  
  //inserting n6 between n3 and n4-
  Node* n6=new Node(7);
  n3->next=n6;
  n6->next=n4;
  
  
  //inserting at head
  Node* n0=new Node(1);
  n0->next=n1;
  
  // cout<<"n0 data "<<n0->data<<endl;
  // cout<<"n1 data "<< n1->data<<endl;
  n1=n0;
  // cout<<"n0 data "<<n0->data<<endl;
  // cout<<"n1 data "<< n1->data<<endl;
  Node* curr=n1;
  
  //inserting at tail
  Node* n7=new Node(11);
  n5->next=n7;
  
  
  
  curr=n1;
  while(curr!= NULL){
    cout<< "data : "<<curr->data<<" ";
    curr=curr->next;
  }
  
  
}