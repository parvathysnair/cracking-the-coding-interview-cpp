#include<iostream>
#include<vector>
using namespace std;


struct node{
  char data;
  node *next;
};


int main(){
  char a[]={'a','b','c','d','e','f'};
  vector<char> project(a,a+(sizeof(a)/sizeof(a[0])));

  int n=project.size();
  struct node *p[n];
  struct node *temp=new node();
  for(int i=0;i<n;i++){
    temp->data=project[i];
    p[i]=temp;
  }
  


  return 0;
}
