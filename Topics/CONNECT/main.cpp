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
    if(fopen("SCONNECT.INP", "r")){
        freopen("SCONNECT.INP", "r", stdin);
        freopen("SCONNECT.OUT", "w", stdout);
    }
}

int n, m, cnt = 0;
bool vis[N] = {false};
vector <int> adj[N], radj[N];
stack <int> st;

void read(){
    cin >> n >> m;
    FOR(i, m){
        int x, y; cin >> x >> y;
        adj[x].PB(y);
        radj[y].PB(x);
    }
}

void DFS1(int node){
    if(vis[node]) return;
    vis[node] = true;
    for(auto nxt : adj[node]){
        if(vis[nxt]) continue;
        DFS1(nxt);
    }
    st.push(node);
}

void DFS2(int node){
    if(vis[node]) return;
    vis[node] = true;
    for(auto nxt : radj[node]){
        if(vis[nxt]) continue;
        DFS2(nxt);
    }
    cout << node << sp;
}

void solve(){
    FOR(i, n)
        if(!vis[i]) DFS1(i);
    FOR(node, n) vis[node] = false;
    while(!st.empty()){
        int node = st.top(); st.pop();
        if(!vis[node]){
            DFS2(node);
            cout << nl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freop();
    //srand(time(NULL));

    read();
    solve();

    return 0;
}

