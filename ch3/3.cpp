#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;
int threshold=5;




class SetofStacs{
  public:
    vector<stack<int> >v1;
    int stacksize;
    int vectorsize;
    stack<int> s1;
    int index;
    SetofStacs(){
      stacksize=0;
      vectorsize=0;
      index=0;
    }
    void push(int data){
        if(v1.empty()){

          s1.push(data);
          v1.push_back(s1);
          // stacksize=s1.size();
        }
        else{
          stacksize=s1.size();
          vectorsize=v1.size();
          index=vectorsize-1;

          if(stacksize<threshold){
            s1.push(data);
            v1[index]=s1;
            stacksize++;
          }
          else{
            index++;
            s1=stack<int>();
          //  stacksize=1;
            s1.push(data);
            v1.push_back(s1);

          }
        }

      //  cout<<"\ncurrent vector filled:"<<index;
    }

    void display(){
      if(v1.empty())
        cout<<"\nEmpty";
      stack<int> temp;
      vectorsize=v1.size();
      for(int i=0;i<vectorsize;i++){
        temp=v1[i];
        cout<<i+1<<"stack: ";
        while(!temp.empty()){
          cout<<temp.top()<<" ";
          temp.pop();
        }
        cout<<"\n";
      }
    }

    void pop(){
      if(v1.empty())
        cout<<"Empty";
        else{
          vectorsize=v1.size();
          v1[vectorsize-1].pop();
          if(v1[vectorsize-1].empty()){
            v1.erase(v1.begin()+vectorsize-1);
          }
        }
    }



};







int main(){
  SetofStacs a;
  int ch,data;
  do{
    cout<<"\nenter the choice\n";
    cout<<"1.push\n2.pop\n3.display\n4.exit";

    cin>>ch;
    switch(ch){
      case 1: cout<<"\nenter the element";
              cin>>data;
              a.push(data);
              a.display();
              break;
      case 2: a.pop();
              a.display();
              break;
      case 3: a.display();
              break;
      case 4: break;
    }
  }while(ch!=4);


    return 1;
}
