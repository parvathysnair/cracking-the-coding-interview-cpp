#include<iostream>
#include<stack>
using namespace std;

void push( stack<int> &values,stack<int> &min){
  int no,minimum;
  cout<<"\nenter the number\n";
  cin>>no;
  if(min.empty()){
    minimum=no;
    min.push(no);
  }
  minimum=min.top();
  values.push(no);
  if(no<minimum){
    min.push(no);

  }

}
void pop(stack<int> &values,stack<int> &min){

  int valuestop,mintop;
  valuestop=values.top();
  mintop=min.top();
  if(valuestop==mintop){
    values.pop();
    min.pop();
  }
  else{
    values.pop();
  }

}


void display(stack<int> values,stack<int> min){
  stack<int> temp=values;
  cout<"\nthe values:";
  if(min.empty()&&temp.empty()){
    cout<<"\nempty";
    return;
  }
  while(!temp.empty()){
    cout<<" "<<temp.top()<<" ";
    temp.pop();
  }
  cout<<"\nmin:"<<min.top();

}

int main(){

  stack<int> values;
  stack<int> min;
  int ch;


  do{
    cout<<"\nenter the choice\n";
    cout<<"1.push\n2.pop\n3.display\n4.exit";

    cin>>ch;
    switch(ch){
      case 1:push(values,min);
              break;
      case 2: pop(values,min);
              break;
      case 3: display(values,min);
              break;
      case 4: break;
    }
  }while(ch!=4);



  //cout<<values;
  return 0;
}
