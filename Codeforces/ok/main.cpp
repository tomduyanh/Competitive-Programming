#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define sp " "
#define nl "\n"
#define PB push_back
#define pii pair<int,int>
#define FOR(i, n) for(int i=1;i<=n;++i)
const int N = 1e5 + 1;
int n, m, q, timer=0;
int num[N], low[N];
bool bridge[5001][5001], ok[5001][5001];
vector <int> adj[N];
vector <pii> check;
map<pii,bool> br;
map<pii,bool> path;
bool vis[N];
void DFS1(int node, int par){
    ++timer;
    num[node] = low[node] = timer;
    for(auto nxt : adj[node]){
        if(num[nxt]){
            if(nxt!=par) low[node]=min(low[node], num[nxt]);
            continue;
        }
        DFS1(nxt, node);
        low[node]=min(low[nxt], low[node]);
        if(num[nxt]==low[nxt]){
            bridge[node][nxt]=bridge[nxt][node]=1;
            br[{min(nxt,node),max(nxt,node)}]=1;
            check.PB({node, nxt});
        }
    }
}
void buildtree(){
    DFS1(1, 0);
}
bool bru[N];
void DFS2(int u, int en){
    vis[u]=bru[u]=1;
    if(u==en)return;
    for(auto v:adj[u]){
        if(!vis[v]){
            DFS2(v, en);
        }
    }
}
void DFS3(int u, int en){
    vis[u]=1;
    if(u==en)return;
    for(auto v:adj[u]){
        if(!vis[v]){
            DFS2(v, en);
            if(bru[v]){
                ok[v][u]=ok[u][v]=1;
                path[{min(u,v),max(u,v)}]=1;
            }
        }
    }
}
void sub1(){
    buildtree();
    while(q--){
        int a,b,c,d;cin>>a>>b>>c>>d;
        adj[a].PB(b);
        adj[b].PB(a);
        FOR(i, n){
            low[i]=num[i]=vis[i]=0;
            FOR(j, n) ok[i][j]=0, bridge[i][j]=0;
        }
        timer=0;
        buildtree();
        DFS2(c,d);
        FOR(i,n)vis[i]=0;
        DFS3(d,c);
        int ans=0;
        FOR(i,n){
            for(int j=i+1;j<=n;++j){
                if(ok[i][j]&&bridge[i][j]){
                    ++ans;
                }
            }
        }
        cout<<ans<<nl;
    }
}
void sub2(){
    buildtree();
    while(q--){
        int a,b,c,d;cin>>a>>b>>c>>d;
        adj[a].PB(b);
        adj[b].PB(a);
        FOR(i, n){
            low[i]=num[i]=vis[i]=0;
        }
        br.clear();
        path.clear();
        timer=0;
        buildtree();
        DFS2(c,d);
        FOR(i,n)vis[i]=0;
        DFS3(d,c);
        int ans=0;
        for(auto it : br){
            if(it.S==1&&path[it.F]==1)++ans;
        }
        cout<<ans<<nl;
    }
}
int par[N];
void dfs4(int u, int p){
    par[u]=p;
    for(auto v : adj[u]) if(v != p) dfs4(v, u);
}
int up[N][35], s[N][35];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("bridge.inp", "r", stdin);
    freopen("bridge.out", "w", stdout);
    cin>>n>>m>>q;
    FOR(i, m){
        int x, y; cin>>x>>y;
        adj[x].PB(y);
        adj[y].PB(x);
    }
//    sub2();
    if(n<=100&&m<=100&&q<=100) sub1();
    else if(n<=5000&&m<=5000&&q<=5000) sub2();
//    if(m==n-1) sub3();
    return 0;
}
