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
#define FORR(i, n) for(int i = n; i > 0; --i)

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int n, h, k;
using matrix = array<array<ll,105>,105>;


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n >> h >> k;

    matrix base;

    FOR(i, n) FOR(j, n) base[i-1][j-1] = 0;
    for(int i = 0; i < n; ++i){
        for(int x = -k; x <= k; ++x){
            int j = i + x;
            if(-1 < j && j < n) base[i][j] = 1;
        }
    }
    FOR(i, n){
        FOR(j, n) cout << base[i-1][j-1] << sp;
        cout << nl;
    }

    return 0;
}

