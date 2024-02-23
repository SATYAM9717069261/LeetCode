#include<bits/stdc++.h>
using namespace std;
class Solution{
    public: int atoi(string inp){
                int ans = 0;
                int strLen = inp.length();
                string tmpStr = "";
                int tmpStrLen = tmpStr.length();
                int negative = 1;
                bool sign = false;
                bool firstNum = false;
                bool zero = false;
                for(int i=0;i<strLen;i++){
                    int num = int(inp[i]);
                    if(num < 48 || num > 59){
                        if((zero == true || firstNum == true ) && inp[i] == ' ')
                            break;
                        if(inp[i] == ' ')
                            continue;
                        if(firstNum == false && zero == true && (inp[i] == '-' || inp[i] == '+')){
                            return 0;
                        }
                        if((inp[i] == '-' || inp[i] == '+') && sign == true)
                            break;
                        if(inp[i] == '-'){
                            negative = -1;
                            sign = true;
                            continue;
                        }
                        if(inp[i] == '+'){
                            sign = true;
                            continue;
                        }
                        break;
                    }else{
                        if(num!=48 || (num == 48 && firstNum == true)){
                            tmpStr += inp[i];
                            firstNum = true;
                        }else{
                            if(num == 48 && zero == false ){
                                zero = true;
                                continue;
                            }
                            continue;
                        }
                    }
                }
                cout<<"GET STRI +>" <<tmpStr <<endl;
                tmpStrLen = tmpStr.length();
                if(tmpStrLen == 0)
                    return 0;
                if(tmpStrLen >= 10)
                    return Solution::checkTen(tmpStr,negative);

                return Solution::clamp(negative * Solution::ans(tmpStr,pow(10,tmpStr.length()-1)));
            }

            int ans(string inp, int mul){
                int strLen = inp.length();
                if(strLen == 0 )
                    return 0;
                int tmp = int(inp[0]) - 48; 
                long long tmpAns = ans(inp.erase(0,1),mul/10);
                return Solution::clamp(tmp*mul + tmpAns);
            }

            int clamp(long long num, int min=INT_MIN, int max = INT_MAX){
                if(num < min)
                    return min;
                if(num > max)
                    return max;
                return static_cast<int>(num);
            }

            int checkTen(string str,int sign){
                int arr[10] = {2,1,4,7,4,8,3,6,4,7};
                int ans = 0;
                if(str.length() == 10){
                    for(int i = 0;i<10;i++){
                        if(int(str[i])-48 > arr[i] || (sign == -1 && int(str[i])-48 >= arr[i])){
                            if(sign == -1) // positive
                                return INT_MIN;
                            else
                                return INT_MAX;
                        }else{
                            cout<<" INSIDE ELSE "<<endl;
                            break;
                        }
                    }
                }else{
                        if(sign == -1) // positive
                            return INT_MIN;
                        else
                            return INT_MAX;
                }
               cout<<" String =>"<<str<<str.length()-1<<endl; 
                return Solution::clamp(sign * Solution::ans(str,pow(10,str.length()-1)));
            }
};
int main(){
    string inp; cin>>inp;
    Solution sol;
    cout<<sol.atoi(inp)<<endl;
    return 0;
}
