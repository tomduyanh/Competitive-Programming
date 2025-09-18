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
    freopen(".INP", "r", stdin);
    freopen(".OUT", "w", stdout);
}

int n;
vector <int> adj[N];

void read(){
    cin >> n;
    for(int i = 1; i < n; ++i){
        int a, b; cin >> a >> b;
        adj[a].PB(b);
        adj[b].PB(a);
    }
    cout << nl;
    char arr [n+4]
}

int child[N];

void DFS1(int node, int pre){
    child[node] = 1;
    for(auto nxt : adj[node]){
        if(nxt == pre) continue;
        DFS1(nxt, node);
        child[node] += child[nxt];
    }
}

void solve(){
    DFS1(1, 0);
    for(int i = 1; i <= n; ++i){
        cout << i << sp << child[i] << nl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    read();
    solve();

    return 0;
}
