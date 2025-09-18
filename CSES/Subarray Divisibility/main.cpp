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
#define FORR(i, n) for(int i = n; i > 0; --i)

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int n, a[N];
ll s[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n;
    FOR(i, n) cin >> a[i];
    FOR(i, n) s[i] = (s[i - 1] + a[i] + n) % n;
    map <int, int> mp;
    int ans = 0;
    for(int i = n; i > 0; --i) {
        ans += mp[s[i-1]];
//        cout << i << sp << ans << nl;
//        if(a[i] % n == 0 && a[i] != 0) ++ans;
        ++mp[s[i]];
    }
//    FOR(i, n) cout << s[i] << sp;
//    cout << nl;
    cout << ans;

    return 0;
}

