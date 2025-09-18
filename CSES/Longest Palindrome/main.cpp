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

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;
const int base = 101;
const ll MM = 1ll * MOD * MOD;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

string s; int n;
ll pb[N], pr[N];
ll p[N], hb[N], hr[N];

void read(){
    cin >> s; n = s.size();
    s = " " + s;
}

ll getHashB(int u, int v){
    return (hb[v] - hb[u - 1] * p[v - u + 1] + MM) % MOD;
}

ll getHashR(int u, int v){
    return (hr[u] - hr[v + 1] * p[v - u + 1] + MM) % MOD;
}

void buildhash(){
    p[0] = 1;
    pb[0] = pr[n + 1] = 1;
    for(int i = 1; i <= n; ++i){
        p[i] = (p[i - 1] * base) % MOD;
        pb[i] = (pb[i - 1] * base) % MOD;
        hb[i] = ((hb[i - 1] * base) + s[i]) % MOD;
    }
    for(int i = n; i >= 1; --i){
        pr[i] = (pr[i + 1] * base) % MOD;
        hr[i] = ((hr[i + 1] * base) + s[i]) % MOD;
    }
}

int findPalin(int pos){
    ///case 1: pos is the middle
    int mx1 = 0, mx2 = 0;
    int lo_len = 1, hi_len = min(pos, n - pos + 1);
    while(lo_len <= hi_len){
        int mid_len = (lo_len + hi_len) / 2;
        if(getHashB(pos - mid_len + 1, pos) == getHashR(pos, pos + mid_len - 1)){
            mx1 = mid_len;
            lo_len = mid_len + 1;
        }
        else hi_len = mid_len - 1;
    }
    ///case 2: pos is left and right
    lo_len = 1, hi_len = min(pos, n - pos);
    while(lo_len <= hi_len){
        int mid_len = (lo_len + hi_len) / 2;
        if(getHashB(pos - mid_len + 1, pos) == getHashR(pos + 1, pos + mid_len)){
            mx2 = max(mx2, mid_len);
            lo_len = mid_len + 1;
        }
        else hi_len = mid_len - 1;
    }
    mx1 = mx1 * 2 - 1; mx2 *= 2;
    return max(mx1, mx2);
}

void solve(){
    int ans = 0, pos = 0;
    FOR(i, n){
        int val = findPalin(i);
        if(val > ans){
            ans = val;
            pos = i;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    read();
    buildhash();
    solve();

    return 0;
}

