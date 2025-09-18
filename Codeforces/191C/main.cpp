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
const int LOG = 18;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int n, q;
int par[N], h[N], s[N], ans[N];
int up[LOG + 1][N];
map <int, map <int, int>> val, pos;
vector <int> adj[N];

void read(){
    cin >> n >> q;
    for(int i = 2; i <= n; ++i){
        int x, y; cin >> x >> y;
        adj[x].PB(y); adj[y].PB(x);
        pos[x][y] = pos[y][x] = i;
    }
}

void DFS1(int node, int p, int hei){
    h[node] = hei;
    par[node] = p;
    for(auto nxt : adj[node])
        if(nxt != p) DFS1(nxt, node, hei + 1);
}

void build(){
    DFS1(1, 0, 1);
    FOR(i, n) up[0][i] = par[i];
    FOR(j, LOG - 1)
        FOR(i, n) up[j][i] = up[j - 1][up[j - 1][i]];
}

int jump(int node, int k){
    for(int i = 0; i < LOG; ++i)
        if(k & (1 << i)) node = up[i][node];
    return node;
}

void DFS2(int node, int par){
    ans[node] = s[node];
    for(auto nxt : adj[node])
        if(nxt != par){
            DFS2(nxt, node);
            ans[node] += ans[nxt];
        }
}

int LCA(int u, int v){
    int lca = 1;
    if(h[u] < h[v]) swap(u, v); ///h[u] > h[v]
    u = jump(u, h[u] - h[v]);
    for(int i = LOG - 1; i >= 0 && up[0][u] != up[0][v]; --i)
        if(up[i][u] != up[i][v])  u = up[i][u], v = up[i][v];
    if(u == v) lca = u;
    else lca = up[0][v];
    return lca;
}

void solve(){
    while(q--){
        int a, b; cin >> a >> b;
        int lca = LCA(a, b);
        ++s[a], ++s[b], --s[lca], --s[up[0][lca]];

    }

    DFS2(1, 0);

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    read();
    build();
    solve();

    return 0;
}

