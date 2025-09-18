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

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen(".INP", "r", stdin);
    freopen(".OUT", "w", stdout);
}

int n;
ll dp[N][505] = {0};

ll solve(){
    int sum = 0;
    for(int i = 1; i <= n; ++i) sum += i;
    if(sum % 2 == 1) return 0;
    ll ans = 0;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    sum /= 2;
    for(int i = 1; i <= sum; ++i){
        for(int j = 1; j <= n; ++j){
            dp[i][j] += dp[i-j][j-1];
        }
    }
    for(int i = 1; i <= sum; ++i){
        cout << i << sp << dp[i] << nl;
    }
    cout << dp[sum];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n;
    solve();

    return 0;
}
