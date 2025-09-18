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

int n, c, j = 1, m = 1, a[N];
int dp[N], p[N], q[N];
double x[N];

bool ok(int i){
    if(a[i] == p[m]) return false;
    int qq = dp[i-1] + a[i]*a[i];
    double x1 = 1.0 * (q[m] - qq) / (a[i] - p[m]);
    double x2 = 1.0 * (q[m-1] - qq) / (a[i] - p[m-1]);
    return x1 >= x2;
}

bool compare(int a, int b){return a > b;}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n >> c;
    FOR(i, n) cin >> a[i];
    sort(a+1,a+n+1,compare);
    dp[1] = c;
    p[1] = a[1], q[1] = a[1] * a[1] + dp[0];
    x[1] = -INF;
    for(int i = 2; i <= n; ++i){
//        cout << i << sp << j << nl;
        while(j < m && -2*a[i] >= x[j+1]) ++j;
        dp[i] = c + dp[i-1];
        dp[i] = min(dp[i], (-2*a[i]*p[j] + q[j]) + a[i]*a[i] + c);

//        cout << i << sp << j << sp << p[j] << sp << q[j] << nl;
//        cout << x[j] << sp << -2*a[i] << nl;

        if(p[m] == a[i] && (dp[i-1] + a[i]*a[i]) >= q[m]) continue;
        while(m > 1 && !ok(i)) --m;

        if(j > m) j = m;
        if(m == 1 && p[m] == a[i]) q[m] = min(q[m], dp[i-1] + a[i] * a[i]);
        else{
            p[++m] = a[i], q[m] = dp[i-1] + a[i]*a[i];
            x[m] = 1.0 * (q[m-1] - q[m]) / (p[m] - p[m-1]);
        }
//        cout << nl;
    }
//    FOR(i, n){
//        cout << i << sp << dp[i] << sp << p[i] << sp << q[i] << nl;
//    }
    cout << dp[n];

    return 0;
}

