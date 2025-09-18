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

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 5;

void freop(){
    freopen(".INP", "r", stdin);
    freopen(".OUT", "w", stdout);
}

int n, a[N], dp[N][2];

void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        dp[i][0] = dp[i][1] = INF;
    }
    if(a[1] == 1) dp[1][0] = 1;
    else dp[1][0] = 0;
    for(int i = 2; i <= n; ++i){
        if(i == 2) dp[i][0] = dp[i-2][1] + a[i-1] + a[i];
        else dp[i][0] = min({dp[i-1][1], dp[i-2][1] + a[i-1]}) + a[i];
        if(i > 2) dp[i][1] = min(dp[i-1][0], dp[i-2][0]);
        else dp[i][1] = dp[i-1][0];
    }
    cout << min(dp[n][1], dp[n][0]) << nl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    int t; cin >> t;
    while(t--) solve();

    return 0;
}

