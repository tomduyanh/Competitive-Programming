#include <bits/stdc++.h>
using namespace std;

#define sp " "
#define nl "\n"
#define int long long
#define PB push_back

typedef long long ll;

const int MOD = 1e9+7;

int n, k, m = 101, d[105];
int f[105];

using matrix = array<array<ll,105>,105>;

void debug(matrix base){
    cout << "debug: \n";
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < m; ++j) cout << base[i][j] << sp;
        cout << nl;
    }
    cout << nl;
}

matrix mul(matrix a, matrix b){
    matrix ans;
    for(int i = 0; i < m; ++i) for(int j = 0; j < m; ++j) ans[i][j] = 0;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < m; ++j){
            for(int h = 0; h < m; ++h){
                ans[i][j] += a[i][h] * b[h][j];
                ans[i][j] %= MOD;
            }
        }
    }
    return ans;
}

matrix pow(matrix a, int x){
    matrix ans = a;
    for(--x; x > 0; x /= 2){
        if(x & 1) ans = mul(a, ans);
        a = mul(a, a);
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        int x; cin >> x;
        ++d[x];
    }

    f[0] = 1, d[0] = 1;
    for(int s = 1; s <= m-1; ++s){
        for(int j = 1; j <= s; ++j){
            f[s] += f[s-j] * d[j];
            f[s] %= MOD;
        }
    }

    vector <int> init; init.PB(1);
    for(int i = 1; i <= m-1; ++i){
        init[0] += f[i];
        init[0] %= MOD;
    }

    if(k <= m-1){
        int ans = 1;
        for(int i = 1; i <= k; ++i){
            ans += f[i];
            ans %= MOD;
        }
        cout << ans;
        return 0;
    }

    for(int i = m-1; i > 0; --i) init.PB(f[i]);
    matrix base;

    for(int i = 0; i < m; ++i) for(int j = 0; j < m; ++j) base[i][j] = 0;

    base[0][0] = 1;
    for(int j = 1; j < m; ++j) base[0][j] = base[1][j] = d[j];
    for(int i = 2; i < m; ++i) base[i][i-1] = 1;

    base = pow(base, k - m + 1  );
    int ans = 0;

    for(int i = 0; i < m; ++i){
        ans += base[0][i] * init[i];
        ans %= MOD;
    }
    cout << ans;

    return 0;
}
