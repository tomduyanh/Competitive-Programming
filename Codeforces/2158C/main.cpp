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
    freopen("banhkeo.INP", "r", stdin);
    freopen("banhkeo.OUT", "w", stdout);
}

int n, m, k, p = 501;
vector <int> adj[N];
bool vis[N];

void DFS(int node){
    if(vis[node]) return;
    vis[node] = true;
    for(auto nxt : adj[node]){
        if(!vis[nxt]){
            DFS(nxt);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freop();
    //srand(time(NULL));

    cin >> n >> m >> k;
    for(int i = 0; i < k; ++i){
        int x; cin >> x;
        p = min(p, x);
    }
    for(int i = 0; i < m; ++i){
        int a, b, t; cin >> a >> b >> t;
        if(t < p) continue;
        adj[a].PB(b);
        adj[b].PB(a);
    }

    int ans = 0;
    for(int i = 1; i <= n; ++i){
        if(!vis[i]){
            DFS(i);
            ++ans;
        }
    }
    cout << ans;

    return 0;
}

