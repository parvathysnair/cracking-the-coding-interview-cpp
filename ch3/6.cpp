#include<iostream>
#include <queue>
using namespace std;

class shelter{
public:
  queue<string> all;
  queue<string> cat;
  queue<string> dog;

  void push(string name){
      all.push(name);
    if(name.substr(0,3)=="cat")
      cat.push(name);
    else
      dog.push(name);

  }

  void popany(){
    cout<<all.front();
    if(all.front().substr(0,3)=="cat")
      cat.pop();
    else
      dog.pop();
    all.pop();
  }
  void popcat(){
    string which=cat.front();
    cout<<cat.front();
    cat.pop();
    queue<string> temp;

    while(!all.empty()){
          if(which==all.front()){
          all.pop();
          //break;
        }
        else{
          temp.push(all.front());
          all.pop();
        }
    }
    all=temp;


  }
  void popdog(){
    string which=dog.front();
    cout<<dog.front();
    dog.pop();

    queue<string> temp;

    while(!all.empty()){
          if(which==all.front()){
          all.pop();
          //break;
        }
        else{
          temp.push(all.front());
          all.pop();
        }
    }
    all=temp;
  }

  void display(){
    queue<string> temp;
    temp=all;
    cout<<"\nthe all list: ";
    if(temp.empty())
    cout<<"EMPTY";
    while(!temp.empty()){
      cout<<temp.front()<<" ";
      temp.pop();
    }
    cout<<"\nthe cat list: ";
    temp=cat;
    if(temp.empty())
    cout<<"EMPTY";
    while(!temp.empty()){
      cout<<temp.front()<<" ";
      temp.pop();
    }

    cout<<"\nthe dog list: ";
    temp=dog;
    if(temp.empty())
    cout<<"EMPTY";
    while(!temp.empty()){
      cout<<temp.front()<<" ";
      temp.pop();
    }

  }
};




int main(){
  shelter a;

  int ch;
  string data;
  do{

    cout<<"\n\n1.push\n2.get any\n3.get a cat\n4.get a dog\n5.exit";

    cin>>ch;
    switch(ch){
      case 1: cout<<"\nenter the name";
              cin>>data;
              a.push(data);
              a.display();
              break;
      case 2: a.popany();
              a.display();
              break;
      case 3: a.popcat();
              a.display();
              break;
      case 4: a.popdog();
              a.display();
              break;
      case 5: break;
    }
  }while(ch!=5);




  return 1;
}
