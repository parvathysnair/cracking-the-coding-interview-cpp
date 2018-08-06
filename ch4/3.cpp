#include "iostream"
#include<vector>

using namespace std;

struct treeNode{
  int data;
  treeNode *left;
  treeNode *right;
  treeNode *next=NULL;
};
// struct ll{
//   struct treeNode value;
//   struct ll *next;
// };


void listofdepth(struct treeNode *current){
  vector<treeNode*> level;

  treeNode *temp;
  temp=current;
  level.push_back(temp);
  int length=1;
  treeNode *t;
  treeNode *pushelement;
  //cout<<"h";
    while(length>0){
    //cout<<i;
    t=level[level.size()-1];
    length=0;
    temp=NULL;
    while(t!=NULL){
      cout<<t->data;
      if(t->left!=NULL && t->right!=NULL){
        length++;

        }
      if(temp==NULL){
        temp=t->left;
      pushelement=temp;
      }
      else{
        temp->next=t->left;
        temp=temp->next;
      }
      temp->next=t->right;
      temp=temp->next;

      t=t->next;
    }
    level.push_back(pushelement);

  }





}


void check(struct treeNode *current){
  vector<vector<treeNode*> > values;
  vector<treeNode*> temp,nodes;
  treeNode *left,*right,*node;
  temp.push_back(current);
  values.push_back(temp);

  //temp.clear();
  int l=1;
  while(l>0){
    nodes=temp;
    //nodes=values[values.size()-1];
    temp.clear();
    l=0;
    for(int i=0;i<nodes.size();i++){
      node=nodes[i];
      left=node->left;
      right=node->right;
      if(left!=NULL){
        l++;
        temp.push_back(left);
        }
      if(right!=NULL){
        l++;
        temp.push_back(right);
      }
    }
    values.push_back(temp);
  }
for(int i=0;i<values.size();i++){
  for(int j=0;j<values[i].size();j++){
    cout<<values[i][j]->data<<" " ;
  }
  cout<<"\n";
}

}




int main(){

  treeNode *root=new treeNode();
  root->data=5;
  treeNode *left=new treeNode();
    left->data=1;
  treeNode *right=new treeNode();
    right->data=9;
  root->left=left;
  root->right=right;
  treeNode *left1=new treeNode();
    left1->data=4;
  treeNode *right1=new treeNode();
    right1->data=19;
    root->left->left=left1;
    root->left->right=right1;

     //listofdepth(root);
check(root);

  return 0;
}
