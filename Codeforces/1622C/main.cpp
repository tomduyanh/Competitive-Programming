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

int n, k;
int a[N];

int get(int pos, int need){
    int cur = pos, cnt = pos;
    if(cur >= need) return cnt;
    for(int i = n; i > 1; --i){
        ++cnt;
        cur += pos + a[i] - a[1];
        if(cur >= need) return cnt;
    }
    return 0;
}

int solve(){
    cin >> n >> k;
    int need = -k;
    FOR(i, n){
        cin >> a[i];
        need += a[i];
    }
    int sumdif = 0;
    if(n == 1) return max(0ll, a[1] - k);
    sort(a+1, a+n+1);
    FOR(i, n) sumdif += a[i] - a[1];
    if(need <= 0) return 0;
    int ans = INF;
    int lo = 1, hi = (int)1e15;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        int sum = mid * n + sumdif;
        if(sum >= need){
            ans = min(ans, get(mid, need));
            cout << lo << sp << hi << sp << mid << sp << ans << nl;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    int t; cin >> t;
    while(t--) cout << solve() << nl;

    return 0;
}

