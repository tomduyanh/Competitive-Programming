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
const int M = 5e2 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int n, m, st = 0;
int mtrx[M][M], hole[M][M], idx[M][M];
bool vis[N], ok[N];
vector <pii> adj[N];

void read(){
    cin >> n >> m;
    FOR(i, n) FOR(j, m) cin >> mtrx[i][j];
    FOR(i, n) FOR(j, m) cin >> hole[i][j];
    int nn = 0;
    FOR(i, n) FOR(j, m) idx[i][j] = ++nn;
    FOR(i, n){
        FOR(j, m){
            if(hole[i][j]){
                ok[idx[i][j]] = 1;
                st = idx[i][j];
            }
            if(1 < i) adj[idx[i][j]].PB({idx[i-1][j], abs(mtrx[i][j] - mtrx[i-1][j])});//, adj[idx[i-1][j]].PB({idx[i][j], abs(mtrx[i][j] - mtrx[i-1][j])});
            if(1 < j) adj[idx[i][j]].PB({idx[i][j-1], abs(mtrx[i][j] - mtrx[i][j-1])});//, adj[idx[i][j-1]].PB({idx[i][j], abs(mtrx[i][j] - mtrx[i][j-1])});
            if(i < n) adj[idx[i][j]].PB({idx[i+1][j], abs(mtrx[i][j] - mtrx[i+1][j])});//, adj[idx[i+1][j]].PB({idx[i][j], abs(mtrx[i][j] - mtrx[i+1][j])});
            if(j < m) adj[idx[i][j]].PB({idx[i][j+1], abs(mtrx[i][j] - mtrx[i][j+1])});//, adj[idx[i][j+1]].PB({idx[i][j], abs(mtrx[i][j] - mtrx[i][j+1])});
        }
    }
    n = nn;
}

void DFS(int node, int mx){
    if(vis[node]) return;
    vis[node] = 1;
    for(auto it : adj[node]){
        int nxt = it.F, w = it.S;
        if(w > mx || vis[nxt]) continue;
        DFS(nxt, mx);
    }
}

bool check(int k){
    FOR(i, n) vis[i] = false;
    DFS(st, k);
    FOR(i, n) if(ok[i] && !vis[i]) return false;
    return true;
}

void solve(){
    int lo = 0, hi = (int)1e9, ans = 0;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(check(mid)){
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("GOLF.INP", "r", stdin);
    freopen("GOLF.OUT", "w", stdout);
    //srand(time(NULL));

    read();
    solve();

    return 0;
}

