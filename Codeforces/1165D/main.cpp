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

const int N = 1e6 + 5;
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

void solve(){
    cin >> n;
    FOR(i, n) cin >> a[i];
    sort(a+1, a+n+1);
    int cur;
    if(n % 2 == 0) cur = a[n] * a[1];
    else cur = a[n/2+1] * a[n/2+1];
    vector <int> uoc;
    for(int i = 2; i * i <= cur; ++i){
        if(cur % i == 0){
            uoc.PB(i);
            if(i*i != cur) uoc.PB(cur/i);
        }
    }
    sort(all(uoc));
//    for(auto it : uoc) cout << it << sp;
//    cout << nl;
    if(uoc.size() != n){
        cout << -1 << nl;
        return;
    }
    for(int i = 0; i < uoc.size(); ++i){
        if(uoc[i] != a[i+1]){
            cout << -1 << nl;
            return;
        }
    }
    cout << cur << nl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}

