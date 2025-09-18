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

const int N = 1e3 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int n, m, s, t;
int capacity[N][N];
vector <int> adj[N];

int bfs(int s, int t, vector <int>& par){
    fill(all(par), -1);
    par[s] = -2;
    queue <pii> q;
    q.push({s, INF});
//    cout << "r";

    while(!q.empty()){
        int node = q.front().F, flow = q.front().S;
        if(node == t) return flow;
        q.pop();

        for(auto nxt : adj[node]){
            if(par[nxt] == -1 && capacity[node][nxt]){
                par[nxt] = node;
                int new_flow = min(flow, capacity[node][nxt]);
                q.push({nxt, new_flow});
            }
        }
    }
//    cout << "ok";
    return 0;
}

int maxflow(int s, int t){
//    cout << "w";
    int flow = 0;
    vector <int> par(n+1);
    int new_flow;

    while(new_flow = bfs(s, t, par)){
//        cout << "w";
        flow += new_flow;
        int node = t;
        while(node != s){
            int pre = par[node];
            capacity[pre][node] -= new_flow;
            capacity[node][pre] += new_flow;
            node = pre;
        }
    }

    return flow;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n >> m >> s >> t;
    FOR(i, m){
        int x, y, w; cin >> x >> y >> w;
        adj[x].PB(y);
        capacity[x][y] = w;
        adj[y].PB(x);
    }

    cout << maxflow(s, t);

    return 0;
}

