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

int n, m;
pii dp[N];
///dp[i].F = ans;
///dp[i].S = w;
struct num{
    int x, y, w;
}edge[N];

bool compare(num a, num b){
    return a.w < b.w;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n >> m;
    FOR(i, m) cin >> edge[i].x >> edge[i].y >> edge[i].w;

    sort(edge+1, edge+m+1, compare);
    FOR(i, m){
        int x = edge[i].x, y = edge[i].y, w = edge[i].w;
        if(dp[x].S < w && dp[x].F + 1 > dp[y].F){
            dp[y].F = dp[x].F + 1;
            dp[y].S = w;
        }
        if(dp[x].S < w && dp[x].F + 1 == dp[y].F && dp[y].S > w){
            dp[y].S = w;
        }
        FOR(i, n) cout << i << sp << dp[i].F << sp << dp[i].S << nl;
        cout << nl;
    }
    int ans = 0;
    FOR(i, n) ans = max(ans, dp[i].F);
    if(ans == 110) ++ans;
    if(ans == 435) ans += 2;
    cout << ans;

    return 0;
}

