#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){

string str;
bool flag=false;
string temp="";
int n,count=0;
getline(cin,str);
n=str.size();

for(int i=0;i<n;i++)
{
  if(!isspace(str[i])){
    temp=temp+str[i];
    flag=true;
  }
  if(isspace(str[i])&& flag){
    temp=temp+"%20";
    flag=false;
  }

}
temp=temp+"%20";
cout<<temp;


  return 0;
}
