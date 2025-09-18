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

int p[N+1];

void sieve(){
    int cnt = 0;
    FOR(i, N - 5) p[i] = i;
    for(int i = 2; i <= N - 5; ++i){
        if(p[i] == i){
            for(int j = 1; i * j <= N - 5; ++j){
                p[i*j] = i;
                ++cnt;
            }
        }
        ++cnt;
    }
    cout << cnt << nl;
    FOR(i, 10) cout << i << sp << p[i] << nl;
}

int res = 0;
map <int, int> mp;

int cnt(int n){
    int ans = 0;
    while(n > 1){
        ans++;
        if(mp[p[n]] == 0) ++res;
        ++mp[p[n]];
        n /= p[n];
    }
    return ans;
}

int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    //freop();
    //srand(time(NULL));

    sieve();
    int sum = 0, mx = 0;
    FOR(i, N-5){
        int val = cnt(i);
        sum += val;
        mx = max(mx, val);
    }
    cout << sum << sp << mx << sp << res;

    return 0;
}


