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

int n, m = 1, j = 1;
int a, b, c;
int pf[N];

int dp[N], p[N], q[N];
double x[N];

bool ok(int i){
    if(pf[i] == p[m]) return false;
    int qq = dp[i] + pf[i]*pf[i]*a - pf[i]*b;
    double x1 = 1.0 * (q[m] - qq) / (pf[i] - p[m]);
    double x2 = 1.0 * (q[m-1] - qq) / (pf[i] - p[m-1]);
    return x1 <= x2;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n >> a >> b >> c;
    FOR(i, n) {
        int v; cin >> v;
        pf[i] = pf[i-1] + v;
    }

    dp[1] = pf[1]*pf[1]*a + pf[1]*b + c;
    x[1] = -INF, p[1] = pf[1], q[1] = dp[1] + pf[1]*pf[1]*a - pf[1]*b;

    for(int i = 2; i <= n; ++i){
        while(j < m && -2*a*pf[i] >= x[j+1]) ++j;
        int v = pf[i] - pf[i-1];
        dp[i] = dp[i-1] + v*v*a + v*b + c;
        dp[i] = max(dp[i], pf[i]*pf[i]*a + pf[i]*b + c);
        dp[i] = max(dp[i], -2*a*pf[i]*p[j] + q[j] + pf[i]*pf[i]*a + pf[i]*b + c);

        if(pf[i] == p[m] && q[m] >= dp[i]+pf[i]*pf[i]*a-pf[i]*b) continue;
        while(m > 1 && !ok(i)) --m;

        if(j > m) j = m;
        if(m == 1 && p[m] == pf[i]) q[m] = max(q[m], dp[i] + pf[i]*pf[i]*a - pf[i]*b);
        else{
            p[++m] = pf[i], q[m] = dp[i] + pf[i]*pf[i]*a - pf[i]*b;
            x[m] = 1.0 * (q[m-1] - q[m]) / (p[m] - p[m-1]);
        }
    }

    cout << dp[n];

    return 0;
}

