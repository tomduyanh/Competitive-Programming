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

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen(".INP", "r", stdin);
    freopen(".OUT", "w", stdout);
}

int n, q;
int sparse[N][18][2];

void read(){
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        int x; cin >> x;
        sparse[i][0][0] = sparse[i][0][1] = x;
    }
}

int GCDquery(int l, int r) {
    int val = 31 - __builtin_clz(r - l + 1);
    return __gcd(sparse[l][val][0], sparse[r][val][1]);
}

void buildst(){
    for(int s = 1; s < 18; s++) {
        for(int i = 1; i + (1 << s) - 1 <= n; i++) {
            int p = s - 1;
            sparse[i][s][0] = __gcd(sparse[i][p][0], sparse[i + (1 << p)][p][0]);
        }
        for(int i = n; i - (1 << s) + 1 >= 1; i--) {
            int p = s - 1;
            sparse[i][s][1] = __gcd(sparse[i][p][1], sparse[i - (1 << p)][p][1]);
        }
    }
}

map <int, ll> mp;

int BS(int l, int lo, int hi, int val){
    int pos = 0;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        int gcd = GCDquery(l, mid);
        if(gcd >= val){
            lo = mid + 1;
            pos = mid;
        }
        else hi = mid - 1;
    }
    return pos;
}

void cnt(int lo, int hi){
    int l = lo;
    while(lo <= hi){
        int cur = GCDquery(l, lo);
        int pos = BS(l, lo, hi, cur);
        int freq = pos - lo + 1;
        mp[cur] += freq;
        lo = pos + 1;
    }
}

void buildmap(){
    for(int i = 1; i <= n; ++i){
        cnt(i, n);
    }
}

void solve(){
    cin >> q;
    while(q--){
        int x; cin >> x;
        cout << mp[x] << nl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    read();
    buildst();
    buildmap();
    solve();

    return 0;
}
