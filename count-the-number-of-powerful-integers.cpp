#include "bits/stdc++.h"
using namespace std;
class Solution {
    private:
        long long findCount(long long start, long long finish, int limit, long long num, int strlen){
                 long long divFact = 10;
                 long long ans = 0;

                 bool usefirstNum = 0;  // should we use First One 
                 bool useLastNum = 0;  // should we use last Number

                int trackcount = 0;

cout<<" \t\t\t\t NUMBER  =>"<<num<<endl;

                 while(finish>0){
                     long long finishLast = finish % divFact;
                     long long numLast = num % divFact;
                     long long startLast = start % divFact;

                     if( trackcount<=strlen && useLastNum == 0 && min(finishLast,(long long)limit) < numLast)
                         useLastNum = 1;
                     if(trackcount<=strlen && usefirstNum == 0 && startLast > numLast)
                         usefirstNum = 1;

    cout<<" NUM LAST =>"<<numLast<<endl;
    cout<<"\t\t condition =<>>" << startLast << " > "<<numLast << ", =>  "<< min(finishLast,(long long)limit) <<" < "<< numLast<< endl;
                         
    cout<<" TRACK COUNT  =>"<<trackcount << " ++ >"<< strlen << " > " << useLastNum << " > "<<usefirstNum<<endl;

                     if( trackcount>strlen )
                         ans += min(finishLast,(long long)limit) - min (startLast,(long long)limit) ;

                     
                     finish = finish / divFact;
                     start = start /  divFact;
                     num = num / divFact;

                     trackcount++;
                 }
                    ans -= (useLastNum + usefirstNum);


                 cout<<"\t\t Ans =>"<<ans << " +>"<<finish << " limit =>"<<limit <<" num =>"<<num << " use  =>"<< (useLastNum + usefirstNum) <<endl;

                 return ans;
             }

    public: long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
            if(s.length()>15)
                return 0;
            long long num = stoll(s);
            if(num > finish)
                return 0;

            if(num <= start)
                num=start;
            long long ans = findCount(start,finish,limit,num,s.length()-1);
            return ans;
        }
};
int main(){
    int test; cin>>test;
    while(test--){
        long long strt; cin>>strt;
        long long fin; cin>>fin;
        int lmit; cin>>lmit;
        string str; cin>>str;
        Solution sol;
        long long ans = sol.numberOfPowerfulInt(strt,fin,lmit,str);
        cout<<" ANS =>"<<ans<<endl;
    }
    return 0; 
}

