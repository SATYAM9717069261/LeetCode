#include<bits/stdc++.h>
using namespace std;
class Kmp{
    private: vector<pair<char,int>> kmpTable; 
             int lps(const string pat, int end){
                 for (int len = end - 1; len > 0; len--) {
                     if (pat.substr(0, len) == pat.substr(end - len, len)) {
                         return len;
                     }
                 }
                 return 0; 
             } 

    public: Kmp(const string& pat){
                vector<pair<char,int>> table(pat.length()+1,{'\0',0});
                for(int i = 1 ;i<=pat.length() ;i++){
                    table[i] = {pat[i-1],lps(pat,i)};
                }
                kmpTable = table;
            } 

            vector<int> soluton(const string& str){
                vector<int> res(2,0); // {start,end}
                int i=0,j=0;
                while(i < str.length() ){
                    if(str[i] == kmpTable[j+1].first){
                        i++; j++;
                    }else{
                        j = kmpTable[j].second;
                        if(kmpTable[j].first == '\0')
                            i++;
                    } 

                    if(j == kmpTable.size()-1){
                        res = { i-(kmpTable.size()-1),i};
                        break;
                    }
                }
                return res;
            } 
};

int main (){
    Kmp kmp("ababcab"); 
    vector<int> response = kmp.soluton("ababcabcababcab");
    for(int i : response){
        cout << i << endl;
    }
    return 0;
} 

