#include<bits/stdc++.h>
using namespace std;
class Solution{
    public: bool isMatch(string s, string p){
                return compute(s,p,0,0);
            } 
            bool compute(string str, string pat, int i, int j){
                if(str.length() == i || pat.length() == j){
                    if(str.length() == i && pat.length() == j)
                        return true;
                    else 
                        return false;
                }else{
                    if(pat[j] == '*' || pat[j] == '.' || pat[j] == str[i]){
                        if(pat[j] == '*'){
                            while(pat[j-1] == str[i])
                                i++;
                            int jMatch = 1;
                            while(pat[j-1] == pat[j+jMatch])
                                jMatch++;
                            if(pat[j-1] == '.')
                                return compute(str,pat,str.length(),j+1);
                            else
                                return compute(str,pat,i,j+jMatch);
                        }else{
                            return compute(str,pat,i+1,j+1);
                        }
                    }else{
                        return compute(str,pat,i,j+1);
                    }
                }
            }
};

int main(){
    string inp; cin>>inp;
    string pattern; cin>>pattern;
    Solution sol;
   cout<<sol.isMatch(inp,pattern);
    return 0;
}
