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

const int N = 5e2 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int n, a[N];
int dp[N][N];

void read(){
    cin >> n;
    FOR(i, n){
        char x; cin >> x;
        a[i] = x - 'a' + 1;
    }
}

int solve(int l, int r){
    if(l == r) return dp[l][r] = 1;
    if(r < l) return dp[l][r] = 0;
    if(dp[l][r] != -1) return dp[l][r];
    int ans = (r - l + 1);
    map <int, int> check;
    for(int i = l; i <= r; ++i) ++check[a[i]];
    for(int k = 1; k <= 26; ++k){ ///xet ky tu
        if(!check[k]) continue; ///kiem tra ky x co thuoc doan [l,r] khong
        vector <pii> pos; ///vecto luu cac doan [u,v]
        for(int i = l; i <= r; ++i){
            if(a[i] != k){
                int nxtL = i, nxtR = i;
                while(a[nxtR+1] != k && nxtR < r) ++nxtR;
                pos.PB({nxtL, nxtR});
                i = nxtR;
            }
        }
        int cur = 1;
        if(pos.size()){
            for(auto it : pos){
                cur += solve(it.F, it.S);
            }
        }
        ans = min(ans, cur);
    }
    dp[l][r] = ans;
    return dp[l][r];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    read();
    memset(dp, -1, sizeof(dp));
    cout << solve(1, n);

    return 0;
}

