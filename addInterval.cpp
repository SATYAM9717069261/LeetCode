#include<bits/stdc++.h>
using namespace std;
class Solution{
    private: void print(vector<vector<int>> intervals){
                int size = intervals.size();
                for(int i=0;i<size;i++){
                    cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
                }
             }
    public: void addIntervals(vector<vector<int>>intervals, vector<int> newInterval){
                const int n = intervals.size();
                vector<vector<int>> ans;
                int i = 0;

                while (i < n && intervals[i][1] < newInterval[0])
                    ans.push_back(intervals[i++]);

                // Merge overlapping intervals.
                while (i < n && intervals[i][0] <= newInterval[1]) {
                    newInterval[0] = min(newInterval[0], intervals[i][0]);
                    newInterval[1] = max(newInterval[1], intervals[i][1]);
                    ++i;
                }

                ans.push_back(newInterval);

                while (i < n)
                    ans.push_back(intervals[i++]);

             //   return ans
                     print(ans);
            }
};

int main(){
    int limit; cin>>limit;
    vector<vector<int>> intervals;
    vector<int> newInterval;

    while(limit--){
        int start; cin>>start;
        int end; cin>>end;
        intervals.push_back({start,end});
    }
    int start; cin>>start;
    int end; cin>>end;
    newInterval.push_back(start);
    newInterval.push_back(end);
    Solution sol;
    sol.addIntervals(intervals,newInterval);
    return 0;
}
