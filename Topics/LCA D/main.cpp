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
const int LOG = 17;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 1;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int n, m, sz[N], par[N], h[N];
int up[LOG][N], mn_dis[LOG][N];
struct tupel{
    int x, y, w;
}edge[N];
vector <pii> adj[N];

void read(){
    cin >> n >> m;
    FOR(i, m) cin >> edge[i].x >> edge[i].y >> edge[i].w;
    FOR(i, n){
        sz[i] = 1, par[i] = i;
        for(int j = 0; j < LOG; ++j) mn_dis[j][i] = INF;
    }
}

bool compare(tupel a, tupel b){
    return a.w > b.w;
}

int root(int node){
    while(node != par[node]) node = par[node];
    return node;
}

void unite(int x, int y){
    x = root(x), y = root(y);
    if(sz[x] < sz[y]) swap(x, y);
    sz[x] += sz[y];
    par[y] = x;
}

void buildMST(){
    sort(edge + 1, edge + m + 1, compare);
    FOR(i, m){
        int x = edge[i].x, y = edge[i].y, w = edge[i].w;
        if(root(x) != root(y)){
            adj[x].PB({y, w});
            adj[y].PB({x, w});
            unite(x, y);
        }
    }
}

void buildSPT(){
    for(int i = 1; i < LOG; ++i)
        for(int j = 1; j <= n; ++j) up[i][j] = up[i-1][up[i-1][j]];
    for(int i = 1; i < LOG; ++i)
        for(int j = 1; j <= n; ++j) mn_dis[i][j] = min(mn_dis[i-1][j], mn_dis[i-1][up[i-1][j]]);
}

void DFS(int node, int par, int hi){
    h[node] = hi;
    for(auto it : adj[node]){
        int nxt = it.F, w = it.S;
        if(nxt == par) continue;
        DFS(nxt, node, hi + 1);
        up[0][nxt] = node;
        mn_dis[0][nxt] = w;
    }
}

pii jump(int node, int k){
    int res = INF;
    for(int i = 0; i < LOG; ++i)
        if(k & (1 << i)){
            res = min(res, mn_dis[i][node]);
            node = up[i][node];
        }
    return {node, res};
}

ll getMin(int x, int y){
    int res = INF;
    if(h[x] > h[y]) swap(x, y);
    pii cur = jump(y, h[y] - h[x]);
    y = cur.F, res = cur.S;
    if(x == y) return res;
    for(int i = LOG - 1; i >= 0; --i){
        if(up[i][x] == up[i][y]) continue;
        res = min({res, mn_dis[i][x], mn_dis[i][y]});
        x = up[i][x], y = up[i][y];
    }
    return min({res, mn_dis[0][x], mn_dis[0][y]});
}

void solve(){
    ll ans = 0;
    FOR(i, m) ans += max(0LL, getMin(edge[i].x, edge[i].y) - edge[i].w);
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    read();
    buildMST();
    DFS(1, 1, 1);
    buildSPT();
    solve();

    return 0;
}

