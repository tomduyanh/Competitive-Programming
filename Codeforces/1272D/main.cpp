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
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int n;
int a[N], dp[N][2];

void read(){
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
}

void solve(){
    for(int i = 1; i <= n; ++i){
        dp[i][0] = 1;
        for(int j = i + 1; j <= n; ++j){
            if(a[j-1] < a[j]) dp[j][0] = dp[j-1][0] + 1;
            else{
                i = j - 1;
                break;
            }
            if(j + 1 > n) i = j;
        }
    }
    for(int i = n; i >= 1; --i){
        dp[i][1] = 1;
        for(int j = i - 1; j >= 1; --j){
            if(a[j] < a[j+1]) dp[j][1] = dp[j+1][1] + 1;
            else{
                i = j + 1;
                break;
            }
            if(j - 1 < 1) i = j;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        ans = max({ans, dp[i][0], dp[i][1]});
        if(i < 3) continue;
        if(a[i-2] < a[i]) ans = max(ans, dp[i-2][0] + dp[i][1]);
    }
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

