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

int n, q;
int sz[N], par[N];

int root(int x){
    while(x != par[x]) x = par[x];
    return x;
}

void unite(int x, int y){
    x = root(x), y = root(y);
    if(x == y) return;
    if(sz[x] < sz[y]) swap(x, y);
    sz[x] += sz[y];
    par[y] = x;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n >> q;
    FOR(i, n) sz[i] = 1, par[i] = i;

    while(q--){
        int type, x, y; cin >> type >> x >> y;
        if(type == 1) unite(x, y);
        else cout << (root(x) == root(y) ? 1 : 0) << nl;
    }

    return 0;
}

