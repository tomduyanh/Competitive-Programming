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

const int N = 3e5 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int n, m;
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
int st[4*N];
void add(int node, int val){
    node += n; st[node] = val;
    for(node /= 2; node > 0; node /= 2)
        st[node] = st[node*2] + st[node*2+1];
}
int query(int lo, int hi){
    lo += n, hi += n;
    int ans = 0;
    while(lo <= hi){
        if(lo % 2 == 1) ans += st[lo++];
        if(hi % 2 == 0) ans += st[hi--];
        lo /= 2, hi /= 2;
    }
    return ans;
}
pii ans[N];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) cin >> a[i];
    map <int, int> pos;
    for(int i = 1; i <= m; ++i){
        pre[i] = pos[a[i]];
        pos[a[i]] = i;
    }
    build(1, 1, m);
    pos.clear();
    for(int i = 1; i <= n; ++i) ans[i].F = ans[i].S = i;
    for(int i = 1; i <= m; ++i){
        int val = a[i];
        if(pos[val] == 0){
            ans[val].S = max(ans[val].S, val + query(val + 1, n));
        }
        else{
            int pre = pos[val];
            ans[val].S = max(ans[val].S, 1 + get(1, 1, m, pre + 1, i - 1, pre + 1));
        }
        pos[val] = i;
        ans[val].F = 1;
        add(val, 1);
    }
    for(int i = 1; i <= n; ++i){
        if(pos[i] == 0){
            ans[i].S = max(ans[i].S, i + query(i + 1, n));
        }
        else{
            int pre = pos[i];
            ans[i].S = max(ans[i].S, 1 + get(1, 1, m, pre + 1, m, pre + 1));
        }
    }
    for(int i = 1; i <= n; ++i) {
        cout << ans[i].F << sp << ans[i].S << nl;
    }
    return 0;
}

