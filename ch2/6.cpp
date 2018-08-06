#include<iostream>
#include<string>

using namespace std;

struct node{
  char data;
  node *next;
};

class linkedlist{
  public:
  node *head;
  node *current;
  node *next;
  node *prev;
  linkedlist(){
    head=NULL;
    current=NULL;
  }
  void addnode(char n)
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
   void reverse(){
     current=head;
     next=NULL;
     prev=NULL;
     while(current!=NULL){
       next=current->next;
       current->next=prev;
       prev=current;
       current=next;
     }
     head=prev;
   }

};

  void palindrome(linkedlist a){
    linkedlist b;
    b=a;
    int flag=0;
    b.reverse();
    b.display();
    //if equal
    node *ta,*tb;
    ta=a.head;
    tb=b.head;
    while(ta!=NULL){
      if(ta->data==tb->data){
        ta=ta->next;
        tb=tb->next;
      }
      else{
        flag=1;break;
      }
    }

    if(flag==1)
    cout<<"\nNot palindrome";
    else
    cout << "\npalindrome" << '\n';

  }



int main(){
  linkedlist a;
  a.addnode('a');
   a.addnode('b');
  a.addnode('b');
  a.addnode('c');
 a.addnode('a');
  a.display();

cout<<"\n";

 palindrome(a);


  return 0;
}
