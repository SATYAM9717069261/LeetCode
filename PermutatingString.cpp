#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool checkInclusion(string s1, string s2) {
            int arr[26] = {0};
            int len = s1.length();
            int count =0;
            for(char c: s1)
                arr[c - 'a']++;

            int tmpArr[26];
            copy(begin(arr), end(arr), begin(tmpArr));
            int s2Len = s2.length();

            for(int i=0;i<=(s2Len - len ) ;i++){
                int limit = i+len;
                copy(begin(arr), end(arr), begin(tmpArr));
                for(int j=i;j<limit;j++){
                    if(tmpArr[s2[j] - 'a'] != 0){
                        tmpArr[s2[j] - 'a']--;
                        count++;
                    }else{
                        count = 0;
                        break;
                    }
                }
                if(count == len){
                    cout<<"Match";
                    return true;
                }
            }
            return false; 
        }
};
int main(){
    string s1; cin>>s1;
    string s2; cin>>s2;
    Solution sol;
    sol.checkInclusion(s1,s2);
    return 0;
}
