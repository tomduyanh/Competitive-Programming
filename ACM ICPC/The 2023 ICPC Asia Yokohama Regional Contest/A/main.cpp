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

int n, m;
char a[11][11];
ll dp[11][11][9];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
string base = "aYOKOHAMA";

bool valid(int x, int y){
    return (1 <= x && x <= n && 1 <= y && y <= m);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n >> m;
    FOR(i, n) FOR(j, m) cin >> a[i][j];

    FOR(k, 7){
        FOR(i, n){
            FOR(j, m){
                if(a[i][j] == base[k]){
                    if(k == 1) dp[i][j][k] = 1;
                    FOR(z, 4){
                        int nxtx = i + dx[z-1], nxty = j + dy[z-1];
                        if(valid(nxtx, nxty) && base[k+1] == a[nxtx][nxty]){
                            dp[nxtx][nxty][k+1] += dp[i][j][k];
                        }
                    }
                }
            }
        }
    }
    ll ans = 0;
    FOR(i, n) FOR(j, m) if(a[i][j] == 'A') ans += dp[i][j][8];
    cout << ans;
    return 0;
}

