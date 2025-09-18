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

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int n, q, timer = 0;
int st[N], en[N], a[N], v[N];
ll seg[4*N];
vector <int> adj[N];

void read(){
    cin >> n >> q;
    FOR(i, n) cin >> v[i];
    FOR(i, n - 1){
        int x, y; cin >> x >> y;
        adj[x].PB(y);
        adj[y].PB(x);
    }
}

void DFS1(int node, int par){
    ++timer;
    st[node] = timer;
    a[timer] = node;
    for(auto nxt : adj[node])
        if(nxt != par) DFS1(nxt, node);
    en[node] = timer;
}

void build(int id, int l, int r){
    if(l == r){
        seg[id] = v[a[l]];
        return;
    }
    int mid = (l + r) / 2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    seg[id] = seg[id*2] + seg[id*2+1];
}

void update(int id, int l, int r, int pos, int val){
    if(pos < l || r < pos) return;
    if(pos == l && r == pos){
        seg[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(id*2, l, mid, pos, val);
    update(id*2+1, mid+1, r, pos, val);
    seg[id] = seg[id*2] + seg[id*2+1];
}

ll get(int id, int l, int r, int u, int v){
    if(v < l || r < u) return 0;
    if(u <= l && r <= v) return seg[id];
    int mid = (l + r) / 2;
    return get(id*2, l, mid, u, v) + get(id*2+1, mid+1, r, u, v);
}

void solve(){
    DFS1(1, 0);
    build(1, 1, n);
    while(q--){
        int type; cin >> type;
        if(type == 1){
            int node, val; cin >> node >> val;
            int pos = st[node];
            update(1, 1, n, pos, val);
        }
        else{
            int node; cin >> node;
            int l = st[node], r = en[node];
            cout << get(1, 1, n, l, r) << nl;
        }
    }
//    FOR(i, n) cout << i << sp  << st[i] << sp << en[i] << nl;
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

