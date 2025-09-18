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

int n, m, cur = 0;
int scc[N];
vector <int> adj[N], radj[N];
stack <int> st;
bool vis[N], found = false;

void DFS1(int node){
    if(vis[node]) return;
    vis[node] = true;
    for(auto nxt : adj[node])
        if(!vis[nxt]) DFS1(nxt);
    st.push(node);
}

void DFS2(int node){
    if(vis[node]) return;
    vis[node] = true;
    for(auto nxt : radj[node])
        if(!vis[nxt]) DFS2(nxt);
    scc[node] = cur;
}

void DFS3(int node, int en){
    if(en == node) found = 1;
    if(vis[node] || found) return;
    vis[node] = 1;
    for(auto nxt : adj[node])
        if(!vis[nxt]) DFS3(nxt, en);
}

int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int x, y; cin >> x >> y;
        adj[x].PB(y);
        radj[y].PB(x);
    }

    FOR(i, n)
        if(!vis[i]) DFS1(i);
    FOR(i, n) vis[i] = false;
    while(!st.empty()){
        int node = st.top(); st.pop();
        if(!vis[node]){
            ++cur;
            DFS2(node);
        }
    }

    int x = 1, y = 1;
//    FOR(i, n) cout << i << sp << scc[i] << nl;
    for(int i = 2; i <= n; ++i)
        if(scc[i] != scc[x]){
            y = i;
            break;
        }

    if(x == y) cout << "YES";
    else {
        cout << "NO\n";
        FOR(i, n) vis[i] = 0;
        DFS3(x, y);
        if(found) cout << y << sp << x;
        else cout << x << sp << y;
    }

    return 0;
}

