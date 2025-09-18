#include <bits/stdc++.h>
using namespace std;

#define int long long
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

int n, sum = 0, a[N], s[N];
ll ans[N];
vector <pii> adj[N];

void DFS0(int node, int par){
    for(auto it : adj[node]){
        int nxt = it.F;
        if(nxt != par){
            DFS0(nxt, node);
            s[node] += s[nxt];
        }
    }
    s[node] += a[node];
}

int DFS1(int node, int par){
    ll ans = 0;
    for(auto it : adj[node]){
        int nxt = it.F, w = it.S;
        if(nxt != par){
            ans += s[nxt] * w + DFS1(nxt, node);
        }
    }
    return ans;
}

void DFS2(int node, int par){
    for(auto it : adj[node]){
        int nxt = it.F, w = it.S;
        if(nxt != par){
            ans[nxt] = ans[node] + w * (sum - 2 * s[nxt]);
            DFS2(nxt, node);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n;
    FOR(i, n - 1){
        int x, y, w; cin >> x >> y >> w;
        adj[x].PB({y, w});
        adj[y].PB({x, w});
    }
    FOR(i, n){
        cin >> a[i];
        sum += a[i];
    }

    DFS0(1, 0);
    ans[1] = DFS1(1, 0);
    DFS2(1, 0);
    ll mn = INF, mx = -INF;
    FOR(i, n) mn = min(mn, ans[i]), mx = max(mx, ans[i]);
    cout << mn << sp << mx;

    return 0;
}

