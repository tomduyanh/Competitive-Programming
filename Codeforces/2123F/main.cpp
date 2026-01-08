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

int p[N], a[N], ans[N];
vector <int> adj[N];

int getMaxPrime(int n){
    while(p[n] != 0){
        n /= p[n];
    }
    return n;
}

void Sieve(){
    p[0] = p[1] = 0;
    for(int i = 2; i*i <= 100000; ++i){
        if(!p[i]) for(int j = i; i*j <= 100000; ++j) p[i*j] = i;
    }
    for(int i = 1; i <= 100000; ++i){
        a[i] = getMaxPrime(i);
    }
}

void solve(){
    int n; cin >> n;
//    vector <int> ans(n+5);
    vector <int> primes;
    int mx = 0;
    FOR(i, n){
        adj[a[i]].PB(i);
        if(a[i] != 0 && mx < a[i]){
            mx = max(mx, a[i]);
            primes.PB(a[i]);
        }
    }
    for(auto pr : primes){
        for(int i = 0; i < adj[pr].size() - 1; ++i){
            int temp = adj[pr][i+1];
            ans[adj[pr][i]] = temp;
        }
        ans[adj[pr][adj[pr].size()-1]] = adj[pr][0];
    }
    for(int i = 1; i <= n; ++i) cout << ans[i] << sp;
    cout << nl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    Sieve();
//    FOR(i, 10){
//        cout << i << sp << a[i] << nl;
//    }
    int t; cin >> t;
    while(t--) solve();

    return 0;
}

