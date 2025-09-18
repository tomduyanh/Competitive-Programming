#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int n, c[N], res[N];
vector <int> adj[N];
map <int, int> ans[N], sus[N];

void DFS(int node, int par){
    ans[node][c[node]] = 1;
    bool ok = false;
    for(auto nxt : adj[node]){
        if(nxt == par) continue;
        DFS(nxt, node);
        if(ans[node].size() < ans[nxt].size()){ ///so mau
            swap(ans[node], ans[nxt]);
            swap(sus[node], sus[nxt]);
        }
        for(auto it : ans[nxt]){
            if(it.F == c[node]) ok = true;
            int bruv = (ans[node][it.F] += it.S);
            sus[node][bruv] += it.F;
        }
        ans[nxt].clear(), sus[nxt].clear();
    }
    if(!ok){
        sus[node][ans[node][c[node]]] += c[node];
    }
    auto sussy = ans[node].rbegin();
    res[node] = sus[node][sussy->S];
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n;
    FOR(i, n) cin >> c[i];

    FOR(i, n - 1){
        int x, y; cin >> x >> y;
        adj[x].PB(y), adj[y].PB(x);
    }

    DFS(1, 0);

    FOR(i, n) cout << res[i] << sp;

    return 0;
}
