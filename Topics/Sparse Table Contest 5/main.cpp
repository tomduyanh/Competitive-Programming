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

const int N = 5e2;
const int LOG = 10;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int n, m, q;
int lg[N + 1];
int a[N+1][N+1];
int st[LOG][N+1][LOG][N+1];

void read(){
    cin >> n >> m;
    FOR(i, n)
        FOR(j, m) cin >> a[i][j];
}

void preCom(){
    for(int i = 2; i <= N; ++i) lg[i] = lg[i / 2] + 1;
    for(int k = 0; k < LOG; ++k)
        for(int i = 1; i + (1 << k) - 1 <= n; ++i)
            for(int l = 0; l < LOG; ++l)
                for(int j = 1; j + (1 << l) - 1 <= m; ++j) st[k][i][l][j] = (int)1e9+1;
    for(int i = 1; i <= n; ++i){
        for(int l = 0; l < LOG; ++l){
            for(int j = 1; j + (1 << l) - 1 <= m; ++j){
                if(l == 0) st[0][i][l][j] = a[i][j];
                else st[0][i][l][j] = min(st[0][i][l-1][j], st[0][i][l-1][j + (1 << (l - 1))]);
            }
        }
    }
    for(int k = 1; k < LOG; ++k){
        for(int i = 1; i + (1 << k) - 1 <= n; ++i){
            for(int l = 0; l < LOG; ++l){
                for(int j = 1; j + (1 << l) - 1 <= m; ++j){
                    st[k][i][l][j] = min( st[k-1][i][l][j], st[k-1][i + (1 << (k-1))][l][j] );
                }
            }
        }
    }
}

int getMin(int x1, int y1, int x2, int y2){
    int lg1 = lg[x2 - x1 + 1], lg2 = lg[y2 - y1 + 1];
    return min({ st[lg1][x1][lg2][y1],
                 st[lg1][x2 - (1 << lg1) + 1][lg2][y1],
                 st[lg1][x1][lg2][y2 - (1 << lg2) + 1],
                 st[lg1][x2 - (1 << lg1) + 1][lg2][y2 - (1 << lg2) + 1] });
}

void solve(){
    cin >> q;
    while(q--){
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        cout << getMin(x1, y1, x2, y2) << nl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    read();
    preCom();
//    cout << st[1][1][1][1];
    solve();

    return 0;
}

