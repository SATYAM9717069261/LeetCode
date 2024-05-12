#include<bits/stdc++.h>
using namespace std;
struct workerRatio{
    double ratio;
    int* quality;
    int* wage;
};
bool compare(workerRatio w1, workerRatio w2){
    if(w1.ratio < w2.ratio)
        return true;
    return false;
}
class Solution{
    private: void print(vector<workerRatio>& data){
                 cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
                 cout<<" Quality :";
                 for(workerRatio ratio : data)
                     cout<<" "<<*ratio.quality;

                 cout<<endl<<" Wages :";
                 for(workerRatio ratio : data)
                     cout<<" "<<*ratio.wage;
                 cout<<endl<<" Ratio :";
                 for(workerRatio ratio : data)
                     cout<<" "<< ratio.ratio;
                 cout<<endl<<"--------------------------------------------------------------------------------------------------------"<<endl;
             }
    public: double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
                vector<workerRatio> ratio;
                int size = quality.size();
                for(int i = 0; i<size;i++){
                    double rat = (double)wage[i] /  (double)quality[i];
                    ratio.push_back({ rat, &quality[i], &wage[i] });
                }
                sort(ratio.begin(),ratio.end(),compare);
                int start = k-1;
                int Qualitysum = 0.0;
                priority_queue<double> pq;
                for(int i=0;i<k;i++){
                    pq.push(*ratio[i].quality);
                    Qualitysum += (*ratio[i].quality);
                }
                double ans = ratio[k-1].ratio * Qualitysum;
                for(int i = k;i<size;i++){
                    Qualitysum += (*ratio[i].quality);
                    Qualitysum -= pq.top();
                    double tmpans = ratio[i].ratio * Qualitysum;
                    if(tmpans < ans)
                        ans = tmpans;
                    pq.pop();
                    pq.push(*ratio[i].quality);
                }
                print(ratio);
                return ans; 
            }
};

int main(){
    int count; cin>>count;
    vector<int> q;
    vector<int> w;
    for(int i=0;i<count;i++){
        int tmp; cin>>tmp;
        q.push_back(tmp);
    }
    for(int i=0;i<count;i++){
        int tmp; cin>>tmp;
        w.push_back(tmp);
    }
    int k; cin>>k;
    Solution sol;
    cout<<sol.mincostToHireWorkers(q,w,k);
    return 0; 
}
