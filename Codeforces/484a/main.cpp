#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;
typedef pair <int,int> pii;
typedef pair <int , int> pint;

#define sp " "
#define nl "\n"
#define F first
#define S second
#define PB push_back
#define aint(arr) arr.begin(), arr.end()
#define FOR(i, n) for(int i = 1; i <= n; ++i)

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e18;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int get(int x, int pos){
    int ans = 0;
    for(int i = 0; i <= pos; ++i)
        if(x & ((int)1 << i)) ans += ((int)1 << i);
    return ans;
}

void solve(){
    int x, y, pos = 63, res = 0; cin >> x >> y;
    vector <int> a, b, ans;
    for(int i = 0; i < 64; ++i){
        a.PB(x & ((ll)1 << i) ? 1 : 0);
        b.PB(y & ((ll)1 << i) ? 1 : 0);
    }
    for(int i = 63; i >= 0; --i, --pos)
        if(a[i] != b[i]) break;
    for(int i = 0; i < 64; ++i){
        if(i < pos) res += ((int)1 << i);
        else if(i == pos){
            if(res + ((int)1 << i) <= get(y, pos)) res += ((int)1 << i);
        }
        else if(b[i]) res += ((int)1 << i);
    }
    cout << res << nl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NUint));

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
