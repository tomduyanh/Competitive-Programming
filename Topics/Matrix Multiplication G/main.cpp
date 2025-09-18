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
const int MOD = 1e9 + 9;
const ll INF = 1e18;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int n, m, f[4][4];
pii mo[4] = { {-1, -2} , {+1, -2} , {-2, -1} , {+2, -1} };
using matrix = array<array<ll,9>,9>;

void debug(matrix a){
    cout << "debug: \n";
    FOR(i, 2*m){
        FOR(j, 2*m) cout << a[i-1][j-1] << sp;
        cout << nl;
    }
    cout << nl;
}

bool valid(int x, int y, int xx, int yy){
    for(int i = 0; i < 4; ++i) if(xx + mo[i].F == x && yy + mo[i].S == y) return true;
    return false;
}

matrix buildbase(matrix a){
    for(int i = 0; i < m; ++i) a[i][m+i] = 1;
    for(int i = m; i < 2*m; ++i){
        for(int j = 0; j < m; ++j){
            int pre_x = j, pre_y = j - 2;
            int cur_x = i - m, cur_y = j;
            if(!valid(pre_x, pre_y, cur_x, cur_y)) a[i][j] = 1;
        }
        for(int j = m; j < 2*m; ++j){
            int pre_x = j - m, pre_y = j - 1;
            int cur_x = i - m, cur_y = j;
            if(!valid(pre_x, pre_y, cur_x, cur_y)) a[i][j] = 1;
        }
    }
    return a;
}

matrix mul(matrix a, matrix b){
    matrix ans;
    FOR(i, 2*m) FOR(j, 2*m) ans[i-1][j-1] = 0;
    for(int i = 0; i < 2*m; ++i){
        for(int j = 0; j < 2*m; ++j){
            for(int h = 0; h < 2*m; ++h){
                ans[i][j] += a[i][h] * b[h][j];
                ans[i][j] %= MOD;
            }
        }
    }
    return ans;
}

matrix mul(matrix a, int x){
    matrix ans = a;
    for(--x; x > 0; x /= 2){
        if(x & 1) ans = mul(ans, a);
        a = mul(a, a);
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> m >> n;

    matrix base;
    FOR(i, 2*m) FOR(j, 2*m) base[i-1][j-1] = 0;
    base = buildbase(base);
//    debug(base);
    vector <int> init(2*m);
    for(int j = 0; j < m; ++j) f[j][0] = 1;
    for(int j = 0; j < m; ++j) for(int jj = 0; jj < m; ++jj) if(!valid(jj, 0, j, 1)) f[j][1] += f[jj][0];

    base = pow(base, n-2);


    return 0;
}

