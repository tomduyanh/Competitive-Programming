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
#define FORR(i, n) for(int i = n; i > 0; --i)

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int BLOCK = 500;
const int LOG = 17;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int n, m;
int dis1[N], dis2[N], ans[N];
int h[N], pre[N], up[N][LOG+1];
vector <int> add;
bool red[N];
vector <int> adj[N];

void DFS1(int node, int par){
    if(red[node]) dis1[node] = 0;
    for(auto nxt : adj[node]){
        if(nxt == par) continue;
        DFS1(nxt, node);
        if(dis1[nxt] + 1 < dis1[node]){
            dis2[node] = dis1[node];
            dis1[node] = dis1[nxt] + 1;
        }
        else if(dis1[nxt] + 1 < dis2[node]){
            dis2[node] = dis1[nxt] + 1;
        }
    }
}

void DFS2(int node, int par, int top){
    ans[node] = min(top, dis1[node]);
    for(auto nxt : adj[node]){
        if(nxt == par) continue;
        if(dis1[nxt] + 1 == dis1[node]){
            DFS2(nxt, node, min(top, dis2[node]) + 1);
        }
        else{
            DFS2(nxt, node, min(top, dis1[node]) + 1);
        }
    }
}

void rebuild(){
    FOR(i, n) dis1[i] = dis2[i] = ans[i] = INF;

    for(auto node : add) red[node] = true;
    add.clear();

    DFS1(1, 0);
    DFS2(1, 0, INF);

}

void read(){
    cin >> n >> m;
    FOR(i, n - 1){
        int x, y; cin >> x >> y;
        adj[x].PB(y);
        adj[y].PB(x);
    }
    red[1] = true;
    FOR(i, n) ans[i] = INF;
}

void update(int x){
    add.PB(x);
    if(add.size() == BLOCK) rebuild();
}

int Jump(int node, int k){
    for(int i = 0; i < LOG; ++i)
        if(k & (1 << i)) node = up[node][i];
    return node;
}

int LCA(int x, int y){
    if(h[x] < h[y]) swap(x, y);
    x = Jump(x, h[x] - h[y]);
    for(int i = LOG - 1; i >= 0 && up[x][0] != up[y][0]; --i){
        if(up[x][i] != up[y][i]){
            x = up[x][i];
            y = up[y][i];
        }
    }
    if(x == y) return x;
    else return up[x][0];
}

void query(int x){
    int res = ans[x];
    for(auto node : add){
        int lca = LCA(node, x);
        res = min(res, -2*h[lca] + h[node] + h[x]);
    }
    cout << res << nl;
}

void buildH(int node, int par){
    h[node] = h[par] + 1;
    pre[node] = par;
    for(auto nxt : adj[node]){
        if(nxt == par) continue;
        buildH(nxt, node);
    }
}

void build(){
    FOR(i, n) up[i][0] = pre[i];
    FOR(j, LOG - 1) FOR(i, n) up[i][j] = up[up[i][j-1]][j-1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    read();
    buildH(1, 0);
    build();
    rebuild();
    while(m--){
        int type, x; cin >> type >> x;
        if(type == 1) update(x);
        else query(x);
    }
    return 0;
}

