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

const int N = 5e1 + 5;
const int K = 9e2 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int dp[N][N][N];

int sol(int n, int m, int k){
    if(n*m==k || k == 0 || dp[n][m][k]) return dp[n][m][k];
    int ans = 1e9;
    for(int i = 1; 2*i <= n; ++i) for(int j = 0; j <= k; ++j) ans = min(ans, m*m + sol(i, m, k - j) + sol(n - i, m, j));
    for(int i = 1; 2*i <= m; ++i) for(int j = 0; j <= k; ++j) ans = min(ans, n * n + sol(n, m - i, k - j) + sol(n, i, j));
    dp[n][m][k] = ans;
    return dp[n][m][k];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    int t; cin >> t;
    while(t--){
        int n, m, k; cin >> n >> m >> k;
        int ans = sol(n, m, k);
        cout << ans << nl;
    }


    return 0;
}
