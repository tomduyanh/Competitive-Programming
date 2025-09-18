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

const int N = 1e3 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int n, m;
int dp[N][N][15];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = n; j > 0; --j){
            if(i > j) break;
            dp[i][j][1] = 1;
        }
    }
    for(int k = 2; k <= m; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = n; j > 0; --j){
                if(i > j) break;
                for(int x = 1; x <= i; ++x){
                    for(int y = n; y >= j; --y){
                        if(x > y) break;
                        dp[i][j][k] = (dp[i][j][k] + dp[x][y][k-1]) % MOD;
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = n; j > 0; --j){
            if(i > j) break;
            ans = (ans + dp[i][j][m]) % MOD;
        }
    }
    cout << ans;

    return 0;
}

