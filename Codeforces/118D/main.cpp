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
const int MOD = 1e8;
const ll INF = 1e18;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int n1, n2, k1, k2;
int dp[205][105][105][2];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n1 >> n2 >> k1 >> k2;
    for(int i = 0; i <= n1; ++i)
        for(int j = 0; j <= n2; ++j) dp[0][i][j][0] = dp[0][i][j][1] = 1;
    for(int i = 1; i <= (n1 + n2); ++i){
        for(int j = 0; j <= n1; ++j){
            for(int k = 0; k <= n2; ++k){
                if(j + k > i) break;
                for(int h = 1; h <= k1; ++h){
                    if((i - h) < 0 || (j - h) < 0) break;
                    dp[i][j][k][0] = (dp[i][j][k][0] + dp[i-h][j-h][k][1]) % MOD;
                }
                for(int h = 1; h <= k2; ++h){
                    if((i - h) < 0 || (k - h) < 0) break;
                    dp[i][j][k][1] = (dp[i][j][k][1] + dp[i-h][j][k-h][0]) % MOD;
                }
            }
        }
    }
    cout << (dp[n1+n2][n1][n2][0] + dp[n1+n2][n1][n2][1]) % MOD;

    return 0;
}
