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
int t = 0, cnt = 0;
int low[N], num[N], scc[N];
bool vis[N] = {false};
vector <int> adj[N];
stack <int> st;

void read(){
    cin >> n >> m;
    FOR(i, m){
        int x, y; cin >> x >> y;
        adj[x].PB(y);
    }
}

void DFS(int node){
    vis[node] = true;
    st.push(node);
    low[node] = num[node] = ++t;
    for(auto nxt : adj[node]){
        if(!vis[nxt]){
            DFS(nxt);
            low[node] = min(low[node], low[nxt]);
        }
        else if(scc[nxt] == 0) low[node] = min(low[node], num[nxt]);
    }
    if(low[node] == num[node]){
        int nxt = 0; ++cnt;
        while(nxt != node){
            nxt = st.top(); st.pop();
            scc[nxt] = cnt;
        }
    }
}

void solve(){
    FOR(i, n){
        if(vis[i]) continue;
        DFS(i);
    }
    cout << cnt << nl;
    FOR(i, n) cout << scc[i] << sp;
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


