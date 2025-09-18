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

struct SegTree{
    ll mx;
    ll lef, rig;
    ll sum;
}seg[4*N];

int n, m;
int a[N];

void build(int id, int l, int r){
    if(l == r){
        seg[id].mx = seg[id].lef = seg[id].rig = seg[id].sum = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    seg[id].mx = max(seg[id].mx, seg[id*2].rig + seg[id*2+1].lef);
    seg[id].lef = max(seg[id].lef, seg[id*2].sum + seg[id*2+1].lef);
    seg[id].rig = max(seg[id].rig, seg[id*2].rig + seg[id*2+1].sum);
    seg[id].sum = seg[id*2].sum + seg[id*2+1].sum;
}

void read(){
    cin >> n >> m;
    FOR(i, n) cin >> a[i];
    build(1, 1, n);
}

void update(int id, int l, int r, int pos, int val){
    if(r < pos || pos < l) return;
    if(pos == l && r == pos){
        seg[id].mx = seg[id].lef = seg[id].rig = seg[id].sum = a[pos];
        return;
    }
    int mid = (l + r) / 2;
    update(id*2, l, mid, pos, val);
    update(id*2+1, mid+1, r, pos, val);
    seg[id].mx = max(seg[id].mx, seg[id*2].rig + seg[id*2+1].lef);
    seg[id].lef = max(seg[id].lef, seg[id*2].sum + seg[id*2+1].lef);
    seg[id].rig = max(seg[id].rig, seg[id*2].rig + seg[id*2+1].sum);
    seg[id].sum = seg[id*2].sum + seg[id*2+1].sum;
}


void solve(){
    cout << seg[2].rig << sp << seg[3].lef << nl;
    while(m--){
        int pos, val; cin >> pos >> val;
        update(1, 1, n, pos, val);
        cout << seg[1].mx << nl;
    }
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

