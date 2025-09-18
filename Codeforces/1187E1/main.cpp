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
const ll INF = 1e18;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int n, child[N];
ll dp[N], dp2[N];
vector <int> adj[N];

void DFS1(int node, int par){
    for(auto nxt : adj[node]){
        if(nxt == par) continue;
        DFS1(nxt, node);
        child[node] += child[nxt];
        dp[node] += dp[nxt];
    }
    child[node]++;
    dp[node] += child[node];
}

void DFS2(int node, int par, ll down){
    if(node == 1) dp2[node] = dp[node];
    else{
        for(auto nxt : adj[node]){
            if(nxt == par) continue;
            dp2[node] += dp[nxt];
        }
        dp2[node] += down + n;
    }
    for(auto nxt : adj[node]){
        if(nxt == par) continue;
        DFS2(nxt, node, dp2[node] - dp[nxt] - child[nxt] - 1);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n;
    FOR(i, n - 1){
        int x, y; cin >> x >> y;
        adj[x].PB(y);
        adj[y].PB(x);
    }

    DFS1(1, 0);
    FOR(i, n) --child[i];
    DFS2(1, 0, 0LL);
    ll ans = 0;
    FOR(i, n) ans = max(ans, dp2[i]);
    cout << ans;

    return 0;
}

