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

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int n, m;
vector <int> adj[N+1];

bool compare(pii a, pii b){
    return a.F < b.F;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        vector <pii> sz(n+1);
        for(int i = 1; i <= n; ++i){
            adj[i].clear();
            sz[i].S = i;
        }
        for(int i = 1; i <= m; ++i){
            int x, y; cin >> x >> y;
            adj[x].PB(y);
            adj[y].PB(x);
            ++sz[x].F; ++sz[y].F;
        }
        sort(all(sz), compare);
        map <int, bool> vis;
        for(int i = 1; i <= n; ++i){
            int it = sz[i].S;
            if(vis[it]) continue;
            for(auto nxt : adj[it]) vis[nxt] = true;
        }
        vector <int> ans;
        for(int i = 1; i <= n; ++i)
            if(vis[i]) continue;
            else ans.PB(i);
        cout << ans.size() << nl;
        for(auto it : ans) cout << it << sp;
        cout << nl;
    }

    return 0;
}

