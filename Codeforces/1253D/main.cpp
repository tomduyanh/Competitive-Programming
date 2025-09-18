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

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int n, m;
int mx, mn, sz;
bool vis[N], ok[N];
vector <int> adj[N];

struct Num{
    int F, S, sz;
};

bool compare(Num a, Num b){
    return a.F < b.F || (a.F == b.F && a.S > b.S);
}

void DFS(int node){
    if(vis[node]) return;
    vis[node] = true;
    ++sz;
    mx = max(mx, node);
    mn = min(mn, node);
    for(auto nxt : adj[node]){
        if(vis[nxt]) continue;
        DFS(nxt);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n >> m;
    FOR(i, m){
        int x, y; cin >> x >> y;
        adj[x].PB(y), adj[y].PB(x);
        ok[x] = ok[y] = true;
    }

    vector <Num> a;
    FOR(i, n){
        if(vis[i] || !ok[i]) continue;
        sz = 0, mx = 0, mn = n + 1;
        DFS(i);
        a.PB({mn, mx, sz});
    }
    sort(all(a), compare);
    int ans = 0, l = n+1, r = 0, cur_sz = 0;
    for(int i = 1; i < a.size(); ++i){
        int pre_l = a[i-1].F, pre_r = a[i-1].S;
        int cur_l = a[i].F, cur_r = a[i].S;
        l = min(l, pre_l);
        r = max(r, pre_r);
        cur_sz += a[i-1].sz;
        if(pre_l <= cur_l && cur_l <= pre_r){
            ++ans;
        }
        else{
            ans += r - l + 1 - cur_sz;
            l = n+1;
            r = 0;
            cur_sz = 0;
        }
    }
    l = min(l, a[a.size()-1].F);
    r = max(r, a[a.size()-1].S);
    cur_sz += a[a.size()-1].sz;
    ans += r - l + 1 - cur_sz;
    cout << ans;

    return 0;
}


