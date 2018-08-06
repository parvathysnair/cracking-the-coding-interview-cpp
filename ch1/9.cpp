#include<iostream>
#include<string>
using namespace std;


bool isSubstring(string s1,string s2){
  if(s1.find(s2)!= string::npos)
    return true;
    else
    return false;

}

int main(){

int i;
  string str1,str2;
  getline(cin,str1);
  getline(cin,str2);
  int n=str1.size();
  char c=str1[n-1];

  for( i=n-1;i>=0;i--){
    if(str2[i]==c)
      break;
  }
  string temp=str2.substr(i+1,n);
//cout<<temp;
  bool value=isSubstring(str1,temp);

  if(value)
    cout<<"yes";
  else
    cout<<"NO";


  return 0;
}
