#include <bits/stdc++.h>
using namespace std;

#define int long long
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
const int MOD = 1e9 + 7;
const int BLOCK = 400;
const ll INF = 1e18;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int n, m, k, ans = 0;
int a[N], res[N], ps[N], freq[(1 << 20)+ 1];
struct num{
    int l, r, id;
}q[N];

bool compare(num a, num b){
    if(a.l / BLOCK != b.l / BLOCK) return a.l < b.l;
    else return a.r < b.r;
}

void read(){
    cin >> n >> m >> k;
    FOR(i, n) cin >> a[i];
    FOR(i, n) ps[i] = ps[i-1] ^ a[i];
    FOR(i, m){
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
        --q[i].l;
    }
    sort(q+1,q+m+1,compare);
}

void add(int pos){
    ans += freq[ps[pos] ^ k];
    ++freq[ps[pos]];
}

void del(int pos){
    --freq[ps[pos]];
    ans -= freq[ps[pos] ^ k];
}

void solve(){

    freq[0] = 1;
    for(int i = 1; i <= m; ++i){
        int pre_l = q[i-1].l, pre_r = q[i-1].r;
        int cur_l = q[i].l, cur_r = q[i].r;

        while(cur_l < pre_l) add(--pre_l);
        while(pre_r < cur_r) add(++pre_r);
        while(pre_l < cur_l) del(pre_l++);
        while(cur_r < pre_r) del(pre_r--);

        res[q[i].id] = ans;
    }
    FOR(i, m) cout << res[i] << nl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    read();
    solve();

    return 0;
}
