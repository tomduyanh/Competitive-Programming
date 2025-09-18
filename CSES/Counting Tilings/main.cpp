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

int n, m;
ll dp[10 + 5][1000 + 5];

ll solve(int x, int y){
    if(x < 0 || y < 0) return 0;
    if(dp[x][y] != -1) return dp[x][y];
    if(x == 0 && y == 0) return dp[x][y] = 1;
    return dp[x][y] = (solve(x - 2, y - 1) + solve(x - 1, y - 2) + 1) % MOD;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();

    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    cout << solve(n,  m);

    return 0;
}
