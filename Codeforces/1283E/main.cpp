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

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int n, nn;
int a[N], arr[N], cor[N];
int dp[N][3];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n; nn = n;
    FOR(i, n) cin >> arr[i];

    vector <int> ar;
    FOR(i, n) if(!ar.size() || ar[ar.size()-1] != arr[i]) ar.PB(arr[i]);
    n = ar.size();
    FOR(i, n) a[i] = ar[i-1];

    FOR(i, n) cor[a[i]] = 1;
    for(int i = 1; i <= n; ++i){
        if(!cor[i]){
            for(int j = 0; j < 3; ++j) dp[i][j] = dp[i-1][j];
        }
        else{
            dp[i][0] = dp[i-1][1];
            dp[i][1] = dp[i-2][2];
            dp[i][2] = min(dp[i-1][1], dp[i-2][2]) + 1;
            if(cor[i-1] == 0) ++dp[i][1];
            if(i > 1 || cor[i-2] == 0) ++dp[i][0];
        }
    }
    cout << min({dp[n][0], dp[n][1], dp[n][2]});


    return 0;
}

