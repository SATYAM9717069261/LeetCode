//https://www.codechef.com/problems/FRMN
#include<bits/stdc++.h>
using namespace std;
class Solution{
    private: int findpeaks(int startIdx, vector<int>&arr, pair<int,int>& dp){
                 if (arr.size() < 2 || startIdx >= arr.size() - 1) 
                     return arr.size() - 1;  // Return last index if invalid start

                 int phaseChangeCount = 0;

                 for (int i = startIdx + 1; i < arr.size(); ++i) {
                     if (i > startIdx + 1) {
                         if ((arr[i - 1] > arr[i] && arr[i - 2] < arr[i - 1]) || (arr[i - 1] < arr[i] && arr[i - 2] > arr[i - 1])) {
                             phaseChangeCount++;
                             if(phaseChangeCount == 1){
                                 dp.first = i-1;
                             }
                             if (phaseChangeCount == 2) {
                                 dp.second = i-1;
                                 return i - 1 - startIdx;  
                             }
                         }
                     }
                 }
                 dp.second = arr.size()-1;
                 return arr.size() - 1 - startIdx;              
             }

    public: int friends(vector<int>& mount){
                cout<<" ================================ "<<endl;
                int size = mount.size();
                int ans = 0;
                pair<int,int> dp ={0,0};  // first phase change, Result ans
                for(int i=0;i<size-1;i++){
                    if(dp.first>i){
                        cout<<" LAST ANS =>"<<dp.first << " =>"<<dp.second<<endl;
                        ans += dp.second - i;
                    }else{
                        ans += findpeaks(i,mount,dp);
                    }
                    cout<<" ANS =>"<<i <<" +> "<<ans<<endl;
                }
                return ans;
            }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> mountains(n,0);
        for (int i = 0; i < n; ++i) {
            cin >> mountains[i];
        }
        Solution sol;
        cout << sol.friends(mountains) << '\n';
    }
    return 0;
} 







#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int t; cin >> t;
    while(t--) {
        ll n,enem=0;
        cin>>n;
        vector<ll> h(n);
        vector<ll> ind(n);
        for(ll i=0;i<n;i++) 
            cin>>h[i];

        for(ll i=1;i<n-1;i++) {
            if(h[i-1]>h[i] && h[i+1]>h[i] || h[i-1]<h[i] && h[i+1]<h[i]) 
                ind.push_back(i);
        }

        for(ll i=0;i<ind.size()-2;i++) {
          enem+=(ind[i+1]-ind[i])*(n-1-ind[i+2]);
        }

        cout<<n*(n-1)/2-enem<<endl; 
    }
    return 0;
}



