#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){

vector<int> alpha(26);
int flag=0;
string str1,str2;
getline(cin,str1);
getline(cin,str2);

for(int i=0;i<str1.size();i++){
  alpha[str1[i]-'a']++;
}


for(int i=0;i<str2.size();i++){
  alpha[str2[i]-'a']--;
}

for(int i=0;i<alpha.size();i++){
  //cout<<alpha[i]<<" ";
  if(alpha[i]!=0)
    {flag=1;
      break;
    }

}


if(flag==1)
cout<<"Not palindrome";
else
cout<<"palindrome";

return 0;

}
