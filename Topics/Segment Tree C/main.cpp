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

int n, nn = 0, k;
int a[N], aa[N], dp[N], seg[4*N];
map <int, int> val;

void read(){
    cin >> n >> k;
    FOR(i, n) {
        cin >> a[i];
        aa[i] = a[i];
    }
    sort(aa + 1, aa + n + 1);
}

void comp(){
    FOR(i, n) ++val[a[i]];
    for(auto it : val){
        val[it.F] = ++nn;
    }
}

int bsl(int val){
    int lo = 1, hi = n, pos = -1;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(aa[mid] <= val){pos = mid; lo = mid + 1;}
        else hi = mid - 1;
    }
    if(!pos) return pos;
    return aa[pos];
}

int bsu(int val){
    int lo = 1, hi = n, pos = -1;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(aa[mid] >= val){pos = mid; hi = mid - 1;}
        else lo = mid + 1;
    }
    if(!pos) return pos;
    return aa[pos];
}

int getMax(int id, int l, int r, int u, int v){
    if(v < l || r < u || l > r) return 0;
    if(u <= l && r <= v) return seg[id];
    int mid = (l + r) / 2;
    return max( getMax(id*2, l, mid, u, v) , getMax(id*2+1, mid+1, r, u, v) );
}

void update(int id, int l, int r, int pos, int val){
    if(pos < l || r < pos || l > r) return;
    if(l == r && l == pos){
        seg[id] = max(seg[id], val);
        return;
    }
    int mid = (l + r) / 2;
    update(id*2, l, mid, pos, val); update(id*2+1, mid+1, r, pos, val);
    seg[id] = max(seg[id*2], seg[id*2+1]);
}

void solve(){
    FOR(i, n){
        int v1 = val[bsl(a[i] - k)], v2 = val[bsu(a[i] + k)];
        dp[i] = max((v1 ? getMax(1, 1, nn, 1, v1) : 0) + 1 , (v2 ? getMax(1, 1, nn, v2, nn) : 0) + 1);
        update(1, 1, nn, val[a[i]], dp[i]);
    }
    sort(dp + 1, dp + n + 1);
    cout << dp[n];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    read();
    comp();
    solve();

    return 0;
}

