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

const int N = 2e6 + 1;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int fac[N + 5], inv[N + 5];

int exp(int x, int k){
    x %= MOD; ll res = 1;
    for(; k > 0; k /= 2){
        if(k % 2) res = (res * x) % MOD;
        x = (x * x) % MOD;
    }
    return res;
}

int C(int k, int n){
    return ((fac[n] * inv[k]) % MOD * inv[n - k] % MOD) % MOD;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    fac[0] = 1, inv[0] = exp(fac[0], MOD - 2);
    FOR(i, N) fac[i] = (fac[i-1] * i) % MOD, inv[i] = exp(fac[i], MOD - 2);

    int n, m; cin >> n >> m;
    cout << C(n - 1, m + n - 1);

    return 0;
}

