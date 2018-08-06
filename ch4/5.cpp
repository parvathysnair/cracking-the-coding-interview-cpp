#include<iostream>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

bool bst(struct node *current){
  if(current==NULL)
    return true;
  if(!bst(current->left))
      return false;
  if(!bst(current->right))
      return false;
      if(current->left==NULL && current->right==NULL)
      return true;
      if(current->left==NULL&& current->data < current->right->data)
      return true;
      if(current->right==NULL&& current->left->data <current->data)
      return true;
      if((current->left->data <current->data && current->data < current->right->data) )
          return true;



    return false;

}


int main(){
  node *root=new node();
    root->data=4;
  node *left=new node();
    left->data=2;
  node *right=new node();
    right->data=7;
  root->left=left;
  root->right=right;
  node *left1=new node();
    left1->data=1;
  node *right1=new node();
    right1->data=3;
    root->left->left=left1;
    root->left->right=right1;
    node *left2=new node();
      left2->data=15;
        root->right->left=left2;

        if(bst(root))
        cout<<"BST";
        else cout<<"Not BST";

  return 0;
}
