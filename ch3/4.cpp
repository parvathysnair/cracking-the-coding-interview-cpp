#include <iostream>
#include<stack>
using namespace std;

class qstack{
  public:
  stack<int> s1;
  stack<int> s2;
  int size;
  void push(int data){
    s1.push(data);
  }
  void pop(){
    int i=0;
    size=s1.size();
    while(i<size-1){
      s2.push(s1.top());
      s1.pop();
      i++;
    }
    cout<<"\npopped element: "<<s1.top();
    s1.pop();//popped

    while(!s2.empty()){
      s1.push(s2.top());
      s2.pop();
    }


  }
  void display(){
    stack<int> s2,temp;
    temp=s1;
    if(s1.empty())
    cout<<"EMPTY";
    cout<<"\n";
    while(!s1.empty()){
      s2.push(s1.top());
      s1.pop();
    }
    while(!s2.empty()){
      cout<<s2.top()<<" ";
      s2.pop();
    }
    s1=temp;
  }


};


int main(){
  qstack a;

  int ch,data;
  do{
    cout<<"\nenter the choice\n";
    cout<<"1.push\n2.pop\n3.display\n4.exit";

    cin>>ch;
    switch(ch){
      case 1: cout<<"\nenter the element";
              cin>>data;
              a.push(data);
              //a.display();
              break;
      case 2: a.pop();
              //a.display();
              break;
      case 3: a.display();
              break;
      case 4: break;
    }
  }while(ch!=4);

  return 1;
}
