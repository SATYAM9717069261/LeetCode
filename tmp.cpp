#include<bits/stdc++.h>
using namespace std;
int main(){
    int test;cin>>test;
    while(test--){
        int n,h,t,y1,y2,l;
        cin>> n >> h >> t >> y1 >> y2 >> l;

cout<<" N =>"<<n << h << y1 <<y2<<l <<endl;

        int ans= 0;
        while(n--){
            int type,x; cin>>type>>x;
            cout<<"type =>"<<type<<" "<<x <<" " << n <<endl;
            if(l == 0)
                continue;
            if((type == 1 && (h-y1) > x) || type == 0 && x > y2){
                l--;
            }else{
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
