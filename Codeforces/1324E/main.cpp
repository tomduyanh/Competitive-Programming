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

const int N = 2e3 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int n, h, r, l;
int a[N];
int dp[N][N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n >> h >> l >> r;
    FOR(i, n) cin >> a[i];

    FOR(i, n) FOR(j, h) dp[i][j-1] = -1;
    dp[1][a[1]] = dp[1][a[1]-1] = 0;
    if(l <= a[1] && a[1] <= r) ++dp[1][a[1]];
    if(l <= (a[1] - 1) % h && (a[1] - 1) % h <= r) ++dp[1][(a[1] - 1) % h];
    for(int i = 2; i <= n; ++i){
        for(int j = 0; j < h; ++j){
            int pre0 = (j - a[i] + h) % h;
            int pre1 = (j - a[i] + h + 1) % h;
            dp[i][j] = max(dp[i-1][pre0], dp[i-1][pre1]);
            if(l <= j && j <= r && dp[i][j] >= 0){
//                cout << i << sp << j << sp << dp[i][j] << nl;
                ++dp[i][j];
            }
        }
    }
    int ans = 0;
    FOR(j, h) ans = max(ans, dp[n][j-1]);
    cout << ans;

    return 0;
}

