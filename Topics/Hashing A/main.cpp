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

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const int base = 101;
const ll INF = 1e18;
const ll MM = 1ll * MOD * MOD;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

string a, b;
int n, m;
ll p[N], h[N], ha = 0;

void read(){
    cin >> a >> b;
    n = a.size(), m = b.size();
    a = " " + a, b = " " + b;
}

int GetHash(int u, int v){
    return (h[v] - h[u - 1] * p[v - u + 1] + MM) % MOD;
}

void buildHash(){
    p[0] = 1, h[0] = 0;
    FOR(i, m){
        p[i] = (p[i-1] * base) % MOD;
        h[i] = ((h[i-1] * base) + b[i]) % MOD;
    }
    FOR(i, n) ha = ((ha * base) + a[i]) % MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    read();
    buildHash();

    vector <int> ans;
    for(int i = n; i <= m; ++i)
        if(ha == GetHash(i - n + 1, i)) ans.PB(i-n+1);
    cout << ans.size() << nl;
    for(auto it : ans) cout << it << sp;

    return 0;
}

