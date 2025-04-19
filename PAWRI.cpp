#include<bits/stdc++.h>
using namespace std;
class Solution{
  public: string pawri(string& str){
            string search="party";
            string ans="";
            int searchIndex=0;
            string tmp="";
            int i=0;

            while(i< str.length()){
              if(str.substr(i,search.length()) == search){
                ans+="pawri";
                i+=search.length()-1;
              }else{
                ans+=str[i];
              }
              i++;
            }
            if(tmp != "")
              ans += tmp;
            return ans;
          }
};
int main(){
  int test; cin>>test;
  while(test--){
    string str; cin>>str;
    Solution sol;
    cout<<" INPUT  ===>>"<<str<<endl;
    cout<<sol.pawri(str)<<endl;
  }
  return 0;
}
