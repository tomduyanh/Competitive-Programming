#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int,int> pii;
typedef pair <int , int> pint;

#define sp " "
#define nl "\n"
#define F first
#define S second
#define PB push_back
#define aint(arr) arr.begin(), arr.end()

const int N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen(".INP", "r", stdin);
    freopen(".OUT", "w", stdout);
}

ll disF[N], disS[N];

vector <pii> adj[N];

int n;

void read() {
    cin >> n;
    for(int i = 1; i < n; ++i) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].PB({b, c});
        adj[b].PB({a, c});
    }
}


void DFS1(int node, int pre) {
    for(auto it : adj[node]) {
        int nxt = it.F, w = it.S;
        if(pre == nxt) continue;
        DFS1(nxt, node);
        if(disF[nxt] + w > disF[node]) {
            disS[node] = disF[node];
            disF[node] = disF[nxt] + w;
        }
        else if(disF[nxt] + w > disS[node]) {
            disS[node] = disF[nxt] + w;
        }
    }
}

ll ans[N];

void DFS2(int node, int pre, ll pot) {
    ans[node] = max(pot, disF[node]);
    for(auto it : adj[node]) {
        int nxt = it.F, w = it.S;
        if(nxt == pre) continue;
        if(disF[nxt] + w == disF[node]) DFS2(nxt, node, max(pot, disS[node])+w);
        else DFS2(nxt, node, ans[node] + w);
    }
}

void solve() {
    DFS1(1, 0);
    DFS2(1, 0, 0);
    ll res = 0;
    for(int i = 1; i <= n; ++i) res = max(res, ans[i]);
    cout << res;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();

    read();
    solve();

    return 0;
}
