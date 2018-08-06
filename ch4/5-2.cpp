#include<iostream>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};


bool bst(struct node *current,int min,int max){
  if(current==NULL)
    return true;

  if((min!=-1 &&current->data<=min)||(max!=-1 && current->data >max))
    return false;
  if((!bst(current->left,min,current->data)) ||(!bst(current->right,current->data,max)))
    return false;

  return true;

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
  //root->right->left=left2;
   std::cout << std::boolalpha;
  cout<<bst(root,-1,-1);

  return 1;
}
