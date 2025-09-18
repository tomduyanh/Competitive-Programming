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
int n, child[N], dp[N];
bool vis[N];
vector <int> adj[N];
void DFS0(int node, int par){
    for(auto nxt : adj[node])
        if(nxt != par){
            DFS0(nxt, node);
            child[node] += child[nxt] + 1;
        }
}

void DFS1(int node, int par){
    vis[node] = true;
    if(adj[node].size() == 2 - (node == 1)){
        int nxt = adj[node][0];
        if(vis[nxt]) nxt = adj[node][1];
        DFS1(nxt, node);
        dp[node] = max(dp[nxt], child[nxt]);
    }
    if(adj[node].size() == 3 - (node == 1)){
        int nxt1 = adj[node][0], nxt2 = adj[node][1];
        if(vis[nxt1]) nxt1 = adj[node][2];
        if(vis[nxt2]) nxt2 = adj[node][2];
        DFS1(nxt1, node), DFS1(nxt2, node);
        dp[node] = max(child[nxt1] + dp[nxt2], child[nxt2] + dp[nxt1]);
    }
}
void reset(){
    FOR(i, n){
        child[i] = vis[i] = dp[i] = 0;
        adj[i].clear();
    }
}
void sol(){
    cin >> n; reset();
    FOR(i, n-1) {
        int x, y; cin >> x >> y;
        adj[x].PB(y); adj[y].PB(x);
    }
    DFS0(1, 0); DFS1(1, 0);
    cout << dp[1] << nl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    int t; cin >> t;
    while(t--) sol();

    return 0;
}

