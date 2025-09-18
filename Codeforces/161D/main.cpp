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

const int N = 5e4 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen(".INP", "r", stdin);
    freopen(".OUT", "w", stdout);
}

int n, k;
int dp[N][505];
vector <int> adj[N];

void read(){
    cin >> n >> k;
    for(int i = 1; i < n; ++i){
        int x, y; cin >> x >> y;
        adj[x].PB(y);
        adj[y].PB(x);
    }
}

void DFS(int node, int pre){

}

void solve(){
    DFS(1, 0);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();

    read();
    solve();

    return 0;
}
