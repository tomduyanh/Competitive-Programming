#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5000 + 5;
const int MOD = 1e9 + 7, BASE = 31;


int n, m;
int h[N][N];
char s[N][N];

void read(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) cin >> s[i][j];
    }
}

void buildHash(){
    for(int j = 1; j <= m; ++j){
        for(int i = n; i > 0; --i){
            h[i][j] = ((h[i+1][j] * BASE + (s[i][j] - 'a' + 1))) % MOD;
        }
    }
}

void solve(){
    int lo = 0, hi = n - 1, ans = 0;
    set <int> Set;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        for(int j = 1; j <= m; ++j){
            Set.insert(h[mid + 1][j]);
        }
        if(Set.size() == m) {
            ans = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
        Set.clear();
    }
    cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("DELROW.INP", "r", stdin);
    freopen("DELROW.OUT", "w", stdout);

    read();
    buildHash();
    solve();

    return 0;
}

