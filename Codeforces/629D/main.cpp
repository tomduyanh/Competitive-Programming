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
# define M_PI           3.14159265358979323846

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int n, m = 0;
int a[N], idx[N], dp[N];
int seg[4*N];

void compress(){
    map <int, int> mp;
    FOR(i, n) ++mp[a[i]];
    for(auto it : mp) mp[it.F] = ++m;
    FOR(i, n) idx[i] = mp[a[i]];
}

int getMax(int id, int l, int r, int u, int v){
    if(v < l || r < u) return 0;
    if(u <= l && r <= v) return seg[id];
    int mid = (l + r) / 2;
    return max ( getMax(id*2, l, mid, u, v) , getMax(id*2+1, mid+1, r, u, v) );
}

void update(int id, int l, int r, int pos, int val){
    if(pos < l || r < pos) return;
    if(l == pos && pos == r){
        seg[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(id*2, l, mid, pos, val);
    update(id*2+1, mid+1, r, pos, val);
    seg[id] = max(seg[id*2], seg[id*2+1]);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n;
    FOR(i, n){
        int r, h; cin >> r >> h;
        a[i] = r*r*h;
    }

    compress();

    int ans = 0;
    FOR(i, n){
        int bruh = getMax(1, 1, m, 1, idx[i] - 1);
        dp[i] = max(dp[i], getMax(1, 1, m, 1, idx[i] - 1) + a[i]);
        update(1, 1, m, idx[i], dp[i]);
        ans = max(ans, dp[i]);
    }
    double res = M_PI * ans;
    cout << fixed << setprecision(9) << res;

    return 0;
}

