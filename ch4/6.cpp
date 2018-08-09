#include<iostream>
using namespace std;

struct node{
  char data;
  struct node *left;
  struct node *right;
  struct node *parent;
};

void successor(struct node *current){
  cout<<current->data<<"\n";
  //check1
  if(current->right==NULL){
    if(current->parent->left==current){
      cout<<"next node: "<<current->parent->data;
      return;
    }
    if(current->parent==NULL){
      cout<<"No next node bcz it is the root node and the right sub tree is empty\n";
      return;
    }
    if(current->parent->right==current && current->parent->parent!=NULL && current->parent->parent->left==current->parent){
    //  cout<<"hi";
      cout<<"next node: "<<current->parent->parent->data;
      return;
    }
     if(current->parent->right==current  ){
      cout<<"no next node as it is the right most element\n";
      return;
    }
  }
  //check2
  else{
    if(current->right->left==NULL){
      cout<<"next node: "<<current->right->data;
      return;
    }
    else{
      current=current->right;
      while(current->left!=NULL){
          current=current->left;
      }
      cout<<"next node: "<<current->data;
      return;
    }

  }
}





int main(){
struct node *a=new node();
struct node *b=new node();
struct node *c=new node();
struct node *d=new node();
struct node *e=new node();
struct node *f=new node();
struct node *g=new node();
  a->data='a';
  a->left=b;
  a->right=f;
  a->parent=NULL;
  b->data='b';
  b->left=c;
  b->right=d;
  b->parent=a;
  c->data='c';
  c->left=NULL;
  c->right=NULL;
  c->parent=b;
  d->data='d';
  d->left=e;
  d->right=NULL;
  d->parent=b;
  e->data='e';
  e->left=NULL;
  e->right=NULL;
  e->parent=d;
  f->data='f';
  f->left=g;
  f->right=NULL;
  f->parent=a;
  g->data='g';
  g->left=NULL;
  g->right=NULL;
  g->parent=f;

 successor(d);






  return 1;
}
