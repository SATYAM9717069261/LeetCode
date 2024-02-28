#include<bits/stdc++.h>
using namespace std;
class Solution{
    public: string sol(int num){
                vector<pair<int,string>> RomanNum { {1000,"M"}, {900,"CM"}, {500,"D"}, {400,"CD"}, {100,"C"}, {90,"XC"}, {50,"L"}, {40,"IL"}, {10,"X"}, {9,"IX"}, {5,"V"}, {4,"IV"}, {1,"I"} };
                string out="";
                for(pair<int,string> i : RomanNum){
                    int tmp = num/i.first;
                    for(int j=0;j<tmp;j++)
                        out += i.second;
                    num = num%i.first;
                }
                return out;
            }
};

int main(){
    int num; cin>>num;
    Solution sol;
    cout<<"Ans =>"<<sol.sol(num);
    return 0;
}
