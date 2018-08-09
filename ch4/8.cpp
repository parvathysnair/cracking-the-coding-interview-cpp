
//check for d,e if needed make change
#include<iostream>
using namespace std;

struct node{
  char data;
  struct node *left;
  struct node *right;
}*root;
int flag=0;
int height(struct node *current,struct node *n,int level){
  if(current==NULL)
    return -1;
  if(current==n)
    return level;
  if(current->left==NULL && current->right==NULL)
    return -1;
  int leftheight=height(current->left,n,level+1);
  int rightheight=height(current->right,n,level+1);

  if(leftheight==-1)
    return rightheight;
  else
    return leftheight;
}

bool check(struct node *current,struct node *n){

  if(current==n)
    return true;
    if(current==NULL)
    return false;
  if(check(current->left,n))
    return true;
  else if(check(current->right,n))
    return true;
    else
    return false;

}
void ancestor(struct node *r,struct node *n1,struct node *n2){
  int h1=height(r,n1,1);
  int h2=height(r,n2,1);
//  cout<<h1<<" "<<h2;
  bool n1left=check(r->left,n1);
  bool n1right=check(r->right,n1);
  bool n2left=check(r->left,n2);
  bool n2right=check(r->right,n2);

  if((n1left&&n2right)||(n1right && n2left))//different side
    {
      cout<<"\n"<<r->data;flag=1;
      return;
    }
  else{
    if(n1left && n2left){
      ancestor(r->left,n1,n2);
    }
    if(n1right && n2right){
      ancestor(r->right,n1,n2);
    }

  }

  return;

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

    b->data='b';
    b->left=c;
    b->right=d;

    c->data='c';
    c->left=NULL;
    c->right=NULL;

    d->data='d';
    d->left=e;
    d->right=NULL;

    e->data='e';
    e->left=NULL;
    e->right=NULL;

    f->data='f';
    f->left=g;
    f->right=NULL;

    g->data='g';
    g->left=NULL;
    g->right=NULL;

    root=a;

    ancestor(root,b,d);
    if(flag==0)
      cout<<"\nno ancestor";
  return 1;
}
