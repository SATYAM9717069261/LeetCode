#include<bits/stdc++.h>
using namespace std;
class Solution{
    private: void print(vector<int>& arr){
                 int size= arr.size();
                 cout<<"Element =>";
                 for(int i=0; i< size;i++){
                     cout<<arr[i]<<" ";
                 }
                 cout<<endl;
             }
    public : int maxArea(vector<int>& height){ 
                 int i=0;int j= height.size()-1;
                 int max=-1;
                 Solution::print(height);
                 cout<<" GET HEIGHT +> "<<j<<endl;
                 while(i<j){
                    int tmp = (j-i)*min(height[i],height[j]);
                    cout<<"Tmp =>"<<height[i]<<" => "<<height[j]<<" i => "<<i<<" j=> "<<j<<"TMP =>"<<tmp<<endl;
                    if(height[i] > height[j]) 
                        j--;
                    else
                        i++;
                    if(max < tmp)
                        max=tmp;
                 }
                 return max;
             }
};

int main(){
    int size; cin>>size;
    vector<int> inp;
    while(size--){
        int num; cin>>num;
        inp.push_back(num);
    }
    Solution sol;
    cout<<"Max => "<<sol.maxArea(inp);
    return 0;
}
