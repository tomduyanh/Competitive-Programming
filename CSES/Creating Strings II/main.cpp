#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;
typedef pair <int,int> pii;
typedef pair <ll , ll> pll;

#define sp " "
#define nl "\n"
#define F first
#define S second
#define PB push_back
#define all(arr) arr.begin(), arr.end()
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define FORR(i, n) for(int i = n; i > 0; --i)

const int N = 1e6;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int fac[N+1], inv[N+1];

int exp(int x, int k){
    x %= MOD;
    int res = 1;
    while(k > 0){
        if(k % 2) res = (res * x) % MOD;
        k /= 2;
        x = (x * x) % MOD;
    }
    return res;
}

int C(int k, int n){
    return (fac[n] % MOD * inv[k] % MOD * inv[n - k] % MOD) % MOD;
}

void buildFac(){
    fac[0] = 1, inv[0] = exp(fac[0], MOD - 2);
    FOR(i, N) fac[i] = (fac[i-1] * i) % MOD, inv[i] = exp(fac[i], MOD - 2);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    buildFac();
    string s; cin >> s;
    int n = s.size(); map <int, int> mp;
    FOR(i, n) ++mp[s[i-1] - 'a' + 1];
    ll ans = 1;
    for(auto it : mp){
        ans = (ans * C(it.S, n)) % MOD;
        n -= it.S;
    }
    cout << ans;

    return 0;
}

