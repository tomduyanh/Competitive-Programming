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

int fact(int val, int x){
    int cnt = 0, k = x;
    while(x <= val){
        x *= k;
        ++cnt;
    }
    return cnt;
}

int bs(int lo, int hi, int m, int r){
    int pos = lo - 1;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        int num = mid * m;
        num /= 2, num *= 3;
        if(num <= r){
            pos = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    return pos;
}

void solve(){
    int l, r; cin >> l >> r;
    int ans = 0;
    int cnt = fact(r / l, 2);
    int m = (1 << cnt);
    int hi = r / m;
    int liem = bs(l, hi, m, r);
    ans = (liem - l + 1) * (1 + cnt) + (hi - liem);
    cout << cnt + 1 << sp << ans << nl;
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
