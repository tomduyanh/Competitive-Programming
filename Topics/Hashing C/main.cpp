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

const int N = 2e6 + 10;
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

int n;
string s;
ll h[N], p[N];

ll GetHash(int u, int v){
    return (h[v] - h[u - 1] * p[v - u + 1] + MM) % MOD;
}

void buildHash(){
    s = " " + s;
    p[0] = 1, h[0] = 0;
    FOR(i, n){
        p[i] = (p[i-1] * base) % MOD;
        h[i] = ((h[i-1] * base) + (s[i])) % MOD;
    }
}

void solve(){
    if(!(s.size() % 2)) {
        cout << "NOT POSSIBLE";
        return;
    }
    buildHash();
    map <ll, ll> mp;
    vector <int> pos;
    int len = n / 2;

    if(GetHash(2, 1 + len) == GetHash(len + 2, n)) pos.PB(1), ++mp[GetHash(2, 1 + len)];
    if(GetHash(1, len) == GetHash(len+1, len*2)) pos.PB(n), ++mp[GetHash(1, len)];
    if(GetHash(1, len) == GetHash(len + 2, n)) pos.PB(len+1), ++mp[GetHash(1, len)];

    ll v2 = GetHash(len + 2, n);
    for(int k = 2; k <= len; ++k){
        ll v1 = ((GetHash(1, k - 1) * p[len - k + 1] + MM) % MOD + GetHash(k + 1, len + 1) + MM) % MOD;
        if(v1 == v2){
            ++mp[v2];
            pos.PB(k);
        }
    }
    v2 = GetHash(1, len);
    for(int k = len + 2; k < n; ++k){
        ll v1 = ((GetHash(len + 1, k - 1) * p[n - k] + MM) % MOD + GetHash(k + 1, n) + MM) % MOD;
        if(v1 == v2){
            ++mp[v2];
            pos.PB(k);
        }
    }
    if(mp.size() > 1){
        cout << "NOT UNIQUE";
        return;
    }
    if(mp.size() == 1){
        if(pos[0] <= len + 1){
            for(int i = len + 2; i <= n; ++i) cout << s[i];
        }
        else{
            for(int i = 1; i <= len; ++i) cout << s[i];
        }
    }
    else cout << "NOT POSSIBLE";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> s; n = s.size();
    solve();

    return 0;
}
