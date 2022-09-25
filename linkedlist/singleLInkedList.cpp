#include<iostream>
using namespace std;

class node{
  public:
  int data;
  node* next;
  
  node(int d){
      data = d;
      next = NULL;
  }
};
void insertAtTail(node* &tail,int data){
  node* n = new node(data);
  tail->next = n;
  tail = n;
}
void insertAtHead(node* &head,int data){
    node* n = new node(data);
    n->next = head;
    head = n;
}
void insertAtpos(node* &tail,node* &head,int pos,int d){
  node* temp = head;
  int cnt = 1;
  if(pos == 1){
    insertAtHead(head,d);
    return;
  }
  while(cnt<pos-1){
    temp = temp->next;
    cnt++;
  }
   if(temp->next == NULL){
    insertAtTail(tail,d);
    return;
  }
  node* n = new node(d);
  n->next = temp->next;
  temp->next = n;

}
void delete_node(node* &head,node* &tail,int pos){
  // ye case hogya agar first element remove karna hain
  if(pos == 1){
    node* temp = head;
    int value = temp->data;
    head = head->next;
    temp->next = NULL;
    delete temp;
    cout<<"The memory is free for "<<value<<endl;
  }
  // ye baaki sabke lie hain
  else{
    int cnt = 1;
    node* curr = head;
    node* prev = NULL;
    while(cnt<pos){
      prev = curr;
      curr = curr->next;
      cnt++;
    }
    // ye case hogya agar last element remove karna hain
    if(curr->next == NULL){
      int value = curr->data;
      prev->next = NULL;
      tail = prev;
      delete curr;
        cout<<"The memory is free for "<<value<<endl;
      return;
    }
    // ye baaki ke lie
    int value = curr->data;
    // curr mein tera element hain jo delete karna hain
    // aur prev mein usse pehla vaala kyunki un dono ko hi change karna hain
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
    cout<<"The memory is free for "<<value<<endl;
  }
}
void print(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
int main(){
  node* node1 = new node(10);
  node* head = node1;
  node* tail = node1;
  print(head);
  insertAtTail(tail,20);
  insertAtTail(tail,50);
  insertAtTail(tail,60);
  print(head);
  insertAtpos(tail,head,1,100);
  print(head);
  insertAtpos(tail,head,6,200);
  print(head);
  delete_node(head,tail,6);
  print(head);
  cout<<head->data<<endl;
  cout<<tail->data<<endl;
  return 0;
}