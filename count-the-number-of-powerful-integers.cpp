#include "bits/stdc++.h"
using namespace std;
class Solution {
    private: long long findCount(long long start, long long finish, int limit, long long num){
                 
             }

    public: long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
            if(s.length()>15)
                return 0;
            long long num = stoll(s);
            if(num > finish)
                return 0;

            if(num <= start)
                num=start;

            long long ans = findCount(start,finish,limit,num);
            return ans;
        }
};
int main(){
    int test; cin>>test;
    while(test--){
        long long strt; cin>>strt;
        long long fin; cin>>fin;
        int lmit; cin>>lmit;
        string str; cin>>str;
        Solution sol;
        cout<<" CALL =>"<<strt<<" "<<fin<<" "<<lmit<<" "<<str<<endl;
        long long ans = sol.numberOfPowerfulInt(strt,fin,lmit,str);
        cout<<" ANS =>"<<ans<<endl;
    }
    return 0; 
}

