#include<bits/stdc++.h>
using namespace std;

class Solution{
    private: void reset(int* arr,int len=128){
                 for(int i=0;i<129;i++)
                     arr[i]=0;
             }
             void print(int* arr,int len=128){
                 for(int i=0;i<len;i++){
                     if(arr[i] != -1){
                         cout<<i<<" => "<<arr[i]<<endl;
                     }
                 }
             }
    public: int solution(string s=" "){
        int max_=0;
        int start=0;
        vector<int> hash(256,-1);
        for(int i=0;i<s.length();i++){
                if(hash[s[i]] > start)
                    start = hash[s[i]];
                hash[s[i]] = i;
                max_=max(max_,i-start);
        }
        return max_;
   }
};

int main(){
    string str;
    cin>>str;
    Solution sol;
    cout<<sol.solution(str);
    return 0;
}
