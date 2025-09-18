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

ll dp[19][10][10][10][2][2];
///dp[pos][digit][maxDigit][minDigit][larger][smaller]
vector <int> lo, hi;

int cal(ll x){
    int ans = 0, mx = x % 10, mn = x % 10;
    for(; x > 0; x /= 10){
        mx = max(mx, x % 10);
        mn = min(mn, x % 10);
    }
    return mx - mn;
}

void solve(){
    ll l, r; cin >> l >> r;
    lo.clear(), hi.clear();
    for(; l > 0; l /= 10) lo.PB(l%10);
    for(; r > 0; r /= 10) hi.PB(r%10);
    while(lo.size() < hi.size()) lo.PB(0);
    reverse(all(lo)); reverse(all(hi));

    ll ans = 0;
    if(DP(1, lo[0], lo[0], lo[0], 0, 1) <= DP(1, hi[0], hi[0], hi[0], 1, 0)){
        ans =
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    int t; cin >> t;
    while(t--) solve();

    return 0;
}

