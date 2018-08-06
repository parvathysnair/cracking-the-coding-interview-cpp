#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){

vector<int> a(26);
string str1,str2;
getline(cin,str1);
getline(cin,str2);
int i,count=0;

for(i=0;i<str1.size();i++){
  a[str1[i]-'a']++;
}

for(i=0;i<str2.size();i++){
  a[str2[i]-'a']--;
}


for(i=0;i<26;i++){
  if(a[i]!=0)
  count++;
}
// for(i=0;i<26;i++)
// cout<<a[i]<<" ";

if(count>2)
  cout<<"false";
  else
  cout<<"true";
  return 0;
}
