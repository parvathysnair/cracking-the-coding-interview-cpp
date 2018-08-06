#include<iostream>
#include<string>
using namespace std;

struct node{
  int data;
  node *next;
}*current,*head,*temp,*prev;

void addNode(int d){
  //cout<<"hello add";
   temp=new node;
  temp->data=d;
  temp->next=NULL;

  if(head==NULL){
    head=temp;
  }
  else{
    current=head;
    while(current->next!=NULL){
      current=current->next;
    }
    current->next=temp;
    current=current->next;
  }
  return;
}


void displayNode(){
  current=head;
  while(current!=NULL){
    cout<<current->data<<" ";
    current=current->next;
  }
}

void removeDuplicate(){
  current=head;

  while(current->next!=NULL){
    prev=current;
    temp=current->next;
    while(temp!=NULL){
      if(current->data==temp->data){
          if(temp->next==NULL){
            prev->next=NULL;break;
          }
          else{
            prev->next=temp->next;
            temp=temp->next;
          }

      }
      else{
        prev=temp;
        temp=temp->next;
      }

    }
    if(current->next==NULL)
    break;
        current=current->next;
      }
    return;
}


int main(){
  int d;

  current=NULL;
  head=NULL;
  int a[20],n;

  //adding elements
  cout<<"enter the size\n";
  cin>>n;
  cout<<"enter the node elements";
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for(int i=0;i<n;i++){
    addNode(a[i]);
  }


  //display node
  cout<<"\nthe elements are: ";
  displayNode();


  //remove duplicate
  removeDuplicate();
  cout<<"\nthe modified elements are: ";
  displayNode();

    return 0;
}
