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
#define FORR(i, n) for(int i = n; i > 0; --i)

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int n, a[N], seg[4*N];

void reset(){
    FOR(i, 4*n) seg[i] = 0;
}

void update(int id, int l, int r, int pos){
    if(pos < l || r < pos) return;
    if(pos == l && l == r){
        seg[id] = 1;
        return;
    }
    int mid = (l + r)/2;
    update(id*2, l, mid, pos);
    update(id*2+1, mid+1, r, pos);
    seg[id] = seg[id*2] + seg[id*2+1];
}

int get(int id, int l, int r, int u, int v){
    if(v < l || r < u) return 0;
    if(u <= l && r <= v) return seg[id];
    int mid = (l + r) / 2;
    return get(id*2, l, mid, u, v) + get(id*2+1, mid+1, r, u, v);
}

void solve(){
    cin >> n;
    FOR(i, n) cin >> a[i];
    reset();
    int ans = 0;
    FOR(i, n){
//        cout << i << sp;
        int cnt = get(1, 1, n, a[i]+1, n);
        ans += min(cnt, (n-a[i])-cnt);
        update(1, 1, n, a[i]);
    }
    cout << ans << nl;
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
