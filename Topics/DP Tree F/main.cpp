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

int n, root = 1, a[N];
vector <int> adj[N];

void read(){
    cin >> n;
    FOR(i, n) cin >> a[i];
    map <int, int> mp;
    FOR(i, n - 1){
        int x, y; cin >> x >> y;
        adj[x].PB(y); adj[y].PB(x);
        ++mp[x];
    }
    FOR(i, n) if(!mp[i]) root = i;
}

int DFS(int node, int par, int status){
    int ans = 0;
    for(auto nxt : adj[node]){
        if(nxt == par) continue;
        int cur = DFS(nxt, node, 0);
        if(!status) cur = max(cur   , DFS(nxt, node, 1));
        ans += cur;
    }
    if(status) ans += a[node];
    return ans;
}

void solve(){
    cout << DFS(root, 0, 1);
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


