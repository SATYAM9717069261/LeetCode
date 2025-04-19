#include<bits/stdc++.h>
using namespace std;

int main(){
  int test ; cin>> test;
  while(test--){
    string inp; cin>>inp;
    if(inp.length() >= 10){
      cout<<"No"<<endl;
    }
    bool small =false,cap =false, dig =false, spec =false;
    for(char i : inp){
      if(i >= 'a' || i <= 'z')
        small =true;
      if(i >= 'A' || i <= 'Z')
        cap = true;
      if(i >= '0' || i <= '9')
        dig = true;
      if("@#%&?".find(i,0,5))
        spec = true;
    }
    if(small && cap && dig && spec)
      cout<<"Yes"<<endl;
    else
      cout<<"No"<<endl;
  }
  return 0;
}
