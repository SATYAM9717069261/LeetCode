#include<bits/stdc++.h>
using namespace std;

class Solution{
    public: bool sol(vector<int>& data, int limit){
                int maxEle = 0;
                bool flag = true;
                for(int i=0;i<data.size();i++){
                    if(maxEle>data[i] && (maxEle+data[i]) > limit)
                        flag = false;
                    maxEle = max(maxEle,data[i]);
                }
                return flag;
            }
};
int main(){
    int test; cin>>test;
    while(test--){
        int num; cin>>num;
        int a; cin>>a;
        vector<int> data(num,0);
        for(int i=0;i<num;i++) cin>>data[i];
        Solution sl;
        cout<<(sl.sol(data,a) ? "YES":"NO")<<endl;
    }
    return 0;
}
