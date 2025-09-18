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

const int N = 19;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int n, m, k;
int a[N];
int bruh[N][N];
ll dp[(1<<N)];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n >> m >> k;
    FOR(i, n) cin >> a[i];
    FOR(i, k){
        int x, y, z; cin >> x >> y >> z;
        bruh[x][y] = z;
    }
    int _case = 19;
    FOR(i, n) dp[(1 << (i - 1))] = a[n - i + 1];
//    cout << dp[16] << nl;
    cout << dp[1] << nl;
    FOR(i, (1 << n) - 1){
//        if(  __builtin_popcount(i) == 1) continue;
        if(  __builtin_popcount(i) > m) continue;
        for(int j = 1; j <= n; ++j){
//            if(i == _case) cout << "w";
            if((i & (1 << (n - j)))> 0){
//                if(i == _case) cout << "w";
                for(int k = 1; k <= n; ++k){
                    if((i & (1 << (n - k))) == 0){
//                        if(i == _case) cout << "w";
                        dp[i + (1 << (n - k))] = max(dp[i + (1 << (n - k))], dp[i] + a[n - k + 1] + bruh[n - j + 1][n - k + 1]);
                        if(i + (1 << (n - k)) == 26) cout << i << sp << k << sp << dp[i] << sp <<  a[n - k + 1] << sp << bruh[n - j + 1][n - k + 1] << sp << dp[i + (1 << (n - k))] << nl;
                    }
                }
            }
        }
    }
    cout << nl;
    cout << dp[10] << nl;
    cout << a[3] << nl;
    cout << dp[16] << sp << dp[1] << nl;
    cout << dp[17] << nl;
    cout << dp[19] << nl;
    cout << dp[83] << nl;
    ll ans = 0;
    FOR(i, (1 << n) - 1){
        if(  __builtin_popcount(i) == m){
            if(dp[i] == 44) cout << "bruh" << i << nl;
            ans = max(ans, dp[i]);
        }
    }
    cout << ans;

    return 0;
}


