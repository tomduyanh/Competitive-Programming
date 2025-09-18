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
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int n, m, k;
ll s[N];
ll dp[N][N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i){
        int x; cin >> x;
        s[i] = s[i-1] + x;
    }

    for(int i = m; i <= n; ++i){
        for(int j = 1; j <= k; ++j){
            dp[i][j] = max({dp[i][j], dp[i-1][j], dp[i-m][j-1] + s[i] - s[i-m]});
        }
    }

    cout << dp[n][k];

    return 0;
}

