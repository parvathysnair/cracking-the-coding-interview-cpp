#include<iostream>
#include<vector>
#include<queue>

using namespace std;


class graph{
  public:
  int v;
  vector<int> *adj;
  //vector<vector<int> > adj;
  graph(int v){
    v=v;
    adj=new vector<int>[v];
  }

  void addedge(int a,int b){

    adj[a].push_back(b);
  }

  bool route(int start,int end){
    queue<int> nodes;
    vector<bool> visited(v,false);
    nodes.push(start);
    int temp;
    while(!nodes.empty()){
      if(nodes.front()==end){
      //  cout<<"true";
        return true;
      }
      visited[nodes.front()]=true;
      temp=nodes.front();
      nodes.pop();
      for(int i=0;i<adj[temp].size();i++){
        if(!visited[adj[temp][i]]){
          nodes.push(adj[temp][i]);
        }
      }
    }
    return false;
  }



};


int main(){

  int v=7;
   graph g1(v);

  g1.addedge(1,2);
  g1.addedge(1,3);
  g1.addedge(2,6);
  g1.addedge(3,4);
  g1.addedge(4,5);
  g1.addedge(4,6);
//  g1.addedge(5,0);
 g1.addedge(6,5);
// cout<<"added";
  bool value=g1.route(5,6);
  std::cout << std::boolalpha;
  cout<<value;


  return 0;
}
