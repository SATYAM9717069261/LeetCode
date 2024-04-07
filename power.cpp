#include<bits/stdc++.h>
using namespace std;
class Power{
    private: string multiply(string num1, string num2){
                 int m = num1.size() - 1, n = num2.size() - 1, carry = 0;
                 string product;
                 for (int i=0; i<=m+n || carry; ++i) {
                     for (int j=max(0, i-n); j<=min(i, m); ++j)
                         carry += (num1[m-j] - '0') * (num2[n-i+j] - '0');
                     product += carry % 10 + '0';
                     carry /= 10;
                 }
                 reverse(begin(product), end(product));
                 return  product;
             }
             string intToString(int num){
                 string ans="";
                 while(num > 9){
                     ans += (char)(num/10) + '0';
                     num = num%10;
                 }
                 ans += (char)(num%10) + '0';
                 return ans;
             }
    public: string solution1(int num, int lim){ 
                /**
                 * 3^-2  Not Working 
                 */
                bool neg=false;
                if(lim < 0){
                    num = ((float)1/num)*10;
                    lim *=-1;
                    neg = true;
                }
                string num1 = intToString(num);
                if(lim == 0)
                    return "1";
                if(lim == 1)
                    return num1;

                string ans="1";
                for(int i=0;i<lim;i++)
                   ans = multiply(ans,num1);
                
                if(neg == true){
                    string newAns="0.";
                    cout<<" Ans +>"<<ans<< " => "<<lim<<endl;
                    for(int i=0;i<lim;i++)
                        newAns+="0";
                    for(int i = ans.length()-1, j = newAns.length()-1 ;i>=0;i--,j--){
                        newAns[j] = ans[i];
                    }
                    return newAns;
                }else{
                    return ans;
                }
            }
            double solution(int num, int pow){
                double  ans = 1.0;
                int n = pow;
                if( n < 0)
                    n = -1*n;
                while(n){
                    if(n % 2){
                        ans = ans * num;
                        n--;
                    }else{
                        num = num*num;
                        n = n/2;
                    }
                }
                if(pow < 0)
                    ans = (double)(1.0)/(double)(ans);
                return ans;
            }
};


int main(){
    int limit; cin>>limit;
    while(limit--){
        int num; cin>>num;
        int pow; cin>>pow;
        Power power;
        cout<<" ===================================================="<<endl;
        cout<<power.solution(num,pow)<<endl;
    }
    return 0;
}
