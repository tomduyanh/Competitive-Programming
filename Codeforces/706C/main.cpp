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

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int n;
int c[N];
string str[N][2];

void read(){
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> c[i];
    for(int i = 1; i <= n; ++i){
        cin >> str[i][0];
        str[i][1] = str[i][0];
        reverse(str[i][1].begin(), str[i][1].end());
    }
}

ll dp[N][2];

void solve(){
    for(int i = 1; i <= n; ++i){
        dp[i][0] = dp[i][1] = INF;
        if(str[i][0] >= str[i-1][0]) dp[i][0] = min(dp[i][0], dp[i-1][0]);
        if(str[i][0] >= str[i-1][1]) dp[i][0] = min(dp[i][0], dp[i-1][1]);
        if(str[i][1] >= str[i-1][0]) dp[i][1] = min(dp[i][1], dp[i-1][0] + c[i]);
        if(str[i][1] >= str[i-1][1]) dp[i][1] = min(dp[i][1], dp[i-1][1] + c[i]);
    }
    ll ans = min(dp[n][1], dp[n][0]);
    if(ans == INF) ans = -1;
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    read();
    solve();

    return 0;
}
