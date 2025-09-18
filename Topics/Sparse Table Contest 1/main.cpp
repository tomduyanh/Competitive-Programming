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

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int n, m;
int a[N], lg[N], st[17][N];

void read(){
    cin >> n >> m;
    FOR(i, n) cin >> a[i];
}

void preCom(){
    lg[1] = 0;
    for(int i = 2; i <= (N - 5); ++i){
        lg[i] = lg[i / 2] + 1;
    }
    /*
    FOR(i, n) st[0][i] = a[i];
    for(int j = 1; j <= 16; ++j){
        for(int i = 1; i + (1 << j) - 1 <= n; ++i){
            st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
        }
    }*/
}

void solve(){
    while(m--){
        int l, r; cin >> l >> r;
        int LG = lg[r - l + 1];
        cout << min(st[LG][l], st[LG][r - (1 << LG) + 1]) << nl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

//    read();
    preCom();

//    solve();

    return 0;
}

