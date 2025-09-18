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

using Matrix = array<array<ll,2>,2>;

Matrix mul(Matrix a, Matrix b, int check){
    Matrix res = {{{0, 0}, {0, 0}}};
    for(int i = 0; i < 2;  ++i){
        for(int j = 0; j < 2; ++j){
            for(int k = 0; k < 2; ++k){
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= MOD;
            }
        }
    }
    return res;
}

Matrix pow(Matrix a, int n){
    Matrix ans;
    ans = a; --n;
    for(; n > 0; n /= 2){
        if(n & 1) ans = mul(ans, a, 0);
        a = mul(a, a, 0);
    }
    return ans;
}

int solve(){
    int n; cin >> n;
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(n == 2) return 3;
    Matrix base = {{
        {1, 2},
        {1, 0}
    }}
    ;
    Matrix mat = pow(base, n - 2);

//    for(int i = 0; i < 2; ++i){
//        for(int j = 0; j < 2; ++j) cout << mat[i][j] << sp;
//        cout << nl;
//    }
    int ans = (3LL * mat[0][0] + 1LL * mat[0][1]) % MOD;
    return ans;
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    int t = 1; cin >> t;
    while(t--){
        cout << solve() << nl;
    }

    return 0;
}

