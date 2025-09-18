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

const int N = 2e5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int n, q;
int lg[N + 1];
ll a[N + 1];
ll st[18][N + 1];

void read(){
    cin >> n >> q;
    FOR(i, n) cin >> a[i];
}

void preCal(){
    for(int i = 1; i <= N; ++i) lg[i] = lg[i / 2] + 1;
    FOR(i, n) st[0][i] = a[i];
    for(int j = 1; j < 18; ++j){
        for(int i = 1; i + (1 << j) - 1 <= n; ++i){
            st[j][i] = min(st[j-1][i], st[j-1][i + (1 << (j - 1))]);
        }
    }
}

ll getMin(int l, int r){
    int LG = lg[r - l + 1];
    return min(st[LG][l], st[LG][r - (1 << LG) + 1]);
}

int BS(ll t, int l, int r){
    int pos = 0;
    int lo = l, hi = r;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        ll val = getMin(l, mid);
        if(val <= t){
            pos = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    return pos;
}

void solve(){
    while(q--){
        ll t; int l, r; cin >> t >> l >> r;
        int lo = l, hi = r;
        while(lo <= hi){
            int pos = BS(t, lo, hi);
            if(!pos) break;
            t = t % a[pos];
            lo = pos + 1;
        }
        cout << t << nl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    read();
    preCal();
    solve();

    return 0;
}
