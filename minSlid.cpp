#include<bits/stdc++.h>
using namespace std;
void print(unordered_map<char,int> arr){
    for(pair<char,int> i: arr){
        cout<<i.first<<" => "<<i.second<<endl;
    }
}
class Solution {
    public:
        string minWindow(string s, string t) {
            if (s.empty() || t.empty()) return "";
            unordered_map<char, int> dictT;
            for (char c : t) dictT[c]++;
            int required = dictT.size();
            int l = 0, r = 0;
            int formed = 0;
            unordered_map<char, int> windowCounts;
            int ans[] = {-1, 0, 0};
            while (r < s.size()) {
                char c = s[r];
                windowCounts[c]++;
                if (dictT.find(c) != dictT.end() && windowCounts[c] == dictT[c]) {
                    formed++;
                }
                while (l <= r && formed == required) {
                    c = s[l];
                    if (ans[0] == -1 || r - l + 1 < ans[0]) {
                        ans[0] = r - l + 1;
                        ans[1] = l;
                        ans[2] = r;
                    }
                    windowCounts[c]--;
                    if (dictT.find(c) != dictT.end() && windowCounts[c] < dictT[c]) {
                        formed--;
                    }
                    l++;
                }
                r++;
            }
            return ans[0] == -1 ? "" : s.substr(ans[1], ans[0]);
        }
};
int main(){
    string s; cin>>s;
    string t; cin>>t;
    Solution sol;
    string ans = sol.minWindow(s,t);
    cout<<"ANS +>"<<ans;
    return 0;
}
