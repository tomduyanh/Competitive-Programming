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

int n, q, timer = 0;
int st[N], en[N], a[N], v[N], p[N];
vector <int> adj[N];
pll seg[4*N]; ll s[N];

void read(){
    cin >> n >> q;
    FOR(i, n) cin >> v[i];
    FOR(i, n - 1) {
        int x, y; cin >> x >> y;
        adj[x].PB(y);
        adj[y].PB(x);
    }
}

void DFS1(int node, int par){
    ++timer;
    st[node] = timer;
    a[timer] = node;
    s[node] = s[par] + v[node];
    p[node] = par;
    for(auto nxt : adj[node])
        if(nxt != par) DFS1(nxt, node);
    en[node] = timer;
}

void down(int id, int l, int mid, int r){
    ll t = seg[id].S;
    seg[id*2].F += t * (mid - l + 1);
    seg[id*2].S += t;
    seg[id*2+1].F += t * (r - mid);
    seg[id*2+1].S += t;
    seg[id].S = 0;
}

void update(int id, int l, int r, int u, int v, ll val){
    if(v < l || r < u) return;
    if(u <= l && r <= v){
        seg[id].F += val * (r - l + 1);
        seg[id].S += val;
        return;
    }
    int mid = (l + r) / 2;
    down(id, l, mid, r);
    update(id*2, l, mid, u, v, val);
    update(id*2+1, mid+1, r, u, v, val);
    seg[id].F = seg[id*2].F + seg[id*2+1].F;
}

void build(int id, int l, int r){
    if(l == r){
        seg[id].F = s[a[l]];
        return;
    }
    int mid = (l + r) / 2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    seg[id].F = seg[id*2].F + seg[id*2+1].F;
}

ll get(int id, int l, int r, int pos){
    if(pos < l || r < pos) return 0;
    if(l == pos && r == pos) return seg[id].F;
    int mid = (l + r) / 2;
    down(id, l, mid, r);
    return get(id*2, l, mid, pos) + get(id*2+1, mid+1, r, pos);
}

void solve(){
    DFS1(1, 0);
//    FOR(i, n) cout << i << sp << st[i] << sp << en[i] << sp << s[i] << nl;
//    cout << nl;
    build(1, 1, n);
    while(q--){
        int type; cin >> type;
        if(type == 1){
            int node, val; cin >> node >> val;
            int l = st[node], r = en[node];
//            cout << s[p[node]] << sp << s[node] << sp << val << sp << s[p[node]] - s[node] + val << nl;
            s[p[node]] = get(1, 1, n, st[p[node]]);
            s[node] = get(1, 1, n, st[node]);
            update(1, 1, n, l, r, s[p[node]] - s[node] + val);
            s[node] = s[p[node]] + val;
        }
        else{
            int node; cin >> node;
            int pos = st[node];
            cout << get(1, 1, n, pos) << nl;
        }
//        FOR(i, n) cout << i << sp << get(1, 1, n, i) << nl;
    }
//    cout << nl << get(1, 1, n, 5) << nl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    read();
    solve();

    return 0;
}

