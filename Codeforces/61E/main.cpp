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

const int N = 1e6 + 1;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int n;
int a[N];

void read(){
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
}

void compress(){
    map <int, int> mp;
    for(int i = 1; i <= n; ++i) ++mp[a[i]];
    int cnt = 0;
    for(auto it : mp) mp[it.F] = ++cnt;
    for(int i = 1; i <= n; ++i) a[i] = mp[a[i]];
}

ll seg[4*N][2]; ///seg[i][0] = so a[i] > a[j]
                 ///seg[i][1] = so a[i] > a[j] > a[k]

void add(int node, ll val, int state){
    node += n; seg[node][state] += val;
    for(node /= 2; node > 0; node /= 2)
        seg[node][state] = seg[node*2][state] + seg[node*2+1][state];
}

ll query(int lo, int hi, int state){
    lo += n, hi += n;
    ll ans = 0;
    while(lo <= hi){
        if(lo % 2 == 1) ans += seg[lo++][state];
        if(hi % 2 == 0) ans += seg[hi--][state];
        lo /= 2, hi /= 2;
    }
    return ans;
}

void solve(){
    reverse(a+1, a+n+1);
    ll ans = 0;
    for(int i = 1; i <= n; ++i){
        int val = a[i];
        int upd1 = query(0, val - 1, 0);
        add(val - 1, 1, 0);
        ans += query(0, val - 1, 1);
        add(val - 1, upd1, 1);
    }
    cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    read();
    compress();
    solve();

    return 0;
}
