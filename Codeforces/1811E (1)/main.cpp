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

bool check(int x){
    for(; x > 0; x /= 10)
        if(x % 10 == 4) return true;
    return false;
}

int change(int x){
    int val = 0, xx = x, ten = 1;
    while(xx > 0){
        if(xx % 10 == 4) val -= ten;
        xx /= 10;
        ten *= 10;
    }
    return x + val;
}

int Find(int val){
    int f = 1, ten = 10;
    int ans = 0, val1 = val;
    if(val % 10 >= 4) ++ans;
    val /= 10;
    while(val > 0){
        int bruh = (val % 10) * f;
        if(val % 10 >= 4) bruh += ten - f;
        ans += bruh;
        f = f * 9 + ten;
        ten *= 10;
        val /= 10;
    }
    return val1 - ans;
}

void solve(){
    int n; cin >> n;
    int lo = 1, hi = (int)1e18;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        bool bruh = false;
        if(check(mid)){
            mid = change(mid);
            bruh = true;
//            hi = 2 * mid - lo;
        }
        int pos = Find(mid);
        cout << lo << sp << mid << sp << hi << nl;
        if(pos > n){
            hi = mid - 1;
        }
        else if(pos < n){
            lo = mid + 1;
        }
        else{
            cout << mid << nl;
            return;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

//    int n; cin >> n;
//    cout << Find(n);
    int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}

