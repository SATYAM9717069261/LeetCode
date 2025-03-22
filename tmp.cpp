#include<bits/stdc++.h>
using namespace std;
int main(){
    int test;cin>>test;
    while(test--){
        int n; cin>>n;
        int m; cin>>m;
        string str1; cin>>str1;
        string str2; cin>>str2;
        
        int windowSize = m;
        
        int minDis = INT_MAX;
        int right = 0;
        int left = m-1;
        int finalRight = 0;
            int finalLeft = 0;

        while(left <= n){
            int i = right;
            int j = 0;
            long count = 0;
            while( i <= left && j <= m){
                if(str1[i] != str2[j])
                    count++;
                i++;
                j++;
            }
            if(count < minDis){
                minDis = count;
                finalRight = right;
                finalLeft = left;
            }
            right++;
            left++;
        }
        cout<<minDis<<endl;
        cout<<" Right =>"<<right<<" Left =>"<<finalLeft;
    }
    return 0;
}
