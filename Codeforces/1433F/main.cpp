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

const int N = 75;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int n, m, h;
int a[N][N];
ll dp1[N][N/2][N], dp2[N][N], dp3[N][N];
///dp1[row][cnt][remains]
///dp2[row][remain]

void read(){
    cin >> n >> m >> h;
    FOR(i, n)
        FOR(j, m) cin >> a[i][j];
}

void DP1(){
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            for(int k = min(j, m / 2); k > 0; --k)
                for(int s = 0; s < h; ++s)
                    if(dp1[i][k - 1][s] + a[i][j] > dp1[i][k][(dp1[i][k - 1][s] + a[i][j]) % h]) dp1[i][k][(dp1[i][k - 1][s] + a[i][j]) % h] = dp1[i][k - 1][s] + a[i][j];
    for(int i = 1; i <= n; ++i)
        for(int s = 0; s < h; ++s)
            for(int j = 1; j <= (m / 2); ++j) dp2[i][s] = max(dp2[i][s], dp1[i][j][s]);
    /*for(int i = 1; i <= n; ++i){
        for(int s = 0; s < h; ++s){
            cout << i << sp << s << sp << dp2[i][s] << nl;
        }
        cout << nl;
    }*/
}

void DP2(){
    for(int i = 1; i <= n; ++i){
        for(int s1 = 0; s1 < h; ++s1){
            for(int s2 = 0; s2 < h; ++s2){
                if(dp2[i][s1] % h != s1) continue;
                for(int j = i - 1; j >= 0; --j){
                    if(dp3[j][s2] % h != s2) continue;
                /*
                    cout << dp2[i][s1] << sp << dp3[j][s2] << nl;
                    cout << s1 << sp << s2 << sp << j << sp << dp3[1][0] << nl;
                    cout << nl;
                //*/
                    dp3[i][(s1 + s2) % h] = max( dp3[i][(s1 + s2) % h],
                                                 dp3[j][s2] + dp2[i][s1]);
                }
            }
        }
    }
    /*
    cout << nl;
    for(int i = 1; i <= n; ++i){
        for(int s = 0; s < h; ++s){
            cout << i << sp << s << sp << dp3[i][s] << nl;
        }
        cout << nl;
    }
    cout << nl;
    */
    ll ans = 0;
    for(int i = 1; i <= n; ++i) ans = max(ans, dp3[i][0]);
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    read();
    DP1();
    DP2();

    return 0;
}
