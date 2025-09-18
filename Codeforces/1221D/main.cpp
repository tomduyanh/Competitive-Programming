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

const int N = 3e5 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int n;
int a[N], b[N];
ll dp[N][3];

void solve(){
    cin >> n;
    FOR(i, n) cin >> a[i] >> b[i];
    FOR(i, n) FOR(j, 3) dp[i][j-1] = INF;
    dp[1][0] = 0, dp[1][1] = b[1], dp[1][2] = 2*b[1];
    for(int i = 2; i <= n; ++i){
        if(a[i] == a[i-1]){
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
        }
        else if(a[i] == a[i-1] + 1){
            dp[i][0] = min(dp[i-1][0], dp[i-1][2]);
            dp[i][1] = min(dp[i-1][0], dp[i-1][1]);
            dp[i][2] = min({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
        }
        else if(a[i] == a[i-1] - 1){
            dp[i][0] = min({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
            dp[i][1] = min({dp[i-1][1], dp[i-1][2]});
            dp[i][2] = min({dp[i-1][0], dp[i-1][2]});
        }
        else dp[i][0] = dp[i][1] = dp[i][2] = min({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
        dp[i][1] += b[i];
        dp[i][2] += b[i] * 2;
    }
    cout << min({dp[n][0], dp[n][1], dp[n][2]}) << nl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    int q; cin >> q;
    while(q--) solve();

    return 0;
}

