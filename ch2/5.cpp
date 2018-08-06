#include<iostream>
#include<string>

using namespace std;

struct node{
  int data;
  node *next;
};

class linkedlist{
  public:
  node *head;
  node *current;

  linkedlist(){
    head=NULL;
    current=NULL;
  }
  void addnode(int n)
   {
       node *tmp = new node;
       tmp->data = n;
       tmp->next = NULL;

       if(head == NULL)
       {
           head = tmp;
           current = tmp;
       }
       else
       {
           current->next = tmp;
           current = current->next;
       }
   }
   void display(){
     current=head;
     while(current!=NULL){
       cout<<current->data<<" ";
       current=current->next;
     }
   }

};


void sumlist(linkedlist a,linkedlist b){
  int na=0,nb=0;
  node *temp=NULL;
  node *taila=NULL;
  node *tailb=NULL;
  temp=a.head;

  while(temp!=NULL){
    na++;
    taila=temp;
    temp=temp->next;
  }

  //  cout<<na;
    temp=b.head;
    while(temp!=NULL){
      nb++;
      tailb=temp;
      temp=temp->next;
    }
    //cout<<nb;
    int diff;
    
    if(na<nb){//padding of 0
      diff=nb-na;
      for(int i=0;i<diff;i++){
          node *temp1=new node;
        temp1->data=0;
        temp1->next=NULL;
        taila->next=temp1;
        taila=temp1;
      }
    }
    if(nb<na){//padding 0
      diff=na-nb;
      for(int i=0;i<diff;i++){
        node *temp1=new node;
      temp1->data=0;
      temp1->next=NULL;
        tailb->next=temp1;
        tailb=temp1;
    }

    }
    cout<<"\n";
    a.display();
    cout<<"\n";
    b.display();
    cout<<"\n";
    temp=NULL;
    //sum
    int carry=0,sum=0;
    node *a1,*b1;
    a1=a.head;
    b1=b.head;
    node *prev;
    while(a1!=NULL){
      //cout<<" "<<a1->data<<" "<<b1->data;
       sum=a1->data +b1->data + carry;
      a1->data=sum%10;
       carry=(sum/10)%10;
       //cout<<" sum:"<<sum<<"carry:"<<carry;
       prev=a1;
      a1=a1->next;
      b1=b1->next;

    }
    node *c=new node;
    if(carry!=0){
    c->data=carry;
    c->next=NULL;
    prev->next=c;
  }

}

void reverse(linkedlist a){
  node *t1,*t2,*temp;
  t1=a.head;
  t2=NULL;
  while(t1!=NULL){
    temp=t1;
    t1=t1->next;
    temp->next=t2;
    t2=temp;
  }
}


int main(){
  linkedlist a,b;
  a.addnode(7);
  a.addnode(1);
    a.addnode(1);
  b.addnode(2);
  //  b.addnode(5);
  // b.addnode(9);



 a.display();
 cout<<"\n";
 b.display();
sumlist(a,b);


cout<<"\nThe sum:";
a.display();

//reverse(a);


  return 0;
}
