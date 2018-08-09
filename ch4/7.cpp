#include<iostream>
#include<vector>
#include<set>
using namespace std;




int main(){
  char a[]={'a','b','c','d','e','f'};

  char dependency[][5]={{'a','d'},{'f','b'},{'b','d'},{'f','a'},{'d','c'}};
  int matrix[6][6]={0};
  int index1,index2,i,j;

//  matrix dependancy initialization
  for( i=0;i<5;i++){
      index1=dependency[i][0]-'a';
      index2=dependency[i][1]-'a';
      matrix[index1][index2]=1;
  }
  for(i=0;i<6;i++){
    for(j=0;j<6;j++)
    cout<<matrix[i][j]<<" ";
    cout<<"\n";
  }
  int flag=0;
  set<char> result;
  while(result.size()<6){
    for(i=0;i<6;i++){
      for(j=0;j<6;j++){
        if(matrix[j][i]!=0){
          flag=1;break;
        }

      }
      if(flag==0){
        result.insert(a[i]);
      }
    }
  }

  return 0;
}
