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
#define FORR(i, n) for(int i = n; i > 0; --i)

const int N = 1e5 + 5;
const int M = 5 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int n, m, k;
int a[N][M], seg[4*N][M];

int getMax(int id, int l, int r, int u, int v, int type){
    if(v < l || r < u) return 0;
    if(u <= l && r <= v) return seg[id][type];
    int mid = (l + r) / 2;
    return max( getMax(id*2, l, mid, u, v, type) , getMax(id*2+1, mid+1, r, u, v, type) );
}

bool valid(int lo, int hi){
    ll sum = 0;
    FOR(i, m) sum = sum + (ll)getMax(1, 1, n, lo, hi, i);
    return sum <= k;
}

int bs(int lo, int hi){
    int pos = -1, loo = lo;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(valid(loo, mid)){
            pos = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    return pos;
}

void build(int id, int l, int r, int type){
    if(l == r){
        seg[id][type] = a[l][type];
        return;
    }
    int mid = (l + r) / 2;
    build(id*2, l, mid, type);
    build(id*2+1, mid+1, r, type);
    seg[id][type] = max(seg[id*2][type], seg[id*2+1][type]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n >> m >> k;
    FOR(i, n) FOR(j, m) cin >> a[i][j];

    FOR(i, m) build(1, 1, n, i);

    int lo = -1, hi = -1;
    FOR(i, n){
        int pos = bs(i, n);
        if(pos - i + 1 >= hi - lo + 1){
            lo = i;
            hi = pos;
        }
    }

    if(!lo){
        cout << 0;
        return 0;
    }
    FOR(i, m) cout << getMax(1, 1, n, lo, hi, i) << sp;

    return 0;
}

