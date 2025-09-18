#include <bits/stdc++.h>
using namespace std;

//#define int long long
typedef long long ll;
typedef pair <int,int> pii;
typedef pair <ll , ll> pll;

#define sp " "
#define nl "\n"
#define all(x) x.begin(), x.end()
#define PB push_back
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define FORR(i, n) for(int i = n; i > 0; --i)

const int N = 1e2 + 1;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int n;
int a[N];
int dp[N][(int)(1<<17) + 1], pre[N][(int)(1<<17) + 1], num[N][(int)(1<<17) + 1];
int pr[17] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};

int getmask(int k){
    int mask = 0;
    for(int j = 0; j < 17; ++j) if(k % pr[j] == 0) mask |= (1 << j);
    return mask;
}

int findpos(int ans){
    for(int sub = 0; sub < (1 << 17); ++sub) if(dp[n][sub] == ans) return sub;
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

//    /*
    cin >> n;
    FOR(i, n) cin >> a[i];
    for(int i = 1; i <= 100; ++i) for(int j = 0; j <= (int)(1<<17); ++j) dp[i][j] = 1000000000;
    for(int i = 1; i <= n; ++i){
        for(int k = 1; k < 60; ++k){
            int mask = getmask(k);
            for(int sub = 0; sub < (1 << 17); ++sub){
                if((sub & mask)) continue;
                if(dp[i][mask | sub] >= dp[i-1][sub] + abs(a[i] - k)){
                    dp[i][mask | sub] = dp[i-1][sub] + abs(a[i] - k);
                    num[i][mask | sub] = k;
                    pre[i][mask | sub] = sub;
                }
            }
        }
    }
    int ans = *min_element(dp[n], dp[n]+(1<<17)+1);
    int pos = findpos(ans);
    vector <int> res;
//    cout << pos << nl;
//    cout << pre[n][pos] << nl;

    res.PB(num[n][pos]);

    for(int i = n; i > 1; --i){
        pos = pre[i][pos];
        res.PB(num[i-1][pos]);
    }
    reverse(all(res));
    for(auto it : res) cout << it << sp;

    return 0;
}
