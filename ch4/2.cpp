#include<iostream>
#include<vector>
using namespace std;

struct node{
  int data;
  node *left;
  node *right;
};

class tree{
  public:
  node *root;
  node *current;


  tree(){
    root=NULL;
    current=NULL;
  }
  void preOrder(node *root)
    {
    	if (root == NULL)
    		return;
      node *node=root;
    	cout<< node->data <<" ";
    	preOrder(node->left);
    	preOrder(node->right);
    }

  node* addnode(vector<int> arr,int min,int max){
    if(max<min)
      return NULL;
    int mid=(max+min)/2;
    node *temp=new node();
    temp->data=arr[mid];
    temp->left=addnode( arr, min, mid-1);
    temp->right=addnode( arr, mid+1, max);

    return temp;
  }

};





int main(){
  tree t1;
  int a[]={1,2,3,4,5,6,7};
  vector<int> arr(a,a+sizeof(a)/sizeof(a[0]));
      t1.root=t1.addnode(arr,0,arr.size()-1);

   t1.preOrder(t1.root);

}
