#include <bits/stdc++.h>
using namespace std;

#define dl  long double
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
const int B = 1e9;
const int eps = 1e-9;
const ll INF = 1e18;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int n, w, h;
int a[N], b[N];

void read(){
    cin >> n >> w >> h;
    FOR(i, n) cin >> a[i] >> b[i];
}

bool smaller(dl x, dl y){
    return y - x > eps;
}

bool valid(dl k){
    dl cur_h = 0, cur_w = 0, cur_ln = 0;
    FOR(i, n){
        if(smaller(w, cur_w + a[i] * k) || (b[i] != b[i-1] && i != 1)){
            cur_h += cur_ln * k;
            cur_ln = cur_w = 0;
        }
        cur_w += (dl)a[i] * k;
        cur_ln = max(cur_ln, (dl)b[i]);
        if(smaller((dl)h, cur_h + cur_ln * k)) return false;
        if(smaller((dl)w, cur_w)) return false;
    }
    if(smaller((dl)h, (dl)cur_h + cur_ln * k)) return false;
    if(smaller((dl)w, (dl)cur_w)) return false;
    return true;
}

bool ok(dl mid, dl nxt_mid){
    mid = (dl) mid * B;
    nxt_mid = (dl) nxt_mid * B;
    if(mid == nxt_mid) return true;
    return false;
}

void solve(){
    dl lo = 0, hi = (dl)1e9, ans = 1, mid = 0;
    while((hi - lo) > eps){
        dl nxt_mid = (lo + hi) / 2;
        if(!ok(mid, nxt_mid)) mid = nxt_mid;
        else break;
        if(valid(mid)){
            ans = mid;
            lo = mid;
        }
        else hi = mid;
    }
    cout << fixed << setprecision(6) << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    read();
    solve();

    return 0;
}

