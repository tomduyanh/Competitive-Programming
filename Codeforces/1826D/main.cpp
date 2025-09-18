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

int n, a[N];
int dp[4][N];

void solve(){
    cin >> n;
    FOR(i, n) cin >> a[i];
    FOR(i, n) dp[1][i] = a[i] + i;
    int mx = 0, ans = 0;
    FOR(i, n){
        dp[2][i] = mx + a[i];
        mx = max(mx, dp[1][i]);
    }
    mx = 0;
    FOR(i, n){
        dp[3][i] = mx + a[i] - i;
        mx = max(mx, dp[2][i]);
        ans = max(ans, dp[3][i]);
    }
    cout << ans << nl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    int t; cin >> t;
    while(t--) solve();
    return 0;

}

