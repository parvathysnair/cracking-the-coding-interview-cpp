#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){

  string str;
  int n=0,count=0;
  getline(cin,str);
  vector<int> a(26);

for(int i=0;i<str.size();i++){
  if(!isspace(str[i])){
    a[str[i]-'a']++;
    n++;
  }

}

for(int i=0;i<26;i++){
  if(a[i]%2!=0)
    count++;
}

if(count>1)
  cout<<"not palindrome";

  else
  cout<<"palindrome";





  return 0;
}
