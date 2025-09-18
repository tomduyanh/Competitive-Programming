
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
int max1[N], max2[N], dp[N];
vector <int> adj[N];

void DFS1(int node, int par){
    for(auto nxt : adj[node]){
        if(nxt == par) continue;
        DFS1(nxt, node);
        if(max1[nxt] + 1 > max1[node]){
            max2[node] = max1[node];
            max1[node] = max1[nxt] + 1;
        }
        else if(max1[nxt] + 1 > max2[node]){
            max2[node] = max1[nxt] + 1;
        }
    }
}

void DFS2(int node, int par, int top){
    dp[node] = max(max1[node], top);
    for(auto nxt : adj[node]){
        if(nxt == par) continue;
        if(max1[nxt] + 1 == max1[node]) DFS2(nxt, node, max(top, max2[node]) + 1);
        else DFS2(nxt, node, dp[node] + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n;
    FOR(i, n-1){
        int x, y; cin >> x >> y;
        adj[x].PB(y);
        adj[y].PB(x);
    }

    DFS1(1, 0);
    DFS2(1, 0, 0);

    FOR(i, n) cout << dp[i] << sp;

    return 0;
}

