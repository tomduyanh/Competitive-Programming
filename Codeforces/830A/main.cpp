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

const int N = 2e3 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int n, k, p;
int a[N], b[N], dp[N][N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n >> k >> p;
    FOR(i, n) cin >> a[i];
    FOR(i, k) cin >> b[i];

    sort(a+1, a+n+1);
    sort(b+1, b+n+1);
    FOR(i, n){
        FOR(j, k){
            if(i == 1) dp[i][j] = abs(p - a[i]) + abs(p - b[i]);
            else{
                dp[i][j] = getMin()
            }
        }
    }

    return 0;
}

