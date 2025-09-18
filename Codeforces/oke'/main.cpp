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

const int N = 4e5 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int n, m, timer = 0;
int a[N], lo[N], hi[N];
int color[N][65];
vector <int> adj[N];
pll seg[4*N][65];

void DFS(int node, int par){
    lo[node] = ++timer;
    color[timer][a[node]] = 1;
    for(auto nxt : adj[node]) if(nxt != par) DFS(nxt, node);
    hi[node] = timer;
}

void build(int id, int l, int r, int c){
    if(l == r){
        seg[id][c].F = color[l][c];
        return;
    }
    int mid = (l + r) / 2;
    build(id*2, l, mid, c);
    build(id*2+1, mid+1, r, c);
    seg[id][c].F = max(seg[id*2][c].F, seg[id*2+1][c].F);
}

void down(int id, int c){
    int hold = seg[id][c].S;
    if(hold == -1) return;
    seg[id*2][c].F = seg[id*2+1][c].F = seg[id*2][c].S = seg[id*2+1][c].S = hold;
    seg[id][c].S = -1;
}

void update(int id, int l, int r, int u, int v, int c, int val){
    if(v < l || r < u) return;
    if(u <= l && r <= v){
        seg[id][c].F = seg[id][c].S = val;
        return;
    }
    int mid = (l + r) / 2;
    down(id, c);
    update(id*2, l, mid, u, v, c, val);
    update(id*2+1, mid+1, r, u, v, v, val);
    seg[id][c].F = max(seg[id*2][c].F, seg[id*2+1][c].F);
}

int get(int id, int l, int r, int u, int v, int c){
    if(v < l || r < u) return 0;
    if(u <= l && r <= v) return seg[id][c].F;
    int mid = (l + r) / 2;
    down(id, c);
    return max(get(id*2, l, mid, u, v, c), get(id*2+1, mid+1, r, u, v, c));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n >> m;
    FOR(i, n) cin >> a[i];
    FOR(i, n-1){
        int x, y; cin >> x >> y;
        adj[x].PB(y);
        adj[y].PB(x);
    }
    DFS(1, 0);
    FOR(i, 60) build(1, 1, timer, i);
    FOR(i, timer*4) FOR(j, 60) seg[i][j].S = -1;
    FOR(c, 60){
        FOR(i, timer) cout << "w" << color[i][c] << sp;
        cout << nl;
    }
    while(m--){
        int t; cin >> t;
        if(t == 1){
            int s, v; cin >> s >> v;
            FOR(c, 60){
                if(c == v) update(1, 1, timer, lo[s], hi[s], c, 1);
                else update(1, 1, timer, lo[s], hi[s], c, 0);
            }
        }
        else{
            int v; cin >> v;
            int ans = 0;
            FOR(c, 60){
                int g = get(1, 1, timer, lo[v], hi[v], c);
                if(g) ++ans;
            }
            cout << ans << nl;
        }
    }

    return 0;
}

