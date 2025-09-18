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

int n, q;
int a[N];
struct ST{
    ll val, mod, lazy;
    int type;
}seg[4*N];

void read(){
    cin >> n >> q;
    FOR(i, n) cin >> a[i];
    FOR(i, 4*n){
        seg[i].mod = 1;
        seg[i].type = 2;
    }
}

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

void down(int id, int l, int mid, int r){
    cout << id << sp;
    ll modulo = seg[id].mod;
    if(seg[id*2].type == 2){
        cout << id * 2 << sp;
        seg[id*2].val = seg[id*2].val % modulo;
        seg[id*2].mod *= modulo;
    }
    if(seg[id*2+1].type == 2){
        cout << id * 2 + 1 << sp;
        seg[id*2+1].val = seg[id*2+1].val % modulo;
        seg[id*2+1].mod *= modulo;
    }
    cout << nl;
    seg[id].mod = 1;
}

void update(int id, int l, int r, int u, int v, int x, int type){
    if(v < l || r < u) return;
    if(u <= l && r <= v){
        if(type == 2){
//            cout << id << nl;
            seg[id].val = seg[id].val % x;
            seg[id].mod *= x;
            seg[id].type = type;
            return;
        }
        else{
            seg[id].val = x;
            seg[id].mod = 1;
            seg[id].type = type;
            return;
        }
    }
    int mid = (l + r) / 2;
    down(id, l, mid, r);
    update(id*2, l, mid, u, v, x, type);
    update(id*2+1, mid+1, r, u, v, x, type);
    seg[id].val = seg[id*2].val + seg[id*2+1].val;
}

ll getSum(int id, int l, int r, int u, int v){
    if(v < l || r < u) return 0LL;
    if(u <= l && r <= v){
        return seg[id].val;
    }
    int mid = (l + r) / 2;
    down(id, l, mid, r);
    return getSum(id*2, l, mid, u, v) + getSum(id*2+1, mid+1, r, u, v);
}

void solve(){
    while(q--){
        int type; cin >> type;
        if(type == 1){
            int l, r; cin >> l >> r;
            cout << getSum(1, 1, n, l, r) << "w" << nl;
        }
        if(type == 2){
            int l, r, x; cin >> l >> r >> x;
            update(1, 1, n, l, r, x, type);
        }
        if(type == 3){
            int k, x; cin >> k >> x;
            update(1, 1, n, k, k, x, type);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    read();
    build(1, 1, n);
    solve();

    return 0;
}

