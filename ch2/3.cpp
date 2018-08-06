#include<iostream>
#include<string>
using namespace std;

struct node{
  int data;
  node *next;
}*current,*head,*temp;

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

void deletemid(){
  int n=0,index,j=1;
  current=head;
  while(current!=NULL){
    n++;
    current=current->next;
  }
  index=n/2;
  // cout<<"size:"<<n;
  // cout<<"index:"<<index;
  if(index<=1){
    return;
  }
  current=head;
  while (j<index) {
    j++;
    current=current->next;
  }
  current->next=current->next->next;

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


deletemid();
cout<<"\nthe new node elements:";
displayNode();


    return 0;
}
