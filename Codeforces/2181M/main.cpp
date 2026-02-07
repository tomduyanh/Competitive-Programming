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

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

#include <stdint.h>

int _reverse(int num, int n) {
    int x = (int)num;
    int r = 0;

    if (n < 32) x &= ((1u << n) - 1u);

    for (int i = 0; i < n; ++i) {
        r = (r << 1) | (x & 1u);
        x >>= 1;
    }
    return (int)r;
}


void solve(){
    int n; cin >> n;
    int cur = 0;
    FOR(i, n) cur = (cur << 1) | 1;
    cout << cur << sp;
//    vector <int> ok;
    for(int unlocked_bit = 0; unlocked_bit < n; ++unlocked_bit){
        vector <int> ok;
        for(int num = (1 << (unlocked_bit + 1)) - 1; num >= (1 << unlocked_bit); --num){
            int r_num = _reverse(num, n);
            int temp = cur ^ r_num;
            ok.PB(temp);
//            cout << temp << sp;
        }
//        cout << nl;
        sort(all(ok));
        for(auto it : ok) cout << it << sp;
        ///11111
        ///00101
        ///11010
    }
    cout << nl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    int t; cin >> t;
    while(t--) solve();

//    int a = 5;
//    cout << (1 << 1);

    return 0;
}


