#include<bits/stdc++.h>
using namespace std;
bool compare(vector<int> first, vector<int> second){
    if(first[0] < second[0])
        return true;
    return false;
}

class Solution{
    private: void print(vector<vector<int>>& intervals){
            for(vector<int>i: intervals){
                cout<<i[0]<<" , "<<i[1]<<endl;
            }
        }
    public: void interval(vector<vector<int>>& intervals){
                int intervalSize = intervals.size();
                sort(intervals.begin(), intervals.end(),compare);
                vector<vector<int>> result;
                result.push_back(intervals[0]);
                int lastEle = 0;
                for(int i=1;i<intervalSize;i++){
                   if(result[lastEle][1] >= intervals[i][0]){
                       if(result[lastEle][1] <= intervals[i][1])
                           result[lastEle][1] = intervals[i][1];
                   }else{
                       result.push_back(intervals[i]);
                       lastEle++;
                   }
                }
                print(result);
            }
};

int main(){
    int size; cin>>size;
    vector<vector<int>> intervals;

    while(size--){
        int tmpStart; cin>>tmpStart;
        int tmpEnd; cin>>tmpEnd;
        intervals.push_back({tmpStart,tmpEnd});
    }
    Solution sol;
    sol.interval(intervals);
    return 0;
}
