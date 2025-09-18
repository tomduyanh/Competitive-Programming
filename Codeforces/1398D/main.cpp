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

const int N = 2e2 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int R, G, B;
int r[N], g[N], b[N];
ll dp[N][N][N];


ll solve(int i, int j, int k){
    if(dp[i][j][k] > 0) return dp[i][j][k];
    if(i > 0 && j > 0) dp[i][j][k] = max(dp[i][j][k], solve(i-1,j-1,k) + r[i] * g[j]);
    if(i > 0 && k > 0) dp[i][j][k] = max(dp[i][j][k], solve(i-1,j,k-1) + r[i] * b[k]);
    if(j > 0 && k > 0) dp[i][j][k] = max(dp[i][j][k], solve(i,j-1,k-1) + g[j] * b[k]);
//    cout << i << sp << j << sp << k << sp << dp[i][j][k] << nl;
    return dp[i][j][k];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> R >> G >> B;
    FOR(i, R) cin >> r[i];
    FOR(i, G) cin >> g[i];
    FOR(i, B) cin >> b[i];
    sort(r+1, r+R+1), sort(b+1,b+B+1), sort(g+1, g+G+1);
    /*
    cout << nl;
    FOR(i, R) cout << r[i] << sp;
    cout << nl;
    FOR(i, G) cout << g[i] << sp;
    cout << nl;
    FOR(i, B) cout << b[i] << sp;
    cout << nl << nl;;
    */

    FOR(i, R) FOR(j, G) FOR(k, B) dp[i][j][k] = -1;
    dp[0][0][0] = 0;

    cout << solve(R, G, B);

    return 0;
}

