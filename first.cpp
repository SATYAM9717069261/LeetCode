#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Solution {
    protected: void print(priority_queue<int>& pq){
                    while (!pq.empty()) {
                        cout << pq.top() << ' ';
                        pq.pop();
                        }
                    cout<<endl;
               }
    public: int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
                int count=0;
                priority_queue<int> maxHeap;
                int iter = 0;
                for(int i=0,j=1;i<heights.size()-1;i++,j++){
                    int req= (heights[j]-heights[i]);
                    cout<<" i => "<<i << " j=> " <<j<<" dif" <<req <<" bricks "<<bricks<<" leader => "<<ladders<<endl;
                    if(ladders == 0 && (req > bricks || bricks ==0 ))
                        break;
                    else{
                       if(req < 1)
                           count++;
                       else {
                            if(req > bricks){
                                //cout<<"MAX ELE " <<maxHeap.top()<<endl;
                                ladders--; 
                                count++;
                                if(!maxHeap.empty() && req <= (bricks+maxHeap.top())){
                                    maxHeap.push(req);
                                    bricks = bricks + maxHeap.top() - req;
                                    maxHeap.pop();
                                }
                            }else{
                                 maxHeap.push(req);
                                 bricks -= req;
                                 count++;
                            }
                       }
                    }
                    cout<<"COUNT => "<<count<<endl;
                }
                return count;
            }


};

int main(){
    int size;cin>>size;
    vector<int> heights;
    int br,ld;
    for(int i=0;i<size;i++){
        int a; cin>>a;
        heights.push_back(a);
    }
    cin>>br>>ld;
    Solution sol;
    cout<<sol.furthestBuilding(heights,br,ld);
 //   for(int i=0;i<size;i++)
  //      cout<< "DATA"<<heights[i];
    return 0;
}
