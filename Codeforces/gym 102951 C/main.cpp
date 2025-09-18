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
const ll INF = 1e18;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int n;
int a[N], b[N], posB[N];
int dp[N], seg[4*N];

void update(int id, int l, int r, int pos, int val){
    if(pos < l || r < pos) return;
    if(l == pos && pos == r) {
        seg[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(id*2, l, mid, pos, val);
    update(id*2+1, mid+1, r, pos, val);
    seg[id] = max(seg[id*2], seg[id*2+1]);
}

int getMax(int id, int l, int r, int u, int v){
    if(r < u || v < l) return 0;
    if(u <= l && r <= v) return seg[id];
    int mid = (l + r) / 2;
    return max(getMax(id*2, l, mid, u, v), getMax(id*2+1, mid+1, r, u, v));
}

void solve(){
    FOR(i, n){
        dp[i] = getMax(1, 1, n, 1, posB[a[i]]) + 1;
        update(1, 1, n, posB[a[i]], dp[i]);
    }
    int ans = 0;
    FOR(i, n) ans = max(ans, dp[i]);
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n;
    FOR(i, n) cin >> a[i];
    FOR(i, n) cin >> b[i];

    FOR(i, n) posB[b[i]] = i;

    solve();

    return 0;
}

