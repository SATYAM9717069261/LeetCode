/**
*   class Solution {
*   private:
*       uint64_t primal_hash(const string &str)
*       {
*           static constexpr auto lookup = std::array<uint32_t, 26>{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
*           constexpr auto mod = (~uint64_t{0}) / 1000;
*           auto res = 1ul;

*           for (const auto it : str)
*           {
*               res *= lookup[it - 'a'];
*               res %= mod;
*           }

*           return res;
*       }
*   public:
*       vector<vector<string>> groupAnagrams(vector<string>& strs) {
*           unordered_map<uint64_t, vector<string>> grouped_strs;
*           uint64_t hashKey;
*           for (string str : strs)
*           {
*               hashKey = primal_hash(str);
*               if (grouped_strs.count(hashKey) > 0)
*               {
*                   grouped_strs[hashKey].push_back(str);
*               }
*               else
*               {
*                   grouped_strs[hashKey] = vector<string>{str};
*               }
*           }
*           vector<vector<string>> groups;
*           for (auto &[key, value] : grouped_strs)
*           {
*               groups.push_back(value);
*           }
*           return groups;
*       }
*   };
*/
#include<bits/stdc++.h>
using namespace std;
class Solution{
    private: bool compare(string& inp1, string& inp2){
                 for(char i: inp1){
                     bool find = false;
                     for(char j : inp2){
                         if(i==j){
                             find = true;
                             break;
                         }
                     }
                     if(find == false)
                         return false;
                 }
                 return true;
             }

    

 public: vector<vector<string>> groupAnagrams(vector<string>& strs) {
                vector<vector<string>> ans;
                ans.push_back(strs);
                int stringsArray = ans.size();
                int startStringArray = 0;
                while(startStringArray < stringsArray){
                    int subArryLen = ans[startStringArray].size();
                    int startSubArray = 0;
                    vector<string> remove;
                    vector<string> tmp;
                    while(startSubArray < subArryLen ){
                        if(!compare(ans[startStringArray][0],ans[startStringArray][startSubArray])){
                            remove.push_back( ans[startStringArray][startSubArray] );
                        }else{
                            tmp.push_back(ans[startStringArray][startSubArray]);
                        }
                        startSubArray++;
                    }
                    if(remove.size() == 0)
                        return ans;
                    ans.pop_back();
                    ans.push_back(tmp);
                    ans.push_back(remove);
                    stringsArray = ans.size();
                    startStringArray++;
                  }
            return ans;
   }
    void print(vector<vector<string>> ans){
                 for(vector<string> i : ans){
                     for(string k : i){
                         cout<< k<<" ";
                     }
                     cout<<endl;
                 }

             }

};

int main(){
    int len; cin>>len;
    vector<string>inp; 

    while(len--){
        string str; cin>>str;
        inp.push_back(str);
    }
    Solution sol;
    sol.print(sol.groupAnagrams(inp));
    return 0;
}
