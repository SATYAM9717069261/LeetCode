#include<bits/stdc++.h>
using namespace std;

class Solution {
    public: int minNumberOperations(vector<int>& target) {
                int size = target.size();
                if(size == 1)
                    return target[0];
                int ans = 0;
                for(int i =1;i<size;i++){
                    if(target[i]<target[i-1]){
                        ans += abs(target[i-1]-target[i]);
                    }
                }
                ans+=target[size-1];
                cout<<" ANS =>"<<ans;
                return 0;
            }
};
int main(){
    int num; cin>>num;
    vector<int> arr;
    for(int i=0;i<num;i++){
        int tmp; cin>>tmp;
        arr.push_back(tmp);
    }
    Solution sol;
    sol.minNumberOperations(arr);

    return 0;
}
