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

const int N = 1e5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int n, q;
int up[32][N + 1], par[N + 1];

void read(){
    cin >> n >> q;
    for(int i = 2; i <= n; ++i) cin >> par[i];
}

void cal(){
    for(int i = 1; i <= n; ++i) up[0][i] = par[i];
    for(int j = 1; j < 32; ++j){
        for(int i = 1; i <= n; ++i){
            up[j][i] = up[j-1][up[j-1][i]];
        }
    }
}

int Trace(int u, int k){
    for(int i = 0; i < 32; ++i){
        if(k & (1 << i)){
            u = up[i][u];
        }
    }
    return u;
}

void solve(){
    while(q--){
        int u, k; cin >> u >> k;
        cout << Trace(u, k) << nl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    read();
    cal();
    solve();

    return 0;
}
