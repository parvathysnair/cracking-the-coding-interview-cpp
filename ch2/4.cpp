#include<iostream>
#include<string>
#include<vector>
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

void partition(int p){
  current=head;
  vector<int> small;
  vector<int> large;
  int i;
  while(current!=NULL){
    if(current->data<p)
      small.push_back(current->data);
    else
      large.push_back(current->data);

    current=current->next;
      }
      head=NULL;current=NULL;
      for(i=0;i<small.size();i++){
        addNode(small[i]);
      }
      for(i=0;i<large.size();i++){
        addNode(large[i]);
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
  int p;
  cout<<"\nenter the partition key";
  cin>>p;
  partition(p);
  cout<<"\nafter partition: ";
  displayNode();

    return 0;
}
