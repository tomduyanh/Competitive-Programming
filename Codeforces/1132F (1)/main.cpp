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

const int N = 500 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e9;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int n; string s;
int dp[N][N];
bool vis[N][N];

int sol(int l, int r){
//    cout << l << sp << r << nl;
    if(l > r) return 0;
    if(l == r) return dp[l][r] = 1;
    if(vis[l][r]) return dp[l][r];
    vis[l][r] = 1;
    int ans=1+sol(l+1,r);
    for(int i = l+1; i <= r; ++i) if(s[l] == s[i])ans = min(ans, sol(l+1,i-1) + sol(i ,r));
    dp[l][r] = ans;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n >> s;
    cout << sol(0,n-1);

    return 0;
}

