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

int n, m;
int a[N];
pii seg[2][4*N];
///seg[0][id] = segtree on mn
///seg[1][id] = segtree on a[i] aka sum
///lazy only on segtree on mn

void read(){
    cin >> n >> m;
    FOR(i, n) cin >> a[i];
}

void build(int id, int l, int r){
    if(l == r){
        seg[1][id].F = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    seg[1][id].F = seg[1][id*2].F + seg[1][id*2+1].F;
}

int cal(int l, int r){
    int N = r - l + 1;
    double ans = (double)N / 2;
    return ans * (r + l);
}

void down(int id, int l, int mid, int r){ ///build sum segment tree on mn
    int t = seg[1][id].S;
    ///mn
    seg[1][id*2].F += t * (mid - l + 1), seg[1][id*2].S += t;
    seg[1][id*2+1].F += t * (r - mid), seg[1][id*2+1].S += t;
    seg[1][id].S = 0;
    ///cnt
    t = seg[0][id].S;
    seg[0][id*2].F += t * cal(l, mid), seg[0][id*2].S += t;
    seg[0][id*2+1].F += t * cal(mid+1, r), seg[0][id*2+1].S += t;
    seg[0][id].S = 0;
}

void update(int id, int l, int r, int u, int v, int type){
    if(v < l || r < u) return;
    if(u <= l && r <= v){
        if(type == 1){
            seg[type][id].F += (1 - u) * (r - l + 1);
            seg[type][id].S += (1 - u);
        }
        else{
            seg[type][id].F += cal(l, r);
            seg[type][id].S += 1;
        }
        return;
    }
    int mid = (l + r) / 2;
    down(id, l, mid, r);
    update(id*2, l, mid, u, v, type);
    update(id*2+1, mid+1, r, u, v, type);
    for(int k = 0; k < 2; ++k) seg[k][id].F = seg[k][id*2].F + seg[k][id*2+1].F;
}

int get(int id, int l, int r, int u, int v, int type){
    if(v < l || r < u) return 0;
    if(u <= l && r <= v) return seg[type][id].F;
    int mid = (l + r) / 2;
    down(id, l, mid, r);
    return get(id*2, l, mid, u, v, type) + get(id*2+1, mid+1, r, u, v, type);
}

void solve(){
    build(1, 1, n); ///construct sum
    while(m--){
        int type, l, r; cin >> type >> l >> r;
        if(type == 1){
            update(1, 1, n, l, r, 0);
            update(1, 1, n, l, r, 1);
        }
        else{
            int mn  = get(1, 1, n, l, r, 0);
            int cnt = get(1, 1, n, l, r, 1);
            cout << mn + cnt << nl;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

//*
    read();
    solve();
//*/
/*
    int l, r; cin >> l >> r;
    cout << cal(l, r);
*/
    return 0;
}

