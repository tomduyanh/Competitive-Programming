#include<bits/stdc++.h>
using namespace std;
#define fu(i,a,b) for (long long i=a;i<=b;i++)
#define fd(i,a,b) for (long long i=a;i>=b;i--)
char th[4]={'h','a','r','d'};
long long n;
string s;
long long cost[111111];
long long memo[111111][5];
long long dp(long long vt,long long ht)
{
    if (ht==4) return 1e16;
    if (vt==n+1) return 0;
    if (memo[vt][ht]!=-1) return memo[vt][ht];
    long long ret=0;
    if (s[vt]==th[ht])
    {
        ret=min(dp(vt+1,ht+1),dp(vt+1,ht)+cost[vt]);
    }
    else
        ret=dp(vt+1,ht);
    return memo[vt][ht]=ret;
}
int main()
{
    memset(memo,-1,sizeof(memo));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef LoveP
    freopen("home.inp","r",stdin);
    freopen("home.out","w",stdout);
    #endif
    cin >> n;
    cin >> s;s="*"+s;
    fu(i,1,n) cin >> cost[i];
    cout << dp(1,0);
}
