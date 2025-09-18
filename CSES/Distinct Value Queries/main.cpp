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
int a[N], pre[N];
vector <int> seg[4 * N];

void build(int id, int l, int r){
    if(l == r){
        seg[id].PB(pre[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    merge(all(seg[id*2]), all(seg[id*2+1]), back_inserter(seg[id]));
}

int get(int id, int l, int r, int u, int v, int val){
    if(r < u || l > v) return 0;
    if(u <= l && r <= v) {
        int pos = lower_bound(all(seg[id]), val) - seg[id].begin();
        return pos;
    }
    int mid = (l + r) / 2;
    return get(id*2, l, mid, u, v, val) + get(id*2+1, mid+1, r, u, v, val);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    map <int, int> pos;
    for(int i = 1; i <= n; ++i){
        pre[i] = pos[a[i]];
        pos[a[i]] = i;
    }
    build(1, 1, n);
    while(q--){
        int l, r; cin >> l >> r;
        cout << get(1, 1, n, l, r, l) << nl;
    }
    return 0;
}

