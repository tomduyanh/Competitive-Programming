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
const int BIT = 60;
const ll INF = 1e18;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

ll L, R;
vector <int> a, b, ans;

void conv(){
    for(int i = 0; i < BIT; ++i){
        if(L & (1ll << i)) a.PB(1);
        else a.PB(0);
    }
    for(int i = 0; i < BIT; ++i){
        if(R & (1ll << i)) b.PB(1);
        else b.PB(0);
    }
//    reverse(all(a)), reverse(all(b));
//    for(auto it : a) cout << it;
//    cout << nl;
//    for(auto it : b) cout << it;
//    cout << nl;
//    reverse(all(a)), reverse(all(b));
}

void solve(){
    int pos = a.size() - 1;
    for(int i = a.size() - 1; i >= 0; --i, pos = i){
        ans.PB(0);
        if(a[i] != b[i]) break;
    }
//    cout << pos << nl;
    for(int i = pos; i >= 0; --i){
//        cout << "w";
        ans.PB(1);
    }
//    for(auto it : ans) cout << it;
//    cout << nl;
    reverse(all(ans));
    ll cur = 1, res = 0;
    for(int i = 0; i < ans.size(); ++i){
        if(ans[i]) res += cur;
        cur *= 2;
    }
    cout << res;
//    for(auto it : ans) cout << it;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> L >> R;
    conv();
    solve();

    return 0;
}

