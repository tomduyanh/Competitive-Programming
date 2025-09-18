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

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int n, a[N], sum[N][3];
ll ps[N][3], seg[4*N][3];

void build(int id, int l, int r, int state){
    if(l > r) return;
    if(l == r){
        seg[id][state] = ps[l][state];
        return;
    }
    int mid = (l + r) / 2;
    build(id*2, l, mid, state);
    build(id*2+1, mid+1, r, state);
    seg[id][state] = max(seg[id*2][state], seg[id*2+1][state]);
}

ll get(int id, int l, int r, int u, int v, int state){
    if(v < l || r < u) return -INF;
    if(u <= l && r <= v){
        return seg[id][state];
    }
    int mid = (l + r) / 2;
    return max(get(id*2, l, mid, u, v, state), get(id*2+1, mid+1, r, u, v, state));
}

void solve(){
    cin >> n;
    ll s = 0;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        if(i % 2) s += a[i];
        else ps[i][1] = ps[i][2] = -INF;
    }
    for(int i = 1; i <= 4*n; ++i) seg[i][1] = seg[i][2] = -INF;
    for(int i = 1; i < n; i += 2){
        ps[i][1] = ps[max(i-2, 0)][1] + a[i+1] - a[i];
    }
    for(int i = 3; i <= n; i += 2){
        ps[i][2] = ps[i-2][2] + a[i-1] - a[i];
    }

    build(1, 1, n, 1);
    build(1, 1, n, 2);

    ll mx = -INF;
    for(int i = 1; i <= n; i += 2){
        mx = max({mx, get(1, 1, n, i + 1, n, 1) - ps[max(0, i-2)][1], get(1, 1, n, i + 1, n, 2) - ps[max(0, i-2)][2]});
    }

    ///*
    for(int i = 1; i <= n; ++i) cout << ps[i][1] << sp;
    cout << nl;
    for(int i = 1; i <= n; ++i) cout << ps[i][2] << sp;
    cout << nl;
    cout << s << sp << mx << nl;
    //*/

    cout << s + mx << nl;
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

