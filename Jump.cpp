#include<bits/stdc++.h>
using namespace std;

class Solution{
    public: bool jump(vector<int>& arr){
                int len = arr.size();
                if(len == 0)
                    return true;
                int max=arr[0];
                int maxPos= 0;
                for(int i=0;i<len;i++){
                    max = max - 1;
                    if(max < arr[i]){
                        max = arr[i];
                    }
                    cout<<"MAX => "<<max << " +>"<<i<<endl;
                    if(max == 0 && i != (len-1)){
                        return false;
                    }
                }
                return true;
            }
};

int main(){
    int size; cin>>size;
    vector<int> arr;
    while(size--){
        int tmp; cin>>tmp;
        arr.push_back(tmp);
    }
    Solution sol;
    cout<<sol.jump(arr);
    return 0;
}
