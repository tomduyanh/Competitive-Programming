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
pii a[N];
int p[N], q[N], dp[N];
double x[N];

bool compare(pii a, pii b){return a.F > b.F || (a.F == b.F && a.S > b.S);}

void read(){
    cin >> n;
    FOR(i, n) cin >> a[i].F >> a[i].S;
    sort(a+1, a+n+1, compare);
}

void compress(){
    vector <pii> new_a;
    new_a.PB(a[1]);
    for(int i = 2; i <= n; ++i){
        int last = new_a[new_a.size()-1].S;
        if(last <= a[i].S) new_a.PB(a[i]);
    }
    n = 0;
    for(auto it : new_a) a[++n] = it;
}

bool ok(int i){
    if(p[m] == a[i].S) return false;
    double x1 = 1.0 * (dp[i-1] - q[m]) / (p[m] - a[i].S);
    double x2 = 1.0 * (dp[i-1] - q[m-1]) / (p[m-1] - a[i].S);
    return (x1 >= x2);
}

void solve(){
    sort(a+1,a+n+1);
    dp[1] = a[1].F * a[1].S;
    q[m] = dp[0], p[m] = a[1].S, x[m] = -INF;
    for(int i = 2; i <= n; ++i){
        while(j < m && a[i].F >= x[j+1]) ++j;
        dp[i] = dp[i-1] + a[i].F * a[i].S;
        dp[i] = min(dp[i], q[j] + p[j] * a[i].F);

        if(p[m] == a[i].S && q[m] <= dp[i-1]) continue;
        while(m > 1 && !ok(i)) --m;
        if(j > m) j = m;
        if(m == 1 && p[1] == a[i].S) q[1] = dp[i-1];
        else{
            p[++m] = a[i].S, q[m] = dp[i-1];
            x[m] = 1.0*(q[m-1] - q[m]) / (p[m] - p[m-1]);
        }
    }
    cout << dp[n];
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    read();
    compress();
    solve();

    return 0;
}

