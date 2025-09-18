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

int n;
int subsize[N];
vector <int> adj[N];

void getchild(int node, int par){
    subsize[node]++;
    for(auto nxt : adj[node]){
        if(nxt == par) continue;
        getchild(nxt, node);
        subsize[node] += subsize[nxt];
    }
}

int getCentroid(int node, int par){
    for(auto nxt : adj[node]){
        if(nxt == par) continue;
        if(subsize[nxt] * 2 > n) return getCentroid(nxt, node);
    }
    return node;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n;
    FOR(i, n-1){
        int x, y; cin >> x >> y;
        adj[x].PB(y); adj[y].PB(x);
    }

    getchild(1, 0);
    cout << getCentroid(1, 0);

    return 0;
}

