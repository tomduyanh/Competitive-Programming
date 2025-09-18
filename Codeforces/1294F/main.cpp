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

int n;
int dp1[N], dp2[N], ans[N];
int dis[N], pre[N];
vector <int> path;
vector <int> adj[N];

void DFS1(int node, int par){
    for(auto nxt : adj[node]){
        if(nxt == par) continue;
        DFS1(nxt, node);
        if(dp1[nxt] + 1 >= dp1[node]){
            dp2[node] = dp1[node];
            dp1[node] = dp1[nxt] + 1;
        }
        else if(dp1[nxt] + 1 >= dp2[node]){
            dp2[node] = dp1[nxt] + 1;
        }
    }
}

void DFS2(int node, int par, int top){
    ans[node] = max(dp1[node], top);
    for(auto nxt : adj[node]){
        if(nxt == par) continue;
        if(dp1[nxt] + 1 == dp1[node]) DFS2(nxt, node, max(top, dp2[node]) + 1);
        else DFS2(nxt, node, ans[node] + 1);
    }
}

void DFS3(int node, int par){
    pre[node] = par;
    for(auto nxt : adj[node]){
        if(nxt == par) continue;
        dis[nxt] = dis[node] + 1;
        DFS3(nxt, node);
    }
}

void trace(int idx1, int idx2){
    while(idx2 != idx1){
        path.PB(idx2);
        idx2 = pre[idx2];
    }
    path.PB(idx1);
}

void DFS4(int node, int par, int trc, int sau){
    for(auto nxt : adj[node]){
        if(nxt == par || nxt == trc || nxt == sau) continue;
        dis[nxt] = dis[node] + 1;
        DFS4(nxt, node, trc, sau);
    }
}

int main(){
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
    DFS2(1, 0, 0);

    vector <pii> ok;
    FOR(i, n) ok.PB({ans[i], i});
    sort(all(ok));

    int idx1 = ok[ok.size()-1].S, idx2 = 0, idx3 = 0;
    DFS3(idx1, 0);
    FOR(i, n){
        if(dis[i] == ok[ok.size()-1].F) idx2 = i;
        dis[i] = 0;
    }

    trace(idx1, idx2);
    for(int i = 1; i < path.size() - 1; ++i){
        int trc = path[i-1], nxt = path[i+1], node = path[i];
        DFS4(node, 0, trc, nxt);
    }
    FOR(i, n) if(i !dis[i] >= dis[idx3]) idx3 = i;

    cout << dis[idx3] + ok[ok.size()-1].F << nl << idx1 << sp << idx2 << sp << idx3;

    return 0;
}
