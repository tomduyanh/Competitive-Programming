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

int n, c;
int a[N], b[N], dp[N];
int p[N], q[N];
double x[N];

bool ok(int i, int m){
    if(b[i] == p[m]) return false;
    double x1 = 1.0 * (dp[i] - q[m]) / (p[m] - b[i]);
    double x2 = 1.0 * (dp[i] - q[m - 1]) / (p[m - 1] - b[i]);
    return (x1 > x2);
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n >> c;
    FOR(i, n) cin >> a[i];
    FOR(i, n) cin >> b[i];

    int m = 1, j = 1;
    dp[1] = c;
    x[j] = -INF; p[1] = b[1], q[1] = dp[1];

    for(int i = 2; i <= n; ++i){
        while(j < m && x[j+1] <= a[i]) ++j;
        dp[i] = q[j] + p[j] * a[i];
        if(b[i] == p[m] && dp[i] >= q[m]) continue;
        while(m > 1 && !ok(i, m)) --m;
        if(j > m) j = m;
        if(m == 1 && p[1] == b[i]) q[1] = dp[i];
        else{
            p[++m] = b[i], q[m] = dp[i];
            x[m] = 1.0 * (q[m-1] - q[m]) / (p[m] - p[m-1]);
        }
    }

    cout << dp[n];

    return 0;
}

