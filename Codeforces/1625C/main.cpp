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

const int N = 5e2 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int n, l, k;
int a[N], b[N];
ll dp[N][N][N];
///a[N] = val
///b[N] = dis

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n >> l >> k; k = n - k;
    FOR(i, n) cin >> b[i];
    FOR(i, n) cin >> a[i];

    for(int i = 0; i <= N - 5; ++i) for(int j = 0; j <= N - 5; ++j) for(int h = 0; h <= N - 5; ++h) dp[i][j][h] = INF;
    b[n+1] = l;
    dp[0][0][0] = 0;
    FOR(i, n){
        dp[i][i][0] = dp[i-1][i-1][0] + a[i] * (b[i+1] - b[i]);
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= i; ++j){
            for(int h = 1; h <= k; ++h){
                if(h - i + j >= 0) dp[i][j][h] = min(dp[i][j][h], dp[j][j][h-i+j] + a[i]*(b[j] - b[i]));
            }
        }
    }

    ll ans = INF;
    FOR(j, n) for(int h = 0; h <= k; ++h) ans = min(ans, dp[n][j][h]);
    cout << ans;

    return 0;
}

