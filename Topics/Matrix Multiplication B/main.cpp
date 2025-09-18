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

int n, mod;
using Matrix = array <array<ll,3>,3>;

Matrix mul(Matrix a, Matrix b){
    Matrix res;
    for(int i = 0; i < 3; ++i) for(int j = 0; j < 3; ++j) res[i][j] = 0;
//    cout << "w";
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            for(int k = 0; k < 3; ++k){
//                cout << a[i][k] << sp << b[k][j] << "\t";
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= mod;
            }
//            cout << res[i][j] << sp;
        }
//        cout << nl;
    }
    /*
    cout << nl;
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j) cout << a[i][j] << sp;
        cout << nl;
    }
    cout << nl;
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j) cout << b[i][j] << sp;
        cout << nl;
    }
    cout << nl;
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j) cout << res[i][j] << sp;
        cout << nl;
    }
    cout << nl << nl;
    */
    return res;
}

Matrix pow(Matrix a, int k){
    Matrix res = a; --k;
    for(; k > 0; k /= 2){
        if(k & 1) res = mul(res, a);
        a = mul(a, a);
    }
    return res;
}

int solve(){
    if(n == 0) return 1 % mod;
    if(n == 1) return 1 % mod;
    if(n == 2) return 2 % mod;
    if(n == 3) return 4 % mod;
    Matrix base = {{
        {1, 1, 1},
        {1, 0, 0},
        {0, 1, 0}
    }};

    base = pow(base, n - 3);
    /*
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j) cout << base[i][j] << sp;
        cout << nl;
    }
    */
    int ans = (base[0][0] * 4 + base[0][1] * 2 + base[0][2]) % mod;

    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n >> mod;

    cout << solve();

    return 0;
}

