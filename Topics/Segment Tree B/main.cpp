#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
int n, q, k, a[100001], sz = 0;
vector <int> seg[4*100001];
map <int, int> val, trace;
void build(int id, int l, int r){
    if(l == r){
        seg[id].PB(a[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    merge(seg[id*2].begin(), seg[id*2].end(), seg[id*2+1].begin(), seg[id*2+1].end(), back_inserter(seg[id]));
}
int get(int id, int l, int r, int u, int v, int val){
    if(v < l || r < u) return 0;
    if(u <= l && r <= v) return upper_bound(seg[id].begin(), seg[id].end(), val) - seg[id].begin();
    int mid = (l + r) / 2;
    return get(id*2, l, mid, u, v, val) + get(id*2+1, mid+1, r, u, v, val);
}
int bs(int l, int r){
    int val = k;
    int lo = 1, hi = sz, pos = 0;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        int res = get(1, 1, n, l, r, mid);
        if(res < val) lo = mid + 1;
        if(res >= val){
            hi = mid - 1;
            pos = mid;
        }
    }
    return pos;
}
void compress(){
    for(int i = 1; i <= n; ++i) val[a[i]] = 1;
    for(auto it : val) val[it.first] = ++sz;
    for(int i = 1; i <= n; ++i){
        trace[val[a[i]]] = a[i];
        a[i] = val[a[i]];
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        sz = max(sz, a[i]);
    }
    compress();x`
    build(1, 1, n);
    while(q--){
        int l, r; cin >> l >> r >> k;
        cout << bs(l, r) << "\n";
    }
    return 0;
}
