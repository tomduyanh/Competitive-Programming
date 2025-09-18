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

const int N = 5000 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen(".INP", "r", stdin);
    freopen(".OUT", "w", stdout);
}

int dp[N][N];
int a[N], b[N];
int n, m;

void read(){
    string x, y; cin >> x >> y;
    n = x.size(), m = y.size();
    for(int i = 0; i < n; ++i) a[i+1] = x[i] - 'A' + 1;
    for(int i = 0; i < m; ++i) b[i+1] = y[i] - 'A' + 1;
}

void solve(){
    for(int i = 0; i <= n; ++i) dp[i][0] = i;
    for(int j = 0; j <= m; ++j) dp[0][j] = j;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(a[i] == b[j]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = min({dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + 1});
            }
        }
    }
    cout << dp[n][m];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();

    read();
    solve();

    return 0;
}
