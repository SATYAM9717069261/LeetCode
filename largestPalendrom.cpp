#include<bits/stdc++.h>
using namespace std;
struct Data{
    int index;
    Data* ptr;
    char ch;
};

class Solution{
    private: void print(vector<vector<Data>>& arr, string inp){
                int inpLen = inp.length();
                for(int i=0;i<inpLen;i++){
                    for(int j=0;j<inpLen;j++){
                        cout<<arr[i][j].ch<<arr[i][j].index<<"\t";
                    }
                    cout<<endl;
                }
             }
    public: string sol( string inp){
                int inpLen = inp.length();
                int max= 0;
                string ans="";
                string special = "";
                for(int mid=0;mid<inpLen;mid++){
                    int i = mid-1;
                    int j = mid+1;
                    string tmp="";
                    tmp += inp[mid];

                    while(i>=0 && j<inpLen && inp[i] == inp[j]){
                        tmp=inp[i] + tmp + inp[j];
                        i--; j++;
                    }

                    if(tmp.length() > ans.length()){
                        ans=tmp;
                    }   
                    tmp = "";
                    i = mid;
                    j= mid+1;
                    while(i>=0 && j<inpLen && inp[i] == inp[j]){
                        tmp=inp[i] + tmp + inp[j];
                        i--; j++;
                    }
                    if(tmp.length() > ans.length()){
                        ans=tmp;
                    } 
                    tmp="";
                    
                } 
                
            return ans;
            }
};

int main(){
   string inp; cin>>inp;
   Solution sol;
   string ans = sol.sol(inp);
   cout<<"Solution =>"<<ans;
   return 0;
}
