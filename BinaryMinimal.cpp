/**
 * If number of ones <= op, we return a string of zeros of length (len(op) - op) (make New String)
 * else convert all first 1 into 0's
 * Test Case
 *   5
 *   000 1
 *   11 0
 *   10001 1
 *   001111000 3
 *   11100  3
*/
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public : string sol(string inp,int op){
                 int Onece = count(inp.begin(),inp.end(),'1');  // return Number of Ones 
                 if(Onece <= op)
                     return string(max(0,((int)inp.length()-op)),'0');
                 else {
                     for(int i = 0; i<inp.length() && op > 0;i++){
                         if(inp[i] == '1'){
                             inp[i] = '0';
                             op--;
                         }
                     }
                     return inp;
                 }
             }
};

int main(){
    int test; cin>>test;
    while(test--){
        string inp; cin>>inp;
        int op; cin>>op;
        Solution check ;
        cout<<check.sol(inp,op)<<endl;
    }
    return 0;
}
