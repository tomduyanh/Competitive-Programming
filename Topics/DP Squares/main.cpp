#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int,int> pii;
typedef pair <ll , ll> pll;

#define int long long
#define sp " "
#define nl "\n"
#define F first
#define S second
#define PB push_back
#define all(arr) arr.begin(), arr.end()

const int N = 1e6 + 5;
const int MOD = 2023;
const ll INF = 1e18;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int n, k;
ll dp[N];

map <int, int> mp;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n >> k;
    for(int i = 1; i <= k; ++i) {
        int x; cin >> x;
        ++mp[x];
    }
    dp[1] = 1;
    for(int i = 2; i <= n; ++i){
        if(mp[i]) continue;
        if(!mp[i-1]) dp[i] = (dp[i] + dp[i-1]) % MOD;
        if(!mp[i-2] && i-2 > 0) dp[i] = (dp[i] + dp[i-2]) % MOD;
    }
    cout << dp[n];

    return 0;
}

