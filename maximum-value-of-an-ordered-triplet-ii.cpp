#include<bits/stdc++.h>
using namespace std;
struct coveredHouse{
  int start;
  int end;
};
class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            long long ans = 0;
            int current = 1;
            long long maxEle = nums[0];
            long long maxDiff = 0;
            long long maxCal = 0;
            while (current < nums.size()) {
                maxCal = max(maxCal, maxDiff * nums[current]);
                maxDiff = max(maxDiff, (maxEle - nums[current]));
                maxEle = max(maxEle, (long long)nums[current]);
                current++;
            }
            return maxCal < 0 ? 0 : maxCal;
        }
};
class Solution {
  private: static bool sortlogic(coveredHouse i, coveredHouse j){
             if( i.start == j.start){
               if(i.end < j.end)
                 return true;
               else
                 return false;
             }else{
               return i.start < j.start;
             }
           }
          void print(vector<coveredHouse> data){
            for(coveredHouse i: data){
              cout<<" start : "<<i.start << " end : "<<i.end<<endl;
            }
          }
    public: long long maximumTripletValue(vector<int>& nums, int maxSpeed) {
              vector<coveredHouse> coveredHusList;
              coveredHusList.push_back({1,1});
              for(int copPos : nums){
                int startRange = copPos - maxSpeed ;
                int endRange = copPos + maxSpeed ;
               // cout<<" POSITION =>"<<copPos<< " start =>"<<startRange << " END  =>"<<endRange<<endl;
                coveredHusList.push_back({ (startRange>0) ? startRange : 1,endRange > 100 ? 100 : endRange});
              }
              coveredHusList.push_back({100,100});
              sort(coveredHusList.begin(),coveredHusList.end(),sortlogic);
              int count = 0;

              //print(coveredHusList);
              int i=1;
              for(i;i<coveredHusList.size()-1;i++){
                int diff = coveredHusList[i].start -  coveredHusList[i-1].end;
                //cout<<" AT i ="<<i<<" diff =>"<<diff<<endl;
                if(diff > 0 && diff < 101){
                  count += (diff- (i == 1 ? 0 :1) );
                }
              }
                int diff = coveredHusList[i].start -  coveredHusList[i-1].end;
                //cout<<" OUT AT i ="<<i<<" diff =>"<<diff<<endl;
                if(diff > 0 && diff < 101){
                  count += diff;
                }
              //cout<<" ANS  =>"<<count<<endl; 
              return count;
            }
};
int main(){
  int test; cin>>test;
  while(test--){
    int nums; cin>>nums;
    vector<int> arr;
    int x; cin>>x;
    int y; cin>>y;
    
    while(nums--){
      int tmp; cin>>tmp;
      arr.push_back(tmp);
    }
    Solution sol;
    long long ans = sol.maximumTripletValue(arr,x*y);
    cout<< "================================================================= ANS =>"<<ans;
  }
  return 0;
}
