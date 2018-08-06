#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){

string str;
getline(cin,str);
int i,ch,flag=0;
vector<int> a(26);
//cout<<str;

for(i=0;i<str.size();i++){
  ch=str[i]-'a';
  a[ch]++;
}


for(i=0;i<a.size();i++){
  if(a[i]>1){
  cout<<"not unique";
  flag=1;
  break;
  }
}
if(flag==0)
cout<<"Unique";

  return 0;
}
