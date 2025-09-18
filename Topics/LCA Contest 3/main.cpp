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

const int N = 1e5 + 5;
const int LOG = 17;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int n, q, m = 0;
int up[LOG][N], h[N], p[N];
pii edge[N];
map <int, map <int, int>> val;
vector <int> adj[N];

void read(){
    cin >> n;
    FOR(i, n - 1){
        int x, y; cin >> x >> y;
        adj[x].PB(y);
        adj[y].PB(x);
        edge[i].F = x, edge[i].S = y;
    }
}

void DFS1(int node, int par){
    for(auto nxt : adj[node])
        if(nxt != par){
            h[nxt] = h[node] + 1;
            p[nxt] = node;
            DFS1(nxt, node);
        }
}

void build(){
    DFS1(1, 0);
    FOR(i, n) up[0][i] = p[i];
    FOR(j, LOG - 1)
        FOR(i, n) up[j][i] = up[j - 1][up[j - 1][i]];
}

int Jump(int u, int k){
    for(int i = 0; i < LOG; ++i)
        if(k & (1 << i)) u = up[i][u];
    return u;
}

int LCA(int u, int v){
    for(int i = LOG - 1; i >= 0 && up[0][u] != up[0][v]; --i)
        if(up[i][u] != up[i][v]) u = up[i][u], v = up[i][v];
    if(u == v) return u;
    else return up[0][v];
}

int DFS2(int node, int par){
    for(auto nxt : adj[node]){
        if(nxt == par) continue;
        int v = DFS2(nxt, node);
        val[node][par] += v;
        val[par][node] += v;
    }
    return val[node][par];
}

void solve(){
    cin >> q;
    while(q--){
        int u, v; cin >> u >> v; int a = u, b = v;

        if(h[a] < h[b]) swap(a, b);
        a = Jump(a, h[a] - h[b]);

        int lca = LCA(a, b);
        ++val[u][up[0][u]], ++val[v][up[0][v]];
        ++val[up[0][u]][u], ++val[up[0][v]][v];
        val[lca][up[0][lca]] -= 2; val[up[0][lca]][lca] -= 2;
    }


    DFS2(1, 0);

    int ans = 0;
    FOR(i, n - 1) if(!val[edge[i].F][edge[i].S]) ++ans;
    cout << ans;
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

