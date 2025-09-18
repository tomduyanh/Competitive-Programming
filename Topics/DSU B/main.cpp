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

int n, m;
int par[N], sz[N], ans[N];
pii v[N];
bool vis[N];
vector <int> adj[N];

int root(int node){
    while(node != par[node]) node = par[node];
    return node;
}

void unite(int x, int y){
    x = root(x), y = root(y);
    if(x == y) return;
    if(sz[x] < sz[y]) swap(x, y);
    sz[x] += sz[y];
    par[y] = x;
}

void read(){
    cin >> n >> m;
    FOR(i, n) {
        cin >> v[i].F;
        v[i].S = par[i] = i;
        sz[i] = 1;
        ans[i] = ans[i+1] = -1;
    }
    FOR(i, m){
        int x, y; cin >> x >> y;
        adj[x].PB(y), adj[y].PB(x);
    }
}

bool compare(pii a, pii b) {return a.F > b.F;}

void solve(){
    sort(v + 1, v + n + 1, compare);
    FOR(i, n){
        vis[v[i].S] = true;
        for(auto nxt : adj[v[i].S]){
            if(vis[nxt]){
                unite(nxt, v[i].S);
            }
        }
        int rt = root(v[i].S);
        ans[sz[rt]] = max(ans[sz[rt]], v[i].F);
    }
    for(int i = n; i > 0; --i) ans[i] = max(ans[i], ans[i + 1]);
    FOR(i, n) cout << ans[i] << sp;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    read();
    solve();

    return 0;
}
