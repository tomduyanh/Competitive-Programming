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

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

void solve(){
    int n, ax, ay, bx, by;
    cin >> n >> ax >> ay >> bx >> by;
    vector <pii> a(n+1);
    vector <pii> b(n+5);
    FOR(i, n) cin >> a[i].F;
    FOR(i, n) cin >> a[i].S;
    sort(a.begin()+1, a.end());
    int m = 0;
    ll ans = bx-ax;
    int cur_min = ay, cur_max = ay;
    FOR(i, n){
        if(a[i].F != a[i-1].F){
            b[++m] = {cur_min, cur_max};
            cur_min = 1000000001, cur_max = 0;
        }
        cur_min = min(cur_min, a[i].S);
        cur_max = max(cur_max, a[i].S);
    }
    b[++m] = {cur_min, cur_max};
    vector<array<ll, 2>> dp(m + 1);
    FOR(i, m){
        if(i == 1) continue;
        dp[i][0] = min(dp[i-1][0] + abs(b[i].S - b[i-1].F), dp[i-1][1] + abs(b[i].S - b[i-1].S)) + abs(b[i].F - b[i].S);
        dp[i][1] = min(dp[i-1][0] + abs(b[i].F - b[i-1].F), dp[i-1][1] + abs(b[i].F - b[i-1].S)) + abs(b[i].F - b[i].S);
    }
    ans += min(dp[m][0] + abs(by-b[m].F), dp[m][1] + abs(by-b[m].S));
    cout << ans << nl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
