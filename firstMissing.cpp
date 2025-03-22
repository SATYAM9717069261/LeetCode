#include<bits/stdc++.h>
using namespace std;
void print(vector<int>& arr){
    for(int i:arr)
        cout<<i<<" " ;
    cout<<endl;
}
class Solution {
    public: int firstMissingPositive(vector<int>& arr) {
                int len = arr.size();
                for(int i=0;i<len;i++){
                    if(arr[i]<=0)
                        arr[i] = len+1;
                }
                for(int i=0;i<len;i++){
                    int index = arr[i] < 0 ? -1 * arr[i] : arr[i];
                    if(index > 0 && index <= len && arr[index-1] > 0){
                        arr[index-1] = -1 * arr[index-1];
                        cout<<" INSIDE "<<arr[index-1] << " " <<index;
                    }

                }
                cout<<" NEGA =>"<<endl;
                print(arr);
                for(int i = 0;i<len;i++){
                    if(arr[i] > 0)
                        return i+1;
                }
                return len+1; 
            }
};
int main(){
    int len; cin>>len;
    vector<int> arr;
    while(len--){
        int num; cin>>num;
        arr.push_back(num);
    }
    Solution sol;
    cout<<"NUm=>"<<sol.firstMissingPositive(arr);
    return 0;
}
