#include<bits/stdc++.h>
using namespace std;

class Solution{
    public: string solution(string s, int row){

                int strLen = s.length();
                if(strLen <= row || row < 2)
                    return s;
                int x = (row-1)*2;
                int y = 0;
                string ans;
                for(int i = 0;i<row;i++){
                    if(x>0)
                        ans += s[i]; 
                    int current = i+x;
                    while(current<strLen){
                        ans += s[current];
                        if(y!=0 && x!=0 && (current+y)<strLen)
                            ans += s[current+y];
                        current += (x+y);
                    }
                    x -= 2;
                    y += 2;
                }
                return ans;
            }
};

int main(){
    string str; cin>>str;
    int row; cin>>row;
    Solution sol;
    string ans = sol.solution(str,row);
    cout<<"Ans => "<<ans;
    return 0;
}
