#include<bits/stdc++.h>
using namespace std;
class Soluton{
    public: bool sol(string str="race a car"){
                int len = str.length(); 
                int lastIndex = str.length();
                string newStr = "";
                for(int i = 0;i<len;i++){
                    if( (str[i] > 64 && str[i] < 91) || (str[i] > 96 && str[i] < 123) || (str[i] > 47 && str[i] < 58)){
                        if(str[i] > 64 && str[i] < 91)
                            newStr += (str[i]+32);
                        else
                            newStr += str[i]; 
                    }
                }

                    len = newStr.length(); 
                    lastIndex = newStr.length()-1;
                cout<<newStr;

                for(int i = 0;i<(len/2 + len%2);i++){
                    cout<<" +> "<<newStr[i] << " "<< newStr[lastIndex]<<endl;
                    if(newStr[i] != newStr[lastIndex--])
                        return false;
                }
                
                return true;
            }
};

int main(){
    string inp; cin>>inp;
    Soluton Sol;
    cout<<Sol.sol();
    return  0;
}
