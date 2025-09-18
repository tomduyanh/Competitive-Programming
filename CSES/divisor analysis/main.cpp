#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <ll> vll;
const int MOD=1000000007;
long long int inverse(long long int i){
    if(i==1) return 1;
    return (MOD - ((MOD/i)*inverse(MOD%i))%MOD+MOD)%MOD;
}
ll POW(ll a,ll b)
{
    if(b==0) return 1;
    if(b==1) return a%MOD;
    ll temp=POW(a,b/2);
    if(b%2==0) return (temp*temp)%MOD;
    else return (((temp*temp)%MOD)*a)%MOD;
}

vector<vll> mul(vector<vll> x, vector<vll> y) {
    vector<vll> r(6, vll(6));
    for (int j = 0; j < 6; j++)
    {
        for (int k = 0; k < 6; k++)
        {
            for (int l = 0; l < 6; l++)
            {
                r[j][k] = (r[j][k]+(x[j][l]*y[l][k])%MOD)%MOD;
            }
        }
    }
    return r;
}

vector<vll> modpow(vector<vll> x, ll n)
{
    if (n == 0)
    {
        vector<vll> r(6, vll(6));
        for (int i = 0; i < 6; i++) r[i][i] = 1;
        return r;
    }
    vector<vll> u = modpow(x, n/2);
    u = mul(u, u);
    if (n%2==1) u = mul(u, x);
    return u;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    vector<vll> a(6,vll(6));
    for(int i=0;i<5;i++)
    {
        a[i][i+1]=1;
    }
    for(int i=0;i<6;i++)
    {
        a[5][i]=1;
    }
    vector<vll> ans=modpow(a,n);
    cout<<ans[5][5];
}
