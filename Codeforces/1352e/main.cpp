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

const int N = 8e3;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int n;
//, mp[N*N], ans[N];

void solve(){
    cin >> n;
    vector <int> a(n+1);
    vector <int> s(n+1);
    vector <bool> ans(n*n+1);
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }
    for(int i = 1; i <= n; ++i){
        for(int j = i+1; j <= n; ++j) ans[s[j] - s[i-1]] = true;
    }
    int res = 0;
    for(int i = 1; i <= n; ++i)
        if(ans[a[i]]) ++res;
    cout << res << "\n";
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
