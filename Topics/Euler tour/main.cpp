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

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int n, m;
int bac[N];
bool vis[4*N];
vector <pii> adj[N];
vector <int> ans;
priority_queue <pii> remain;
///adj[i][j].F = nxt
///adj[i][j].S = id

void read(){
    cin >> n >> m;
    FOR(i,m){
        int x, y; cin >> x >> y;
        adj[x].PB({y,i});
        adj[y].PB({x,i});
        bac[x]++, bac[y]++;
    }
}

void DFS(int node, int id, int start){
    if((node == start) || (id != 0 && vis[id])) return;
    vis[id] = true;
    bac[node] -= 2;
    if(bac[node]) remain.push({bac[node], node});
    for(auto it : adj[node]){
        int nxt = it.F, id = it.S;
        DFS(nxt, id, start);
    }
}

void solve(){
    remain.push({bac[1], 1});
    while(!remain.empty()){
        int top = remain.top().S;
        remain.pop();
        DFS(top, 0, top);
    }
    cout << "w";
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


