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

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen(".INP", "r", stdin);
    freopen(".OUT", "w", stdout);
}

string s;
int n;
int z[N];

void Zed() {
    cin >> s;
    n = s.size();
    int l = 0, r = 0;
    z[0] = 1;
    s = s + '*' + s;
    n = n * 2 + 1;
    for(int i = 1; i < n; ++i) {
        if(i <= r) z[i] = min(r - i + 1, z[i - l]);
        while(i + z[i] < n && s[z[i]] == s[i+z[i]]) ++z[i];
        if(i + z[i] - 1 > r) {
            r = i + z[i] - 1;
            l = i;
        }
    }
}

void solve() {
    vector <pii> ans;
    vector <pii> a(n);
    map <int, int> val;

    for(int i = 0; i < n; ++i) cout << i << sp;
    cout << nl;
    for(int i = 0; i < n; ++i) cout << s[i] << sp;
    cout << nl;
    for(int i = 0; i < n; ++i) cout << z[i] << sp;
    cout << nl;

    int on = (n - 1) / 2;
    cout << on << nl;
    for(int i = n / 2 + 1, j = 0; i < n; ++i, ++j) {
        if(!z[i]) continue;
        cout << n - z[i] << sp << z[n - z[i]] << sp << z[i] << sp << n << nl;
        if((z[n - z[i]] + n - z[i]) != n) continue;
        ++val[z[i]];
        cout << nl;
    }
    int cnt = 0;
    for(map <int,int> :: iterator it = val.begin(); it != val.end(); ++it) {
        ++cnt;
        a[cnt].F = it->F;
        a[cnt].S = it->S;
    }
    for(int i = cnt - 1; i > 0; --i) {
        a[i].S += a[i+1].S;
    }
    cout << nl << nl;
    cout << cnt << nl;
    for(int i = 1; i <= cnt; ++i) {
        cout << a[i].F << sp << a[i].S << nl;
    }
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //freop();

    Zed();
    solve();

    return 0;
}
