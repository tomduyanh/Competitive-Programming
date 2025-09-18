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

int n, q;
int seg[2*N];

void add(int k, int val){
    k += n; seg[k] += val;
    for(k /= 2; k > 0; k /= 2) seg[k] = seg[k*2] + seg[k*2+1];
}

int get(int lo, int hi){
    ll ans = 0;
    lo += n, hi += n;
    while(lo <= hi){
        if(lo % 2 == 1) ans += seg[lo++];
        if(hi % 2 == 0) ans += seg[hi--];
        lo /= 2, hi /= 2;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n >> q;
    FOR(i, 2*n) seg[i] = 0;
    while(q--){
        int t, l, r; cin >> t >> l >> r;
        if(t == 1) add(l - 1, r);
        else cout << get(l - 1, r - 1) << nl;
    }

    return 0;
}


