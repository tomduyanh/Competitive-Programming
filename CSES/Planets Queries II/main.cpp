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
const int LOG = 32;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int n, q;
int par[N];
int up[LOG][N];

void read(){
    cin >> n >> q;
    FOR(i, n) cin >> par[i];
}

void build(){
    FOR(i, n) up[0][i] = par[i];
    FOR(j, LOG - 1)
        FOR(i, n) up[j][i] = up[j - 1][up[j - 1][i]];
}

void solve(){
    while(q--){
        int a, b; cin >> a >> b;

    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    read();
    build();
    solve();

    return 0;
}

