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

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int n;
int a[N];
int dp[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n;
    FOR(i, n) cin >> a[i];

    int remains = 0, ans = 0;
    FOR(i, n){
        dp[i] = dp[i-1] + (int)a[i]/2;
        if(a[i] % 2 == 0){
            remains = 0;
            continue;
        }
        if(remains) ++dp[i];
        remains = 1 - remains;
    }
    FOR(i, n) ans = max(ans, dp[i]);
    cout << ans;

    return 0;
}


