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

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int n, q, cnt = 0;
int a[N];
bool bruv = false;
struct ST{
    ll val;
    ll rangeUpd;
    int pointUpd, type, cnt;
}seg[4*N];

void build(int id, int l, int r){
    if(l == r){
        seg[id].val = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    seg[id].val = seg[id*2].val + seg[id*2+1].val;
}

void read(){
    cin >> n >> q;
    FOR(i, n) cin >> a[i];
    build(1, 1, n);
}

///type = 1 -> range upd
///type = 2 -> point upd

void down(int id, int l, int mid, int r){
    int type = seg[id].type;
    if(type == 0) return;
//    cout << "id : " << id << " type : " << type << nl;
    if(type == 1){ ///range update
        ll t = seg[id].rangeUpd;
//        cout << "type 1 ";
        if(seg[id*2].cnt <= seg[id].cnt){
//            cout << id * 2 << sp;
            seg[id*2].val += t * (mid - l + 1);
            seg[id*2].rangeUpd += t;
            seg[id*2].cnt = seg[id].cnt;
            seg[id*2].type = type;
        }
        if(seg[id*2+1].cnt <= seg[id].cnt){
//            cout << id * 2 + 1 << sp;
            seg[id*2+1].val +=  t * (r - mid);
            seg[id*2+1].rangeUpd += t;
            seg[id*2+1].cnt = seg[id].cnt;
            seg[id*2+1].type = type;
        }
        seg[id].rangeUpd = 0;
    }
    if(type == 2){
        int t = seg[id].pointUpd;
        if(t == 0) return;
//        cout << "type 2 ";
        if(seg[id*2].cnt <= seg[id].cnt){
//            cout << id * 2 << sp;
            seg[id*2].val = t * (mid - l + 1);
            seg[id*2].pointUpd = t;
            seg[id*2].cnt = seg[id].cnt;
            seg[id*2].rangeUpd = 0;
            seg[id*2].type = type;
        }
        if(seg[id*2+1].cnt <= seg[id].cnt){
//            cout << id * 2 + 1 << sp;
            seg[id*2+1].val = t * (r - mid);
            seg[id*2+1].pointUpd = t;
            seg[id*2+1].cnt = seg[id].cnt;
            seg[id*2+1].rangeUpd = 0;
            seg[id*2+1].type = type;
        }
        seg[id].pointUpd = 0;
        seg[id].rangeUpd = 0;
    }
//    cout << nl;
}

void update(int id, int l, int r, int u, int v, int x, int t, int cnt){
    if(v < l || r < u) return;
    if(u <= l && r <= v){
        if(t == 1){ ///range update
            seg[id].val += x * (r - l + 1);
            seg[id].pointUpd = 0;
            seg[id].rangeUpd += x;
        }
        if(t == 2){ ///point update
            seg[id].val = x * (r - l + 1);
            seg[id].pointUpd = x;
            seg[id].rangeUpd = 0;
        }
        seg[id].type = t;
        seg[id].cnt = cnt;
        return;
    }
    int mid = (l + r) / 2;
    down(id, l, mid, r);
    update(id*2, l, mid, u, v, x, t, cnt);
    update(id*2+1, mid+1, r, u, v, x, t, cnt);
    seg[id].val = seg[id*2].val + seg[id*2+1].val;
}

ll get(int id, int l, int r, int u, int v){
    if(v < l || r < u) return 0;
    if(u <= l && r <= v){
        return seg[id].val;
    }
    int mid = (l + r) / 2;
    down(id, l, mid, r);
    return get(id*2, l, mid, u, v) + get(id*2+1, mid+1, r, u, v);
}

void solve(){
    while(q--){
        ++cnt;
        int t; cin >> t;
        if(t <= 2){
            int l, r, x; cin >> l >> r >> x;
            update(1, 1, n, l, r, x, t, cnt);
        }
        else{
            int l, r; cin >> l >> r;
            cout << get(1, 1, n, l, r) << nl;
        }
    }
//    cout << nl;
//    FOR(i, 2*n-1) cout << i << sp << seg[i].type << sp << seg[i].cnt << sp << seg[i].val << nl;
//    cout << nl;
//    cout << seg[2].cnt << nl;
//    vector <int> bruh;
//    for(int i = 1; i <= n; ++i) bruh.PB(get(1, 1, n, i, i));
//    for(auto it : bruh) cout << it << sp;
//    cout << nl;
//    FOR(i, 2*n-1) cout << i << sp << seg[i].type << sp << seg[i].cnt << sp << seg[i].val << nl;
//    cout << nl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(cnt(NULL));

    read();
    solve();

    return 0;
}
