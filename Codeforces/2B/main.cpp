#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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

const int N = 1e3 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int n;
int a[N][N]; pii pre[N][N][2], dp[N][N][2];
///dp[i][j][k][]
///k = min 2 and 5
int two[N][N], fiv[N][N];

ll exp(ll x, int k){
    x %= MOD;
    ll res = 1;
    while(k > 0){
        if(k % 2 == 1) res = res * x;
        x = x * x;
        k /= 2;
    }
    return res;
}

int get(int val, int num){
    int res = 0;
    for(; res < 30; ++res){
        ll cur = exp((ll)num, res+1);
        if((ll)val % cur != 0) return res;
    }
    return res;
}

void case_zero(pii zero){
    int x = zero.F, y = zero.S;
    cout << 1 << nl;
    for(int i = 1; i < x; ++i) cout << 'D';
    for(int i = 1; i < y; ++i) cout << 'R';
    for(int i = x; i < n; ++i) cout << 'D';
    for(int i = y; i < n; ++i) cout << 'R';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    pii zero;

    cin >> n;
    FOR(i, n){
        FOR(j, n){
            cin >> a[i][j];
            two[i][j] = get(a[i][j], 2), fiv[i][j] = get(a[i][j], 5);
            dp[i][j][0] = dp[i][j][1] = {INF, INF};
            if(a[i][j] == 0) zero = {i, j};
        }
    }


    dp[1][1][0] = {two[1][1], fiv[1][1]};
    dp[1][1][1] = {two[1][1], fiv[1][1]};

    FOR(i, n){
        FOR(j, n){
            int nxt_two, nxt_fiv;
            nxt_two = dp[i][j][0].F + two[i+1][j];
            nxt_fiv = dp[i][j][1].S + fiv[i+1][j];

            if(nxt_two < dp[i+1][j][0].F || (nxt_two == dp[i+1][j][0].F && dp[i][j][0].S + fiv[i+1][j] <= dp[i+1][j][0].S)){
                dp[i+1][j][0] = {nxt_two, dp[i][j][0].S + fiv[i+1][j]};
                pre[i+1][j][0] = {i, j};
            }
            if(nxt_fiv < dp[i+1][j][1].S || (nxt_fiv == dp[i+1][j][1].S && dp[i][j][1].F + two[i+1][j] <= dp[i+1][j][1].F)){
                dp[i+1][j][1] = {dp[i][j][1].F + two[i+1][j], nxt_fiv};
                pre[i+1][j][1] = {i, j};
            }

            nxt_two = dp[i][j][0].F + two[i][j+1];
            nxt_fiv = dp[i][j][1].S + fiv[i][j+1];

            if(nxt_two < dp[i][j+1][0].F || (nxt_two == dp[i][j+1][0].F && dp[i][j][0].S + fiv[i][j+1] <= dp[i][j+1][0].S)){
                dp[i][j+1][0] = {nxt_two, dp[i][j][0].S + fiv[i][j+1]};
                pre[i][j+1][0] = {i, j};
            }
            if(nxt_fiv < dp[i][j+1][1].S || (nxt_fiv == dp[i][j+1][1].S && dp[i][j][1].F + two[i][j+1] <= dp[i][j+1][1].F)){
                dp[i][j+1][1] = {dp[i][j][1].F + two[i][j+1], nxt_fiv};
                pre[i][j+1][1] = {i, j};
            }

        }
    }

    int ans = min({dp[n][n][0].F, dp[n][n][0].S, dp[n][n][1].F, dp[n][n][1].S});

    if(ans > 1 && zero.F > 0){
        case_zero(zero);
        return 0;
    }

    int status = 0;
    if(min(dp[n][n][0].F, dp[n][n][0].S) != ans) status = 1;

    vector <char> steps;
    int x = n, y = n;
    while(!(x == 1 && y == 1)){
        int prex = pre[x][y][status].F;
        int prey = pre[x][y][status].S;
        if(prey - y == 0) steps.PB('D');
        else steps.PB('R');
        x = prex, y = prey;
    }
    reverse(all(steps));
    cout << ans << nl;
    for(auto it : steps) cout << it;

    return 0;
}

