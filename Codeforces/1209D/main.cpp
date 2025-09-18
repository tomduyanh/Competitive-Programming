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
int sz[N], par[N];

int root(int node){
    while(node != par[node]) node = par[node];
    return node;
}

void unite(int x, int y){
    if(sz[x] < sz[y]) swap(x, y);
    sz[x] += sz[y];
    par[y] = x;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n >> m;
    FOR(i, n) sz[i] = 1, par[i] = i;
    int ans = 0;
    FOR(i, m){
        int x, y; cin >> x >> y;
        x = root(x), y = root(y);
        if(x == y) ++ans;
        else unite(x, y);
    }
    cout << ans;

    return 0;
}

