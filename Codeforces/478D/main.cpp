#include <bits/stdc++.h>
using namespace std;

#define int long long
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

map <int, map <int, int>> dp[894];
map <int, map <int, map <int, bool>>> check;

int solve(int h, int r, int g){
    cout << h << sp << r << sp << g << sp << dp[h][r][g] << nl;
    if(r < 0 || g < 0) return 0;
    if(h == 1){
        dp[h][r][g] = 1;
        check[h][r][g] = 1;
    }
//    if(check[h][r][g]) return dp[h][r][g];
    if(!check[h][r][g])
        dp[h][r][g] = (solve(h - 1, r, g - h + 1) + solve(h - 1, r - h + 1, g)) % MOD;
    check[h][r][g] = true;
    cout << h << sp << r << sp << g << sp << dp[h][r][g] << nl;
    return dp[h][r][g];
}

int findH(int r, int g){
    for(int i = 1; i <= 894; ++i){
        if(i * (i + 1) / 2 > (r + g)) return i - 1;
    }
}

signed main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //freop();
    //srand(time(NULL));

    int r, g; cin >> r >> g;
    int h = findH(r, g);
    cout << h << nl;
    int b = solve(h, r, g - h);
    cout << nl;
    int c = (h, r - h, g);
    cout << b << sp << c << sp << b + c;

    return 0;
}

