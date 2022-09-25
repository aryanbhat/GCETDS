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

void print(node* tail){
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
  print(tail);
  insertNode(tail,10,20);
  print(tail);
  return 0;
}