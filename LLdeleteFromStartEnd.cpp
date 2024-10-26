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
  
  
  Node* curr=n1;
  
  
  //delete last Node
  
  if(n1==NULL){
    //nothing to delete already empty
    return 0;
  }else if(n1->next == NULL){
    //it means only one node is there delete that
    delete n1;
    n1=NULL;
    
  }else{
    Node* temp1=n1;
    while(temp1->next->next!=NULL){
      temp1=temp1->next;
    }
    delete temp1->next;
    temp1->next=NULL;
  }
  
  // DELETING FIRST Node
  
  if(n1==NULL){
    return 0;
  }else if(n1->next==NULL){
    delete n1;
    n1=NULL;
  }else{
    Node* temp2=n1;
    n1=n1->next;
    delete temp2;
    
  }
  
  curr=n1;
  while(curr!= NULL){
    cout<< "data : "<<curr->data<<" ";
    curr=curr->next;
  }
  
  
}