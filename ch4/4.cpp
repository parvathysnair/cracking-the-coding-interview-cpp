#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};


int height(struct node *temp);


int balanced(struct node *current){
  if(current==NULL)
    return 1;

    int value=height(current->left)-height(current->right);

    if(value<=1 && balanced(current->left)==1 && balanced(current->right)==1)
      return 1;
      else
      return 0;

}

int height(struct node *temp){
  if(temp==NULL)
  return 0;

  int h=1+max(height(temp->left),height(temp->right));
  return h;

}
int main(){
  node *root=new node();
  //root=NULL;
  root->data=5;
  node *left=new node();
    left->data=1;
  node *right=new node();
    right->data=9;
  root->left=left;
  root->right=right;
  node *left1=new node();
    left->data=4;
  node *right1=new node();
    right->data=19;
    root->left->left=left1;
    root->left->right=right1;
    node *left2=new node();
      left2->data=1;
      root->left->left->left=left2;

//cout<<height(root);
    if(balanced(root)==1)
    cout<<"balanced";
    else
    cout<<"Not Balanced";


    return 1;
}
