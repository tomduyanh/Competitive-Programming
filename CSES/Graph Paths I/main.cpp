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

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int n, m, k;
using Matrix = array<array<ll,105>,105>;

Matrix mul(Matrix a, Matrix b){
    Matrix ans;
    FOR(i, n) FOR(j, n) ans[i-1][j-1] = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            for(int k = 0; k < n; ++k){
                ans[i][j] += a[i][k] * b[k][j];
                ans[i][j] %= MOD;
            }
        }
    }
    return ans;
}

Matrix pow(Matrix a, int k){
    Matrix ans = a; --k;
    for(; k > 0; k /= 2){
        if(k & 1) ans = mul(ans, a);
        a = mul(a, a);
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    vector <int> init(105);
    Matrix base;

    cin >> n >> m >> k;
    FOR(i, n) FOR(j, n) base[i-1][j-1] = 0;
    FOR(i, m){
        int x, y; cin >> x >> y;
        base[y-1][x-1]++;
    }

    init[0] = 1;
    base = pow(base, k);

    int ans = 0;
    for(int j = 0; j < n; ++j){
        ans += init[j] * base[n-1][j];
        ans %= MOD;
    }
    cout << ans;

    return 0;
}
