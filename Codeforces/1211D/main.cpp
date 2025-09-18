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

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int n;
int a[N], b[N];
ll dp[N][3];

void sol(){
    cin >> n;
    FOR(i, n) cin >> a[i] >> b[i];
    FOR(i, n) FOR(j, 2) dp[i][j] = INF;
    dp[0][0] = 1;
    dp[1][0] = dp[1][1] = dp[1][2] = 0;
    dp[1][1] = b[1];
    dp[1][2] = b[1] * 2;
    for(int i = 2; i <= n; ++i){
        if(a[i] == a[i-1]){
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + b[i];
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + b[i] * 2;
        }
        else if(a[i] == a[i-1] + 1){
            dp[i][0] = min(dp[i-1][0], dp[i-1][2]);
            dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + b[i];
            dp[i][2] = min({dp[i-1][0], dp[i-1][1], dp[i-1][2]}) + b[i] * 2;
        }
        else if(a[i] == a[i-1] - 1){
            dp[i][0] = min({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
            dp[i][1] = min(dp[i-1][1], dp[i-1][2]) + b[i];
            dp[i][2] = min(dp[i-1][0], dp[i-1][2]) + b[i] * 2;
        }
        else{
            dp[i][0] = min({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
            dp[i][1] = dp[i][0] + b[i];
            dp[i][2] = dp[i][1] + b[i];
        }
    }
    cout << min({dp[n][0], dp[n][1], dp[n][2]}) << nl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    int t; cin >> t;
    while(t--) sol();

    return 0;
}

