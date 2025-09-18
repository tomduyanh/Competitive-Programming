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

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int n, q, cnt = 0;
int v[N];
int p[N], dep[N], seg[2*N];
int sz[N], tp[N], id[N];
vector <int> adj[N];

void update(int node, int val){
    seg[node += n] = val;
    for(node /= 2; node > 0; node /= 2) seg[node] = max(seg[node*2], seg[node*2+1]);
}

int get(int lo, int hi) {
	int ra = 0, rb = 0;
	for (lo += n, hi += n + 1; lo < hi; lo /= 2, hi /= 2) {
		if (lo & 1) ra = max(ra, seg[lo++]);
		if (hi & 1) rb = max(rb, seg[--hi]);
	}
	return max(ra, rb);
}

void read(){
    cin >> n >> q;
    FOR(i, n){
        cin >> v[i];
        sz[i] = 1;
    }
    FOR(i, n - 1){
        int x, y; cin >> x >> y;
        adj[x].PB(y);
        adj[y].PB(x);
    }
}

void DFSsz(int node, int par){
    dep[node] = dep[par] + 1;
    p[node] = par;
    for(auto nxt : adj[node])
        if(nxt != par){
            DFSsz(nxt, node);
            sz[node] += sz[nxt];
        }
}

void DFShld(int node, int par, int top){
    tp[node] = top;
    id[node] = ++cnt;
    update(id[node], v[node]);
    int h_child = -1;
    for(auto nxt : adj[node]){
        if(nxt == par) continue;
        if(h_child == -1 || sz[nxt] > sz[h_child]) h_child = nxt;
    }
    if(h_child == -1) return;
    DFShld(h_child, node, top);
    for(auto nxt : adj[node]){
        if(nxt != par && nxt != h_child) DFShld(nxt, node, nxt);
    }
}

void build(){
   DFSsz(1, 1);
   DFShld(1, 1, 1);
}

int query(int x, int y){
    int res = 0;
    while(tp[x] != tp[y]){
        if(dep[tp[x]] < dep[tp[y]]) swap(x, y);
        res = max(res, get(id[tp[x]], id[x]));
        x = p[tp[x]];
    }
    if(dep[x] > dep[y]) swap(x, y);
    res = max(res, get(id[x], id[y]));
    return res;
}

void solve(){
    while(q--){
        int type; cin >> type;
        if(type == 1){
            int node, val; cin >> node >> val;
            v[node] = val;
            update(id[node], v[node]);
        }
        else{
            int nodea, nodeb; cin >> nodea >> nodeb;
            cout << query(nodea, nodeb) << nl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    read();
    build();
    solve();

    return 0;
}

