#include <bits/stdc++.h>
using namespace std;

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

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const int base =  101;
const ll INF = 1e18;
const ll MM = 1ll * MOD * MOD;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int n;
int a[N], b[N];
ll p[N], rp[N], ha[N], hb[N], rhb[N];

int getHash(int u, int v, ll h[]){
    return (h[v] - h[u - 1] * p[v - u + 1] + MM) % MOD;
}

int getHashR(int u, int v){
    return (rhb[u] - rhb[v + 1] * rp[v - u + 1] + MM) % MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n;
    FOR(i, n) cin >> a[i];
    FOR(i, n) cin >> b[i];

    p[0] = 1;
    FOR(i, n){
        p[i] = (p[i-1] * base) % MOD;
        ha[i] = ((ha[i-1] * base) + a[i]) % MOD;
        hb[i] = ((hb[i-1] * base) + b[i]) % MOD;
    }
    FORR(i, n){
        rp[i] = (rp[i+1] * base) % MOD;
        rhb[i] = ((rhb[i+1] * base) + b[i]) % MOD;
    }

    vector <int> ans;
    for(int k = 1; k <= n; ++k){
        int v2 = getHash(k, n, ha), v3 = getHash(1, n - k + 1, hb);
        if(v2 != v3) continue;
        int v1 = getHash(1, k - 1, ha), v4 = getHash(n - k + 2, n, hb), v5 = getHashR(n - k + 2, n);
        if(v1 == v4 || v1 == v5) ans.PB(k);
    }

    cout << ans.size() << nl;
    for(auto it : ans) cout << it << sp;

    return 0;
}

