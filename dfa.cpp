#include<bits/stdc++.h>
using namespace std;

class Dfa{
    int checkLastmatch(const string& pattern, int crntState) {
        for (int len = crntState; len > 0; len--) {
            if (pattern.substr(0, len) == pattern.substr(crntState - len + 1, len)) {
                return len;
            }
        }
        return 0;
    }
    vector<vector<int>> dfaTable;
    int finalState = 0;
    public: Dfa(string pattern){
                unordered_set<char> distincts;
                for(char i : pattern)
                    distincts.insert(i);
                vector<vector<int>> table(pattern.length()+1,vector<int>(26,0));
                table[0][pattern[0] - 'a'] = 1;
                int lps = 0;
                for (int i = 1; i < pattern.length(); i++) {
                    for(char distinct : distincts ){
                        table[i][distinct - 'a'] = table[lps][distinct - 'a'];
                    }
                    table[i][pattern[i] - 'a'] = i + 1;
                    lps = checkLastmatch(pattern, i);
                }
                dfaTable = table;
                finalState = pattern.length();
            }

            bool matchString(const string& str){
               int currentState = 0; 
               for(char i:str){
                   currentState = dfaTable[currentState][i - 'a'];
               }
               return currentState == finalState;
            }
};

int main(){
    Dfa dfa("aabab");
    cout<<" RESULT =>"<<dfa.matchString("aabab");
    return 0;
}
