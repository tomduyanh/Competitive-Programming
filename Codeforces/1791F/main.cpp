#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int,int> pii;
typedef pair <ll , ll> pll;

#define int long long
#define sp " "
#define nl "\n"
#define F first
#define S second
#define PB push_back
#define all(arr) arr.begin(), arr.end()

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

struct Node {
    ll lazy, val;
}tree[4*N];

void down(ll id, ll l, ll mid, ll r) {
    ll t = tree[id].lazy;
    tree[id*2+1].lazy += t;
    tree[id*2].lazy += t;
    tree[id*2].val += t * (mid - l + 1);
    tree[id*2+1].val += t * (r - mid);
    tree[id].lazy = 0;
}

void update(ll id, ll l, ll r, ll u, ll v, ll val) {
    if(v < l || r < u) return;
    if(u <= l && r <= v) {
        tree[id].lazy += val;
        tree[id].val += val * (r - l + 1);
        return;
    }
    ll mid = (l + r) / 2;
    down(id, l, mid, r);
    update(id*2, l, mid, u, v, val);
    update(id*2+1, mid+1, r, u, v, val);
    tree[id].val = tree[id * 2].val + tree[id * 2 + 1].val;
}

ll get(ll id, ll l, ll r, ll pos) {
    if(pos < l || r < pos) return 0;
    if(pos <= l && r <= pos) {
        return tree[id].val;
    }
    ll mid = (l + r) / 2;
    down(id, l, mid, r);
    return get(id*2, l, mid, pos) + get(id*2+1, mid+1, r, pos);
}

int sum(int x){
    int res = 0;
    while(x > 0){
        res += (x % 10);
        x /= 10;
    }
    return res;
}

void updatePos(int id, int val){
    while(val--) a[id] = sum(a[id]);
}

void solve(){
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 0; i <= 4*n; ++i) tree[i].val = tree[i].lazy = 0;
    while(q--){
        int type; cin >> type;
        if(type == 1){
            int l, r; cin >> l >> r;
            update(1, 1, n, l, r, 1);
        }
        else{
            int id; cin >> id;
            ll val = get(1, 1, n, id);
            updatePos(id, val);
            cout << a[id] << nl;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
