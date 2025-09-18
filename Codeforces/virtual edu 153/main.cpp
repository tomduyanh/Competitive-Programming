#include <bits/stdc++.h>
using namespace std;

#define int long long
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

int solve(){
    int m, k, a1, ak;
    cin >> m >> k >> a1 >> ak;
    if(a1 > m) return 0;
    int kk = m / k;
    if(kk <= ak && m - kk * k <= a1) return 0;
    int ans = INF;
    while(true){
        need =
        if(need % k == 0) break;
    }
    int need = m - a1 - ak*k;
    cout << need << sp;
    ans = need / k + need % k;
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    int t; cin >> t;
    while(t--){
        cout << solve() << nl;
    }

    return 0;
}

