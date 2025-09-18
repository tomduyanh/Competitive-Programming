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

int n, child[N];
ll sum1[N], sum2[N];
vector <int> adj[N];

void read(){
    cin >> n;
    FOR(i, n - 1){
        int x, y; cin >> x >> y;
        adj[x].PB(y), adj[y].PB(x);
    }
}

void DFS1(int node, int par){
    for(auto nxt : adj[node])
        if(nxt != par){
            DFS1(nxt, node);
            child[node] += child[nxt] + 1;
            sum1[node] += sum1[nxt];
        }
    sum1[node] += child[node];
}

void DFS2(int node, int par){
    if(node != 1){
        sum2[node] = sum2[par] - 2 * child[node]  + n  - 2;
    }
    for(auto nxt : adj[node])
        if(nxt != par){
            DFS2(nxt, node);
        }
}

void solve(){
    DFS1(1, 0);
    sum2[1] = sum1[1];
    DFS2(1, 0);
    FOR(i, n) cout << sum2[i] << sp;
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

