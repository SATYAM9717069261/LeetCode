#include<bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> ans){
    for(vector<int> i: ans){
        for(int j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

class Solution {
private:
    vector<vector<int>> comp(vector<int> arr, int start,
                             int end) {

        if (start == end) {
            return {{}};
        }

        vector<vector<int>> tmp;
        tmp.push_back({arr[start]});

        for (int i = start; i < (arr.size() - 1); i++) {
            for (vector<int> j : comp(arr, i + 1,arr.size())) {
                j.push_back(arr[start]);
                tmp.push_back(j);
            }
        }
        return tmp;
    }

public:
    vector<vector<int>> combine(int n) {
        vector<int> num;
        for (int i = 1; i <= n; i++)
            num.push_back(i);
        vector<vector<int>> ans;
        for (int i = 0; i < num.size(); i++) {
            for (vector<int> j : comp(num, i, num.size())) {
                ans.push_back(j);
            }
        }

        return ans;
    }
};

int main(){
    int tmp; cin>>tmp;
    while(tmp--){
        int n; cin>>n;
        int k; cin>>k;
        vector<vector<int>> ans;
        Solution sol;
        ans = sol.combine(n);
        print(ans);
    }
    return 0;
}

