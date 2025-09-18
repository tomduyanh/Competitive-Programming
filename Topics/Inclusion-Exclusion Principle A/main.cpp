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
#define FORR(i, n) for(int i = n; i > 0; --i)

const int N = 1e6 + 5;
const int MOD = 2021;
const ll INF = 1e18;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int n, k;
int dp[N], c[N]; bool vis[N];
vector <int> adj[N];

void read(){
    cin >> n >> k;
    FOR(i, n) cin >> c[i];
    FOR(i, n - 1){
        int x, y; cin >> x >> y;
        adj[x].PB(y);
        adj[y].PB(x);
    }
}

bool on(int sub, int bit){
    return (sub & (1 << (bit - 1)));
}

void RESET(int sub){
    FOR(i, n){
        dp[i] = 0;
        vis[i] = false;
    }
}

void DFS(int node, int sub, int par){
    vis[node] = true;
    bool ok = false; int ans = 0, sum = 0;
    for(auto nxt : adj[node]){
        if(vis[nxt] || !(on(sub, c[nxt])) || nxt == par) continue;
        DFS(nxt, sub, node);
    }
    for(int i = 0; i < adj[node].size(); ++i){
        int nxt = adj[node][i];
        if(!on(sub, c[nxt]) || nxt == par) continue;
        sum = (dp[nxt] * (1 + ans)) % MOD;
        ans = (ans + sum) % MOD;
    }
    dp[node] += ans + 1;
}

int get(int sub){
    RESET(sub);
    int ans = 0;
    FOR(i, n){
        if(!vis[i] && on(sub, c[i])){
            DFS(i, sub, 0);
        }
    }
    FOR(i, n){
        if(on(sub, c[i])){
            ans = (ans + dp[i]) % MOD;
        }
    }
    return ans;
}

void solve(){
    int ans = get((1 << k) - 1);
    FOR(sub, (1 << k) - 2){
        int val = get(sub), sz = k - __builtin_popcount(sub);
        if(sz % 2) ans = (ans - val + MOD) % MOD;
        else ans = (ans + val) % MOD;
    }
    cout << ans;
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

