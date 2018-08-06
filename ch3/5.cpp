#include <iostream>
#include<stack>
using namespace std;


void display(stack<int> a){
  stack<int> temp=a;
  while(!temp.empty()){
    cout<<temp.top()<<" ";
    temp.pop();
  }
  cout<<"\n";
}

void sort(stack<int> &a){
  stack<int> temp;
  int min,n=a.size(),flag=0;


  for(int i=0;i<n;i++){
    min=a.top();flag=0;
    for(int j=0;j<n-i;j++){
      if(a.top()<min)
        min=a.top();


      temp.push(a.top());
      a.pop();
    }


    a.push(min);
    int m=temp.size();
    for(int j=0;j<m;j++){

      if(temp.top()!=min  || flag>0){
        a.push(temp.top());
        }
        else{
          flag++;
        }

      temp.pop();
    }
    display(a);
  }
  cout<<"\n";

}


int main(){
  stack<int> a;
  a.push(4);
  a.push(4);
  a.push(1);
  a.push(12);
  a.push(7);
  a.push(8);

  display(a);

  sort(a);
  display(a);

  return 1;
}
