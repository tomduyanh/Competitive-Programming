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

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int n, q;
int a[N];
ll s[N];
pii seg[4*N];

void build(int id, int l, int r){
    if(l == r){
        seg[id].F = s[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    seg[id].F = max(seg[id*2].F, seg[id*2+1].F);
}

void read(){
    cin >> n >> q;
    FOR(i, n){
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }
    FOR(i, 4*n) seg[i].F = -INF;
    build(1, 1, n);
}

void down(int id, int l, int mid, int r){
    int t = seg[id].S;
    seg[id*2].F += t;
    seg[id*2].S += t;
    seg[id*2+1].F += t;
    seg[id*2+1].S += t;
    seg[id].S = 0;
}

void update(int id, int l, int r, int u, int v, int val){
    if(v < l || r < u) return;
    if(u <= l && r <= v){
        seg[id].F += val;
        seg[id].S += val;
        return;
    }
    int mid = (l + r) / 2;
    down(id, l, mid, r);
    update(id*2, l, mid, u, v, val);
    update(id*2+1, mid+1, r, u, v, val);
    seg[id].F = max(seg[id*2].F, seg[id*2+1].F);
}

int get(int id, int l, int r, int u, int v){
    if(v < l || r < u) return -INF;
    if(u <= l && r <= v) return seg[id].F;
    int mid = (l + r) / 2;
    down(id, l, mid, r);
    return max( get(id*2, l, mid, u, v) , get(id*2+1, mid+1, r, u, v) );
}

void solve(){
    while(q--){
        int type, x, y; cin >> type >> x >> y;
        if(type == 1){
            int change = y - a[x];
            a[x] = y;
            update(1, 1, n, x, n, change);
        }
        else{
            cout << max(0LL, get(1, 1, n, x, y) - (x-1 == 0 ? 0 : get(1, 1, n, x-1, x-1))) << nl;
        }
    }
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
