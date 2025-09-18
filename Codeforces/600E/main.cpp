#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int,int> pii;
typedef pair <ll , ll> pll;

#define int long long
#define sp " "
#define nl "\n"
#define F first
#define S second
#define PB push_back
#define all(arr) arr.begin(), arr.end()

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen(".INP", "r", stdin);
    freopen(".OUT", "w", stdout);
}

int n;
int a[N];
vector <int> adj[N+1];
map <int, int> mp[N+1];

void read(){
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for(int i = 1; i < n; ++i){
        int x, y; cin >> x >> y;
        adj[x].PB(y);
        adj[y].PB(x);
    }
}

void DFS1(int node, int par){
    for(auto nxt : adj[node]){
        if(nxt == par) continue;
        DFS1(nxt, node);
        for(map <int, int> :: iterator it = mp[nxt].begin(); it != mp[nxt].end(); ++it){
            mp[node][it->F] += it->S;
        }
    }
    mp[node][a[node]]++;
}

void solve(){
    DFS1(1, 0);
    for(int i )
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    read();
    solve();

    return 0;
}
