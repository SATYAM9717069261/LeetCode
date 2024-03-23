//string sol(string num1, string num2){
//              
//              int m = num1.size() - 1, n = num2.size() - 1, carry = 0;
//              string product;
//              for (int i=0; i<=m+n || carry; ++i) {
//                  for (int j=max(0, i-n); j<=min(i, m); ++j)
//                      carry += (num1[m-j] - '0') * (num2[n-i+j] - '0');
//                  product += carry % 10 + '0';
//                  carry /= 10;
//              }
//              reverse(begin(product), end(product));
//              return  product;
//          }
//
//
// public: string sol(string num1, string num2){
//              int num1Len = num1.length();
//              int num2Len = num2.length();
//              char ans[num1Len + num2Len];
//              memset(ans,'0',sizeof(ans));
//              int k = num1Len + num2Len;
//              ans[k] = '\0';
//              for(int i =num2Len-1  ; i>=0;i--){
//                  int carry = 0;
//                  int ansIndex = k-1;
//                  for(int j = num1Len-1 ;j>=0;j--){
//                      int mul = (charToint(num1[i]) * charToint(num2[j])) + carry + charToint(ans[ansIndex]); 
//                      carry = mul / 10;
//                      ans[ansIndex] = intTochar(mul % 10);
//                      ansIndex--;
//                  }
//                  if(carry != 0)
//                      ans[ansIndex] = intTochar(carry);
//                  k--;
//              } 
//              return ans;
//          }



#include<bits/stdc++.h>
using namespace std;
class Solution{
    private: int charToint(char num){
                 return (num - '0');
             }
             char intTochar(int num){
                 return (num + '0');
             }
             void print(char* arr, int len){
                 for(int i = 0;i<len;i++){
                     cout<<arr[i]<<" ";
                 }
                 cout<<endl;
             }
    public: string sol(string num1, string num2){
                int m = num1.size() - 1, n = num2.size() - 1, carry = 0;
                string product;
                for (int i=0; i<=m+n || carry; ++i) {
                    cout<<"J start =>"<<max(0,i-n) << "end =>"<<min(i, m)<<endl;
                    for (int j=max(0, i-n); j<=min(i, m); ++j){
                        cout<<" NUm1 =>"<<(num1[m-j] - '0')<<" NUm2 =>"<<(num2[n-i+j] - '0')<<endl;
                        carry += (num1[m-j] - '0') * (num2[n-i+j] - '0');
                    }
                    cout<<" OUT Loop2 "<<endl;
                    product += carry % 10 + '0';
                    carry /= 10;
                }
                reverse(begin(product), end(product));
                return  product;
            }


};
int main(){
    string num1; cin>>num1;
    string num2; cin>>num2;
    Solution solution;
    cout<<solution.sol(num1,num2);
    return 0;
}
