#include <bits/stdc++.h>
#define ntr "\n"
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

int n, m;
int a[N], b[N];

void read(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < m; ++i) cin >> b[i];
}

int z[N];

void Z(){
    int l = 0, r = 0;
    for(int i = 1; i < n; ++i) {
        if(i <= r) z[i] = min(r - i + 1, z[i-l]);
        while(i + z[i] < n && a[z[i]] == a[i+z[i]]) ++z[i];
        if(i + z[i] - 1 > r) {
            r = i + z[i] - 1;
            l = i;
        }
    }
}

void solve(){
    if(m == 1){
        cout << n;
        return;
    }
    for(int i = 0; i < n - 1; ++i) a[i] = a[i+1] - a[i];
    for(int i = 0; i < m - 1; ++i) b[i] = b[i+1] - b[i];
    b[m - 1] = 1e9 + 1;
    for(int i = 0; i < n - 1; ++i) b[i+m+1] = a[i];
    n += m + 1;
    for(int i = 0; i < n; ++i) a[i] = b[i];
    Z();
    int ans = 0;
    for(int i = m; i < n; ++i)
        if(z[i] == m - 1) ++ans;
    cout << ans;
}

int ans = 0;

void cu(int n){
    cout << "Dien cai ten vo day : +";
    string name;
    getline(cin, name);
    cout << "Chao ban " << name << nl;
    cout << "Cung dem so tu 1 den 10 nao\n";
    for(int i = 1; i <= 10; ++i) cout << i << sp;
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //freop();
    //cu(10);
    read();
    solve();

    return 0;
}
