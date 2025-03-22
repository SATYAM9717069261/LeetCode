#include<bits/stdc++.h>
using namespace std;
class Solution{
    private: void flipBit(vector<int>& arr,int k,int currentIndex, vector<int>& tmp){
                 int size = tmp.size();
                 for(int i=currentIndex;i<(currentIndex+k);i++){
                     tmp[i]++;
                 }
             }

   public: int solution(vector<int>& arr, int k){
                int len = arr.size(); 
                queue<int> tmp;
                int ans =0;
                for(int i=0; i<len;i++){
                    if(!tmp.empty() && tmp.front() < i )
                        tmp.pop();

                    if(arr[i] == (tmp.size()%2)){
                        if((i+k-1)>=len)
                            return -1;
                        tmp.push(i+(k-1));
                        ans++;
                    }

                }
                return ans;
            }
};

int main(){
    int len; cin>>len;
    vector<int> arr;
    int k;
    while(len--){
        int tmp; cin>>tmp;
        arr.push_back(tmp);
    }
    cin>>k;
    Solution sol;
    cout<<" Ans =>"<<sol.solution(arr,k);
    return 0;
}

