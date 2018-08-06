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
  if(head==NULL)
  cout<<"empty";
  current=head;
  while(current!=NULL){
    cout<<current->data<<" ";
    current=current->next;
  }
}

void removekth(int k){
  int n,index,j=1;
  current=head;
  while(current!=NULL){
    n++;
    current=current->next;
  }
  if(n==1&&k==1){
  //  cout<<"empty";
    head=NULL;return;
  }
  if(n==1 && k>1){
    cout<<"invalid entry";
    return;
  }
  index=n-k;
  current=head;
  while(j<index){
    j++;
    current=current->next;
  }
  current->next=current->next->next;
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
  int k;
  cout<<"\nenter the value of k:";
  cin>>k;
  removekth(k);

  cout<<"\nthe elements are: ";
  displayNode();


    return 0;
}
