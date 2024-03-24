#include<bits/stdc++.h>
using namespace std;
class Solution{
    private: void print(int nums[],int len){
                for(int i = 0 ;i<=len;i++)
                    cout<<nums[i]<<" ";
                cout<<endl;
             }
    public: int jump(vector<int>& nums){
                int numsLen = nums.size() - 1;
                int distace[numsLen+1];
                memset(distace,0,sizeof(distace));
                for(int i = numsLen - 1;i>=0;i--){
                    if(nums[i] == 0){
                        distace[i] = INT_MAX;
                        cout<<"SKIP =>"<<i<<" =>";
                        print(distace,numsLen);

                        continue;
                    }
                    int PosibleJumps = i+nums[i];
                    if(PosibleJumps>numsLen)
                        PosibleJumps = numsLen;

                    cout<<"JUMP =>"<<i+1 <<" Go =>"<<PosibleJumps<<endl;
                    int minJump = distace[PosibleJumps]; 
                    for(int j=i+1;j<=PosibleJumps;j++){
                        if(distace[j] == 0)
                            continue;
                       cout<<"j+>"<<j<<" Value =>"<<distace[j]<<endl; 
                        if(minJump>distace[j])
                            minJump=distace[j];
                        if(distace[j] == 1)
                            break;
                    }
                    if(minJump < INT_MAX)
                        distace[i] = minJump+1;
                    else 
                        distace[i] = minJump;
                    
                    print(distace,numsLen);
                }
                print(distace,numsLen);
                return distace[0];
            }
};

int main(){
    int size; cin>>size;
    vector<int> nums;

    while(size--){
        int tmp; cin>>tmp;
        nums.push_back(tmp);
    }
    Solution sol;
    cout<<sol.jump(nums);
    return 0;
}
