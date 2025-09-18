#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
void solve(){
    int n, q;
    cin >> n >> q; int qq = q;
    vector <int> a(n + 2);
    FOR(i, n) cin >> a[i];
    int mx = 0;
    vector <int> ans(n+1), pos;
    FOR(i, n) ans[i] = 0;
    for(int i = n; i > 0; --i){
        if(a[i] > mx && q >= a[i]){
            pos.PB(i);
            mx = a[i];
            ans[i] = 1;
        }
    }
    pos.PB(0), pos.PB(n+1); sort(all(pos));

    for(auto it : pos) cout << it << sp;
    cout << nl;

    for(int i = 0; i < pos.size() - 1; ++i){
        int lo = pos[i], hi = pos[i + 1];
        for(int j = lo + 1; j < hi; ++j){
            if(q >= a[j]) ans[j] = 1;
            else if(q > a[hi] && q < a[j]){
                --q;
                ans[j] = 1;
            }
        }
    }
    /*
    cout << q << nl;
    for(int i = 1; i <= n; ++i) cout << ans[i];
    cout << nl;
    for(int i = n; i > 0 && q; --i)
        if(ans[i] == 0){
            ans[i] = 1;
            --q;
        }
    */
    for(int i = 1; i <= n; ++i) cout << ans[i];
    cout << nl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));
    int t; cin >> t;
    while(t--) solve();
    return 0;
}


