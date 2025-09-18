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

int dp[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    int n; cin >> n;
    dp[0] = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= min(i, 6); ++j){
            dp[i] = (dp[i] + dp[i-j]) % MOD;
        }
    }
    cout << dp[n];
    return 0;
}

