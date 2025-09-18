#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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

const int N = 5e5 + 1;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
//    freopen("FILE.INP", "r", stdin);
//    freopen("FILE.OUT", "w", stdout);
}

int n, m, s, p;
int a[N], aa[N], b[N], roots[N]; bool vis[N], sus[N];
int dp[N];
vector <int> order, root_nodes, scc;
vector <int> adj[N], radj[N], adj_scc[N];

void read(){
    cin >> n >> m;
    FOR(i, m){
        int x, y; cin >> x >> y;
        adj[x].PB(y);
        radj[y].PB(x);
    }
    FOR(i, n) cin >> a[i];
    cin >> s >> p;
    FOR(i, p) cin >> b[i];
}

void dfs1(int node){
    vis[node] = true;
    for(auto nxt : adj[node]) if(!vis[nxt]) dfs1(nxt);
    order.PB(node);
}

void dfs2(int node){
    vis[node] = true;
    scc.PB(node);
    for(auto nxt : radj[node]) if(!vis[nxt]) dfs2(nxt);
}

void susy(){
    FOR(i, n) vis[i] = false;
    FOR(i, n) if(!vis[i]) dfs1(i);

    reverse(all(order));
    FOR(i, n) vis[i] = false;
    for(auto node : order){
        if(!vis[node]){
            scc.clear();
            dfs2(node);

            int root = scc.front();
            for(auto node : scc){
                roots[node] = root;
                aa[root] += a[node];
            }

            root_nodes.PB(root);
        }
    }

    FOR(node, n){
        for(auto nxt : adj[node]){
            int root_nxt = roots[nxt], root_node = roots[node];
            if(root_nxt != root_node) adj_scc[root_node].PB(root_nxt);
        }
    }
}

void solve(){
    FOR(i, n) vis[i] = false;
    priority_queue <pii> pq;
    dp[roots[s]] = aa[roots[s]];
    pq.push({dp[roots[s]], roots[s]});
    while(!pq.empty()){
        int node = pq.top().S;
        if(dp[node] != pq.top().S);
        pq.pop();
        for(auto nxt : adj_scc[node]){
            if(dp[node] + aa[nxt] > dp[nxt]){
                dp[nxt] = dp[node] + aa[nxt];
                pq.push({dp[nxt], nxt});
            }
        }
    }
    int ans = 0;
    FOR(i, p) ans = max(ans, dp[roots[b[i]]]);
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    read();
    susy();
    solve();

    return 0;
}
