#include<bits/stdc++.h>
using namespace std;

class Solution{
    private: void reset(int* arr,int len=128){
                 for(int i=0;i<129;i++)
                     arr[i]=0;
             }
             void print(int* arr,int len=128){
                 for(int i=0;i<129;i++){
                     if(arr[i] == 1){
                         cout<<i<<" => "<<arr[i]<<endl;
                     }
                 }
             }
    public: int solution(string s=" "){
        int max=0;
        int start=0, end=0;
        int hash[128]={0};

        for(int i=0;i<s.length();i++){
           if(hash[int(s[i])] == 0){
               hash[int(s[i])]=1;
               end = i;
            if(max<(end-start)+1)
                   max = end-start + 1;
           }else{
               if(max<(end-start)+1)
                   max = end-start + 1;
               print(hash);
               memset(hash, 0, sizeof(hash+1));
                i = start+1; end = i;
                start = i;
           }
        }
        if(end == s.length())
            return s.length();
        return max;
    }
};

int main(){
    string str;
    cin>>str;
    Solution sol;
    cout<<sol.solution(str);
    return 0;
}
