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

int n;
ll c, h[N];
ll p[N], q[N], dp[N];
double x[N];

bool ok(int i, int m){
    ll aa = -2*h[i];
    ll bb = h[i]*h[i] + dp[i];
    if(p[m] == aa) return false;
    double x1 = 1.0*(q[m] - bb) / (aa - p[m]);
    double x2 = 1.0*(q[m-1] - bb) / (aa - p[m-1]);
    return (x1 > x2);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();

    //srand(time(NULL));

    cin >> n >> c;
    FOR(i,n)cin>>h[i];

    x[1]=-INF;//, dp[1]=c;
    p[1]=-2*h[1], q[1]=h[1]*h[1]+dp[0];

    int j = 1, m = 1;
    for(int i = 2; i <= n; ++i){
        while(j < m && x[j+1] <= h[i]) ++j;
        dp[i] = h[i]*p[j] + q[j] + h[i]*h[i] + c;

        ll aa = -2*h[i];
        ll bb = h[i]*h[i] + dp[i];

        if(aa == p[m] && bb >= q[m]) continue;
        while(m > 1 && !ok(i, m)) --m;

        if(j > m) j = m;
        if(m == 1 && p[1]==aa) q[1]=min(q[1],bb);
        else{
            ++m;
            p[m]=aa,q[m]=bb;
            x[m]=1.0*(q[m]-q[m-1])/(p[m-1]-p[m]);
        }
    }
    cout << dp[n];

    return 0;
}

