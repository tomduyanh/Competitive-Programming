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
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int n, m;
int a[N], aa[N]; bool vis[N];
ll dp[N];
vector <int> adj[N], radj[N];
vector <int> order, scc;
vector <int> roots(N, 0), root_nodes;
std::vector <vector<int>> adj_scc(N);

void read(){
    cin >> n >> m;
    FOR(i, n) cin >> a[i];
    FOR(i, m){
        int x, y; cin >> x >> y;
        adj[x].PB(y);
        radj[y].PB(x);
    }
}

void dfs1(int node){
    vis[node] = true;
    for(auto nxt : adj[node])
        if(!vis[nxt]) dfs1(nxt);
    order.PB(node);
}

void dfs2(int node){
    vis[node] = true;
    scc.PB(node);
    for(auto nxt : radj[node])
        if(!vis[nxt]) dfs2(nxt);
}

void condensation(){
    FOR(i, n) vis[i] = false;
    FOR(i, n) if(!vis[i]) dfs1(i);

    FOR(i, n) vis[i] = false;
    reverse(all(order));
    for(auto it : order){
        if(!vis[it]){
            dfs2(it);

            int root = scc.front();
            for(auto node : scc){
                roots[node] = root;
                aa[root] += a[node];
//                cout << node << sp;
            }
//            cout << nl; 5
            root_nodes.PB(root);

            scc.clear();
        }
    }
//    cout << root_nodes.size() << nl;
    FOR(node, n){
        for(auto nxt : adj[node]){
            int root_nxt = roots[nxt];
            int root_node = roots[node];
            if(root_node != root_nxt) adj_scc[root_node].PB(root_nxt);
        }
    }
}

void dfs3(int node){
    vis[node] = true;
    for(auto nxt : adj_scc[node]){
        if(!vis[nxt]) dfs3(nxt);
        dp[node] = max(dp[node], dp[nxt] + aa[node]);
    }
    dp[node] = max(dp[node], (ll)aa[node]);
}

void solve(){
    FOR(i, n) vis[i] = false;
    for(auto node : root_nodes){
        if(vis[node]) continue;
        dfs3(node);
    }
    ll ans = 0;
    for(auto node : root_nodes){
        ans = max(ans, dp[node]);
    }
    cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    read();
    condensation();
    solve();

    return 0;
}

