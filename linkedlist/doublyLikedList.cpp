#include<iostream>
using namespace std;

class node{
  public:
  int data;
  node* next;
  node* prev;
  node(int data){
    this->data = data;
    next = NULL;
    prev = NULL;
  }
};
void insertAtHead(node* &head,int data){
        node* n = new node(data);
        n->next = head;
        head->prev = n;
        head = n;
}
void insertAtTail(node* &tail,int data){
  node* n = new node(data);
  tail->next = n;
  n->prev = tail;
  tail = n;
}
void insertAtPos(node* &head,node* &tail,int data,int pos){
  if(pos == 1){
    insertAtHead(head,data);
    return;
  }
  int cnt = 1;
  node* temp = head;
  while(cnt < pos-1){
    temp = temp->next;
    cnt++;
  }
  if(temp == NULL){
    insertAtTail(tail,data);
  }
  node* n = new node(data);
  n->next = temp->next;
  n->prev = temp;
  temp->next = n;
  n->next->prev = n;
}
void deletAtHead(node* &head){
  node* temp = head;
  temp = temp->next;
  head->next = NULL;
  temp->prev = NULL;
  delete(head);
  head = temp;
}
void deleteAtTail(node* &tail){
  node* temp = tail->prev;
  tail->prev = NULL;
  temp->next = NULL;
  delete(tail);
  tail = temp;
}
void deleteAtPos(node* &head,node* &tail,int pos){
  if(pos == 1){
    deletAtHead(head);
    return;
  }
  int cnt = 1;
  node* temp=head;
  while(cnt<pos){
    temp= temp->next;
    cnt++;
  }
  if(temp->next == NULL){
    deleteAtTail(tail);
    return;
  }
  temp->prev->next = temp->next;
  temp->next->prev = temp->prev;
  temp->next = temp->prev = NULL;
  delete(temp);
}
void print(node* head){
  while(head != NULL){
    cout<<head->data<<" ";
    head = head->next;
  }
  cout<<endl;
}
void printTail(node* tail){
  while(tail !=NULL){
    cout<<tail->data<<" ";
    tail = tail->prev;
  }
  cout<<endl;
}
int main(){
  node* node1 = new node(10);
  node* head = node1;
  node* tail = node1;
  insertAtHead(head,20);
  insertAtHead(head,30);
  // print(head);
  insertAtTail(tail,40);
  // print(head);
  insertAtPos(head,tail,50,2);
  print(head);
  deleteAtPos(head,tail,3);
  print(head);
  printTail(tail);
  return 0;
}