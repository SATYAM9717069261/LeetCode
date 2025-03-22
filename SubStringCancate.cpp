#include<bits/stdc++.h>
using namespace std;
class Solution{
    public: 
        vector<int> findSubstring(string s, vector<string>& words) {
            unordered_map<string, int> hashmap;
            for (string data : words) {
                hashmap[data]++;
            }
            int i = 0;
            int lenCheck = words[0].length();
            int stringLen = s.length();
            int totalWords = words.size();
            int tmpWordsSize = 0;
            vector<int> ans;
            while (i < stringLen) {
                unordered_map<string, int> innerhashmap;
                int tmpwordCount = 0;
                int j = 0;
                while ((i + j) < stringLen) {
                    string word = s.substr(i + j, lenCheck);
                    auto find = hashmap.find(word);
                    if (find == hashmap.end() || hashmap[word] <= innerhashmap[word]) {
                        innerhashmap.clear();
                        break;
                    }
                    innerhashmap[word]++;
                    j = j + lenCheck;
                    tmpwordCount++;
                    if (tmpwordCount == totalWords) {
                        ans.push_back(i);
                        break;
                    }
                }
                i++;
            }
            return ans;
        }

};
int main(){
    string s;
    cin>>s;
    int len; cin>>len;
    vector<string> words;
    while(len--){
        string tmp; cin>>tmp;
        words.push_back(tmp);
    }
    Solution sol;
    for(int i: sol.findSubstring(s,words)){
        cout<<"ans =>"<<i<<endl;
    }
    return 0;
}
