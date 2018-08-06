#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

int main(){

string str;
getline(cin,str);
map<char,int> letter;
int i;
map<char,int>::iterator it;

for(i=0;i<str.size();i++){
  it=letter.find(str[i]);
  if(it==letter.end())
    letter.insert(pair<char,int> (str[i],1));
  else
    letter[str[i]]++;
}

string temp="";

for(it=letter.begin();it!=letter.end();it++){
  //it->first;
 int s=it->second;
  temp=temp+string(1,it->first)+to_string(s);

}

cout<<temp;



  return 0;
}
