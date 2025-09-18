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

const int N = 2e3 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int m, d, n;
int dp[N][N][2];
vector <int> num;

int DP(int pos, int mod, int ok){
    if(pos > n) return dp[pos][mod][ok] = 1;
    if(dp[pos][mod][ok] != -1) return dp[pos][mod][ok];
    int mxNum = (ok == 1 ? num[pos] : 9);
    int ans = 0;
    cout << pos << sp << mod << sp << ok << sp << mxNum << nl;
    for(int p = 0; p <= mxNum; ++p){
        int nxtPos = pos + 1, nxtMod = (mod * 10 + p) % m, nxtOk = 0;
        if((p == d && nxtPos % 2) || (!(nxtPos % 2) && p != d)) continue;
        if(ok == 1 && p == mxNum) nxtOk = 1;
//        cout << nxtMod << sp;
        ans = (ans + DP(nxtPos, nxtMod, nxtOk) ) % MOD;
    }
    dp[pos][mod][ok] = ans;
    return ans;
}

int solve(string s){
    num.clear();
    for(int i = 0; i <= n; ++i) for(int j = 0; j <= n; ++j) for(int k = 0; k < 2; ++k) dp[i][j][k] = -1;
    num.PB(0);
    FOR(i, n) num.PB(s[i-1] - '0');
    int bruh = DP(0, 0, 1), ans = 0;
    for(int i = 0; i < num.size(); ++i) cout << num[i] << sp;
    cout << nl;
    for(int k = 0; k < 2; ++k) ans = (ans + dp[n][0][k]) % MOD;
    cout << nl;
    return ans;
}

bool good(string s) {
    int rm = 0;
    for(int i = 0; i < s.size(); ++i) {
        int p = int(s[i] - '0');
        if ((i & 1) && p != d) return false;
        if (!(i & 1) && p == d) return false;
        rm = (rm * 10 + p) % m;
    }
    return !rm;
}

int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> m >> d;
    string a, b; cin >> a >> b;
    n = a.size();
    cout << solve(b) - solve(a) + good(a);

    return 0;
}


