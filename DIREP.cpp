#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include"debug.h"
#else
    #define debug(x)
#endif

const int mod=998244353;

inline int add(int a,int b)
{
    return ((a%mod)+(b%mod))%mod;
}

inline bool check(int i,string &s)
{
    if(i+3>=(int)s.size())
    {
        return 0;
    }
    return ((s[i]==s[i+2])&&(s[i+1]==s[i+3])&&(s[i]!=s[i+1]));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt","w", stderr);
    #endif
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n;
        string s;
        cin>>n>>s;
        if(n<=3)
        {
            cout<<1<<'\n';
        }
        else
        {
            int dp[]={1,1,1};
            for(int i=n-4;i>=0;--i)
            {
                int ndp[3];
                ndp[0]=dp[0];
                ndp[1]=dp[0];
                ndp[2]=dp[1];
                if(check(i,s))
                {
                    ndp[0]=add(ndp[0],dp[2]);
                }
                memcpy(dp,ndp,sizeof(dp));
            }
            cout<<dp[0]<<'\n';
        }
    }
    return 0;
}
