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

struct Edge{
    int x, y, w;
}edge[N];
vector <int> adj[N];

int n, k, v1, v2;
int child[N], tp[N], h[N];

void read(){
    cin >> n >> k >> v1 >> v2;
    FOR(i, n - 1){
        cin >> edge[i].x >> edge[i].y >> edge[i].w;
        adj[edge[i].x].PB(edge[i].y);
        adj[edge[i].y].PB(edge[i].x);
    }
}

void DFS0(int node, int par){
    for(auto nxt : adj[node])
        if(nxt != par){
            DFS0(nxt, node);
            child[node] += child[nxt] + 1;
        }
}

void DFS1(int node, int par){
    h[node] = h[par] + 1;
    if(node != 1) tp[node] = tp[par] + child[par] - child[node];
    for(auto nxt : adj[node])
        if(nxt != par) DFS1(nxt, node);
}

bool compare(double a, double b){return a > b;}

void solve(){
    vector <double> b;
    FOR(i, n - 1){
        int x = edge[i].x, y = edge[i].y;
        if(h[x] < h[y]) swap(x, y);
        double orig = (double)edge[i].w / v1 * (child[x] + 1) * (tp[y] + child[y] - child[x]);
        double upgr = (double)edge[i].w / v2 * (child[x] + 1) * (tp[y] + child[y] - child[x]);
        b.PB((double)orig - upgr);
    }
    double ans = 0;
    sort(all(b), compare);
    FOR(i, k) ans += b[i-1];
    cout << fixed << setprecision(2) << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    read();
    DFS0(1, 0);
    DFS1(1, 0);
    solve();

    return 0;
}
