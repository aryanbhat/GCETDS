#include<iostream>
using namespace std;

class node{
  public:
  int data;
  node* next;
  node(int data){
      this->data = data;
      this->next = NULL;
  }
};

void insertNode(node* &tail,int key,int d){
  if(tail == NULL){
    node* n = new node(d);
    tail = n;
    n->next = n;
    return;
  }
  else{
  node* curr = tail;
  while(curr->data != key){
    curr = curr->next;
  }
  node* n = new node(d);
  n->next = curr->next;
  curr->next = n;
  }
}
void deleteNode(node* &tail,int key){
  if(tail == NULL){
    cout<<" The list is empty"<<endl;
    return;
  }
  else{
    node* prev = NULL;
    node* curr = tail;
    while(curr->data != key){
      prev = curr;
      curr = curr->next;
    } 
    if(curr == prev){
      tail = NULL;
    }
    else if(curr == tail){
      tail = prev;
    }
    prev->next = curr->next;
      if(curr == prev){
      tail = NULL;
    }
    else if(curr == tail){
      tail = prev;
    }
    curr->next = NULL;
    cout<<"Memory is free for "<<key<<" ";
    cout<<endl;
    delete(curr);
  }
}
void print(node* tail){
  if(tail == NULL){
    cout<<"The list is empty "<<endl;
    return;
  }
  node* temp = tail;
    cout<<tail->data<<" ";
    while(tail->next != temp){
      tail = tail->next;
      cout<<tail->data<<" ";
    }
    cout<<endl;
}
int main(){
  node* tail = NULL;
  insertNode(tail,0,10);
  //print(tail);
  insertNode(tail,10,20);
  //print(tail);
  insertNode(tail,20,30);
  //print(tail);
  insertNode(tail,10,40);
  //print(tail);
  insertNode(tail,40,50);
  print(tail);
  deleteNode(tail,50);
  deleteNode(tail,40);
  deleteNode(tail,30);
  deleteNode(tail,20);
  print(tail);
  deleteNode(tail,10);
  // print(tail);
  cout<<tail<<endl;
  return 0;
}