#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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

const int N = 1e5 + 1;
const int BL = 500;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int n, m, q;
int sz[BL+1][N], heavyIdx[N];
ll a[N], heavySum[N], heavyAdd[N];
vector <int> heavy, sets[N];

void read(){
    cin >> n >> m >> q;
    FOR(i, n) cin >> a[i];
    FOR(i, m){
        int sz; cin >> sz;
        while(sz--){
            int idx; cin >> idx;
            sets[i].PB(idx);
        }
        sort(all(sets[i]));
    }
}

int get_inter_size(int idx_light, int idx_heavy){

    int ans = 0, i = 0, j = 0;
    int sz_light = sets[idx_light].size(), sz_heavy = sets[idx_heavy].size();

    while(i < sz_light && j < sz_heavy){
        if(sets[idx_light][i] < sets[idx_heavy][j]) ++i;
        else if(sets[idx_light][i] > sets[idx_heavy][j]) ++j;
        else ++ans, ++i, ++j;
    }

    return ans;
}

void pre(){
    FOR(i, m){
        if(sets[i].size() < BL) continue;
        heavy.PB(i);
        for(auto id : sets[i]) heavySum[i] += a[id];
    }
}

void build(){
    int cnt = 0;
    for(auto id : heavy) heavyIdx[id] = ++cnt;

    for(auto id_heavy : heavy){
        FOR(i, n){
            if(i == id_heavy) continue;
            sz[ heavyIdx[id_heavy] ][i] = get_inter_size(id_heavy, i);
        }
    }

}

void add(int idx, int val){
    if(sets[idx].size() < BL){ ///light
        for(auto id : sets[idx]) a[id] += val;
        for(auto id : heavy) heavySum[id] += (ll)val * sz[heavyIdx[id]][idx];
    }
    else heavyAdd[idx] += val; ///heavy
}

ll getans(int idx){
    ll ans = 0;
    if(sets[idx].size() < BL){
        for(auto id : sets[idx]) ans += a[id];
        for(auto id : heavy) ans += heavyAdd[id] * sz[heavyIdx[id]][idx];
    }
    else{
        ans = (ll)heavySum[idx] + (ll)sets[idx].size() * heavyAdd[idx];
        for(auto id : heavy){
            if(id == idx) continue;
            ans += (ll)heavyAdd[id] * sz[heavyIdx[id]][idx];
        }
    }
    return ans;
}

void solve(){
    while(q--){
        char type; cin >> type;
        if(type == '+'){
            int k, x; cin >> k >> x;
            add(k, x);
        }
        else {
            int x; cin >> x;
            cout << getans(x) << nl;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    read();
    pre();
    build();
    solve();

    return 0;
}

