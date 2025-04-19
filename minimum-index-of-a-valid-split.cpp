#include<bits/stdc++.h>
using namespace std;

class Solution {
    private: int dominateElement(unordered_map<int, int>& freqMap,bool check) {
                 int maxFreq = 0, element = -1;
                 for (const auto& [num, freq] : freqMap) {
                     cout<<(check == 0 ? "left => " : "rigth => ")<<num<<" => "<<freq<<endl;
                     if (freq > maxFreq || (freq == maxFreq && num < element)) {
                         maxFreq = freq;
                         element = num;
                     }
                 }
                 cout<<"\t\t\t RETURN =>"<<element<<endl;
                 return element;
             }
    public: int minimumIndex(vector<int>& nums) {
                unordered_map<int, int> right, left;
                for (int num : nums) 
                    right[num]++;
                
                for (int i = 0; i < nums.size(); i++) {
                    right[nums[i]]--;
                    if (right[nums[i]] == 0) 
                        right.erase(nums[i]);
                    if (dominateElement(left,0) == dominateElement(right,1)) 
                        return i;
                    left[nums[i]]++;
                }
                return -1;
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
    cout<<sol.minimumIndex(nums);
    return 0;
}


/**
int minimumIndex(vector<int>& nums) {
        const int n=nums.size();
        unordered_map<unsigned, unsigned> freq;
        freq.reserve(n);
        int maxF=1, xM=0;
        for(int x: nums){
            unsigned& f=freq[x];
            if(++f>n/2){
                maxF=f;
                xM=x;
            }
        }
        int cntxM=0;
        for(int i=0; i<n; i++){
            cntxM+=nums[i]==xM;
            if (cntxM*2>(i+1) && ((maxF-cntxM)*2>(n-i-1)))
                return i;
        }
        return -1;
    }


class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        const int n=nums.size();
        int cnt=0, xM=0, maxF=0;
        //Las Vegas
        srand(time(NULL));
        int sz=n;
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        while(sz){
            const int i=rand()%sz;
            xM=nums[idx[i]];
            maxF=count(nums.begin(), nums.end(), xM);
            if (maxF*2>n) break;  
            swap(idx[i], idx[--sz]); 
        }
    //    cout<<xM<<" maxF="<<maxF<<endl;
        int cntxM=0;
        for(int i=0; i<n; i++){
            cntxM+=nums[i]==xM;
            if (cntxM*2>(i+1) && ((maxF-cntxM)*2>(n-i-1)))
                return i;
        }
        return -1;
    }
};
**/
