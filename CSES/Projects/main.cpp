#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int,int> pii;
typedef pair <ll , ll> pll;

#define int long long
#define sp " "
#define nl "\n"
#define F first
#define S second
#define PB push_back
#define all(arr) arr.begin(), arr.end()

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen(".INP", "r", stdin);
    freopen(".OUT", "w", stdout);
}

int n;
struct D{
    int x, y, z;
}a[N];

map <int, int> mp;

void read(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i].x >> a[i].y >> a[i].z;
        mp[a[i].x] = mp[a[i].y] = 1;
    }
}

void compress(){
    map <int, int> date;
    int cnt = 0;
    for(map <int, int> :: iterator it = mp.begin(); it != mp.end(); ++it) date[it->F] = ++cnt;
    for(int i = 1; i <= n; ++i){
        a[i].x = date[a[i].x];
        a[i].y = date[a[i].y];
    }
}

bool compare(D a, D b){
    return (a.y < b.y || (a.y == b.y && a.x < b.x));
}

ll dp[N+10], tree[6*N];

void build(int id, int l, int r, int pos, int val){
    if(r < pos || l > pos) return;
    if(pos <= l && r <= pos){
        tree[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    build(id*2, l, mid, pos, val);
    build(id*2+1, mid+1, r, pos, val);
    tree[id] = max(tree[id*2], tree[id*2+1]);
}

ll GetMax(int id, int l, int r, int u, int v){
    if(r < u || l > v) return 0;
    if(u <= l && r <= v) return tree[id];
    int mid = (l + r) / 2;
    return max(GetMax(id*2, l, mid, u, v), GetMax(id*2+1, mid+1, r, u, v));
}

void solve(){
    sort(a+1, a+n+1, compare);
    memset(dp, 0, sizeof(dp));
    int mx = 0;
    for(int i = 1; i <= n; ++i) mx = max(mx, a[i].y + 1);
    for(int i = 1; i <= n; ++i){
        int st = a[i].x, en = a[i].y, va = a[i].z;
        dp[en] = max(dp[en], GetMax(1, 1, mx, 1, st-1) + va);
        build(1, 1, mx, en, dp[en]);
    }
    ll ans = 0;
    for(int i = 0; i <= mx + 1; ++i){
        ans = max(ans, dp[i]);
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    read();
    compress();
    solve();

    return 0;
}
