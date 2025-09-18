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

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int n, m, mxval = 0;
int a[N], b[N];

void read(){
    cin >> n; FOR(i, n) cin >> a[i];
    cin >> m; FOR(i, m) cin >> b[i];
}

bool valid(int val){
    int j = 1;
    FOR(i, n){
        if(a[i] < val){
            if(j > m) return false;
            while(j <= m && b[j] + a[i] < val) ++j;
            if(a[i] + b[j] < val) return false;
            ++j;
        }
    }
    return true;
}

void solve(){
    int lo = 1, hi = (int)2e8, ans = 1;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(valid(mid)){
            ans = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    read();
    solve();

    return 0;
}

