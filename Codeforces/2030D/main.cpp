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

int n, q, a[N];
bool s[N];

void solve(){
    cin >> n >> q;
    FOR(i, n) cin >> a[i];
    FOR(i, n){
        char x; cin >> x;
        s[i] = (x == 'L' ? 0 : 1);
    }
    vector <int> p(n+1), ok(n+1);
    FOR(i, n){
        int l = min(a[i], i);
        int r = max(a[i], i);
        p[l]++;
        p[r]--;
    }
    int cur = 0, invalid_count = 0;
    FOR(i, n){
        cur += p[i];
        if(!cur) ok[i] = 1;
        if(i < n && !ok[i] && !s[i] && s[i+1]) invalid_count++;
    }
    while(q--){
        int pos; cin >> pos;
        s[pos] = (s[pos] == 0 ? 1 : 0);
        if(pos < n && !ok[pos]){
            if(!s[pos] && s[pos+1]){
                invalid_count++;
            }
            else if(s[pos] && s[pos+1]){
                invalid_count--;
            }
        }
        if(1 < pos && !ok[pos-1]){
            if(!s[pos-1] && s[pos]){
                invalid_count++;
            }
            else if(!s[pos-1] && !s[pos]){
                invalid_count--;
            }
        }
        if(invalid_count == 0) cout << "YES\n";
        else cout << "NO\n";
    }
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

