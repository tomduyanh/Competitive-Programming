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

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen(".INP", "r", stdin);
    freopen(".OUT", "w", stdout);
}

int n;
vector <int> adj[N];
int a[N];

void read() {
    cin >> n;
    for(int i = 1; i < n; ++i) {
        int x, y; cin >> x >> y;
        adj[x].PB(y);
        adj[y].PB(x);
    }
    for(int i = 1; i <= n; ++i) cin >> a[i];
}

int cnt[N], pa[N], H[N];

void DFS(int node, int pre, int h) {
    H[node] = h;
    for(auto nxt : adj[node]) {
        if(nxt == pre) continue;
        ++cnt[node];
        pa[nxt] = node;
        DFS(nxt, node, h + 1);
    }
}

bool solve() {
    vector <int> par(n + 5);
    int j = 1;
    for(int i = 1; i <= n; ++i)
        for(int k = 1; k <= cnt[a[i]]; ++k) par[a[++j]] = a[i];
    for(int i = 2; i <= n; ++i) {
        if((H[a[i - 1]] > H[a[i]]) || (par[a[i]] != pa[a[i]])) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();

    read();
    DFS(1, 0, 1);
    cout << (solve() ? "Yes" : "No");

    return 0;
}
