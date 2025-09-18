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

const int N = 5e3 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int n;
int a[N];
bool vis[N][N];
int dp[N][N];

int solve(int l, int r){
    if(vis[l][r]) return dp[l][r];
    vis[l][r] = true;
    if(l >= r)  return dp[l][r];
    solve(l+1, r);
    solve(l, r-1);
    if(a[l] == a[r]) dp[l][r] = solve(l+1, r-1) + 1;
    else dp[l][r] = min(solve(l+1,r), solve(l,r-1)) + 1;
    return dp[l][r];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n;
    FOR(i, n) cin >> a[i];

    vector <int> arr;
    FOR(i, n) if(!arr.size() || a[i] != arr[arr.size()-1]) arr.PB(a[i]);
    n = arr.size();
    FOR(i, n) a[i] = arr[i-1];

    cout << solve(1, n);
//    cout << nl;
//    FOR(i, n) cout << a[i] << sp;
//    cout << nl;
//    cout << nl << dp[2][n];

    return 0;
}

