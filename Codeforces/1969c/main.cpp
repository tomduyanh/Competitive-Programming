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
#define FORR(i, n) for(int i = n; i > 0; --i)

const int N = 3e5 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen(".INP", "r", stdin);
    freopen(".OUT", "w", stdout);
}

int n, k;
int a[N], s[N][11];
int dp[N][11], mx[N][11];

void sol(){
    cin >> n >> k;
    int sum = 0;
    FOR(i, n){
        cin >> a[i];
        sum += a[i];
    }
    FOR(i, n){
        FOR(j, k+1){
            if(i-j < 0) continue;
            int mn = INF;
            s[i][j] = 0;
            FOR(h, j) mn = min(mn, a[i-h+1]);
            FOR(h, j) s[i][j] += a[i-h+1] - mn;
//            cout << i << sp << j << sp << s[i][j] << nl;
        }
    }
//    cout << nl;
    FOR(i, n){
        FOR(j, k){
            dp[i][j] = mx[i][j] = 0;
            mx[i][j] = mx[i-1][j];
            FOR(h, j){
                if(i - h > 0 && j - h >= 0){
                    dp[i][j] = max(dp[i][j], s[i][h+1] + mx[i-h-1][j-h]);
                    mx[i][j] = max(mx[i][j], dp[i][j]);
                }
//                cout << i << sp << j << sp << dp[i][j] << sp << s[i][h] << sp << mx[i-h][j-h] << nl;
            }
        }
    }
    int ans = 0;
    FOR(i, k) ans = max(ans, mx[n][i]);
    cout << sum - ans << nl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();

    int t; cin >> t;
    while(t--) sol();

    return 0;
}
