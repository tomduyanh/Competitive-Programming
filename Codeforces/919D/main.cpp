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

int n, m, a[N], status[N], dp[N][27];
vector <int> adj[N];
bool ok = true;

void read(){
    cin >> n >> m;
    FOR(i, n){
        char x; cin >> x;
        a[i] = x - 'a' + 1;
    }
    FOR(i, m){
        int x, y; cin >> x >> y;
        adj[x].PB(y);
    }
}

void DFScheck(int node){
    if(status[node] == 1) ok = false;
    if(!ok) return;
    status[node] = 1;
    for(auto nxt : adj[node]) DFScheck(nxt);
    status[node] = 2;
}

bool check(){
    FOR(i, n) if(status[i] == 0) DFScheck(i);
    return ok;
}

void DFS(int node){
    if(status[node] == 2) return;
    status[node] = 1;
    for(auto nxt : adj[node]){
        if(status[node] !   = 0){
            DFS(nxt);
            for(int i = 1; i <= 26; ++i) dp[node][i] += dp[nxt][i];
        }
    }
    dp[node][a[node]]++;
    status[node] = 2;
}

void solve(){
    FOR(i, n) status[i] = 0;
    FOR(i, n) if(!status[i]) DFS(i);
    int ans = 0;
    FOR(i, n) FOR(j, 26) ans = max(ans, dp[i][j]);
    cout << dp[3][1] << sp << dp[2][1] << sp << dp[1][1] << nl;
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    read();
    if(!check()) cout << -1;
    else solve();

    return 0;
}

