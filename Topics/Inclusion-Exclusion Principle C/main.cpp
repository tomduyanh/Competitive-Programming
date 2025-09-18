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
const int H = 1e4;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int n, k;
int c[N], h[N], dp[N];
int seg[N];

void read(){
    cin >> n >> k;
    FOR(i, n) cin >> c[i] >> h[i];
}

void build(int id, int l, int r){
    if(l == r){
        seg[id] = dp[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id*2, l, mid); build(id*2+1, mid+1, r);
    seg[id] = (seg[id*2] + seg[id*2+1]) % MOD;
}

void update(int id, int l, int r, int pos, int val){
    if(l == r && pos == r){
        seg[id] = val % MOD;
        return;
    }
    if(pos < l || r < pos) return;
    int mid = (l + r) / 2;
    update(id*2, l, mid, pos, val);
    update(id*2+1, mid+1, r, pos, val);
    seg[id] = (seg[id*2] + seg[id*2+1]) % MOD;
}

int getSum(int id, int l, int r, int u, int v){
    if(u <= l && r <= v) return seg[id];
    if(v < l || r < u) return 0;
    int mid = (l + r) / 2;
    return (getSum(id*2, l, mid, u, v) % MOD + getSum(id*2+1, mid+1, r, u, v) % MOD) % MOD;
}

bool on(int sub, int bit){
    return (sub & (1 << (bit - 1)));
}

int get(int sub){
    dp[0] = 0;
    FOR(i, H) dp[i] = 0;
    build(1, 0, H);
    FOR(i, n){
        if(on(sub, c[i])){
            int sum = getSum(1, 0, H, 0, h[i] - 1);
//            cout << sum << nl;
            dp[h[i]] = (dp[h[i]] + sum + 1) % MOD;
            update(1, 0, H, h[i], dp[h[i]]);
        }
    }
    return getSum(1, 0, H, 0, H);
}

void solve(){
    int ans = get( (1 << k) - 1);
//    cout << ans << nl;
    FOR(sub, (1 << k) - 2){
        int val = get(sub), sz = k - __builtin_popcount(sub);
//        cout << val << nl;
        if(sz % 2) ans = (ans - val + MOD) % MOD;
        else ans = (ans + val) % MOD;
//        cout << nl;
    }
    cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    read();
    solve();

    return 0;
}

