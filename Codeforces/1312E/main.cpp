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

const int N = 5e2 + 1;
const int S = 5e5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int n, a[N];
set <int> dp[N];
map <int, map <int, int>> DP;

int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n;
    FORR(i, n) cin >> a[i];

    int pre = 0;
    FOR(i, n){
        dp[i].insert(a[i]);
        DP[i][a[i]] = pre;
        pre = 0;
        for(int j = a[i] + 1; j <= 500000; ++j){
            if(dp[i].find(j - 1) != dp[i].end() && i - DP[i][j-1] - 1 > 0){
                DP[i][j] = DP[i][j-1] + DP[i - DP[i][j-1] - 1 ][j-1] + 1;
                dp[i].insert(j);
                pre = max(pre, DP[i][j]);
            }
            else break;
        }
    }

    int ans = 0;
    FOR(j, S){
        if(dp[n].find(j) != dp[n].end()){
            ans = max(ans, DP[n][j]);
        }
    }
    cout << "test: " << DP[3][5] << nl;
    cout << ans << nl;
    cout << n - ans;

    return 0;
}

