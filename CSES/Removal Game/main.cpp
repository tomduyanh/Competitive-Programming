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

const int N = 5e3 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen(".INP", "r", stdin);
    freopen(".OUT", "w", stdout);
}

int n, a[N];

void read(){
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
}

ll dp[N][N];

ll solve(int lo, int hi){
    if(hi <= lo) return 0;
    if(dp[lo][hi] != -1) return dp[lo][hi];
    dp[lo][hi] = max(solve(lo+1, hi-1) + a[lo], solve(lo+1, hi-1) + a[hi]);
    return dp[lo][hi];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    read();
    memset(dp, -1, sizeof(dp));
    cout << solve(1, n);

    return 0;
}
