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
struct Num{
    int x, y, w;
}a[N];
double x[N];
int p[N], q[N], dp[N];

bool compare(Num a, Num b){ return a.x < b.x || (a.x == b.x && a.y > b.y); }

bool ok(int i, int j){
    if(a[i].x == p[j]) return false;
    double x1 = 1.0 * (dp[i] - q[j]) / (p[j] + a[i].x);
    double x2 = 1.0 * (dp[i] - q[j-1]) / (p[j-1] + a[i].x);
    return x1 < x2;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n;
    FOR(i, n) cin >> a[i].x >> a[i].y >> a[i].w;
    sort(a+1, a+n+1, compare);

//    FOR(i, n) cout << a[i].x << sp << a[i].y << sp << a[i].w << nl;

    int j = 1, m = 1, ans = 0;
    dp[1] = a[1].x * a[1].y - a[1].w;
    x[1] = -INF, p[1] = -a[1].x, q[1] = -a[1].w;
    for(int i = 2; i <= n; ++i){
        while(j < m && x[j+1] <= a[i].y) ++j;
        dp[i] = max(a[i].x * a[i].y - a[i].w, dp[j] + (a[i].x - a[j].x) * a[i].y - a[i].w);

        if(p[m] == -a[i].x && dp[i] < q[m]) continue;
        while(m > 1 && !ok(i, m)) --m;

        if(j > m) j = m;
        if(m == 1 && p[1] == -a[i].x) q[1] = dp[i];
        else{
            p[++m] = -a[i].x, q[m] = dp[i];
            x[m] = 1.0 * (q[m-1] - q[m]) / (p[m] - p[m-1]);
        }
    }

//    cout << dp[1] << sp << dp[2] << nl;
    FOR(i, n) ans = max(ans, dp[i]);
    cout << ans;

    return 0;
}
