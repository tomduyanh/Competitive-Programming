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

const int N = 5e2 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int n, k;
int a[N], dp[N][N];
bool ok[N][N], vis[N][N], mark[N], yes[N];

void read(){
    cin >> n >> k;
    FOR(i, n) cin >> a[i];
    sort(a+1,a+n+1);
}

void trace(int idx, int sum){
    cout << nl;
    queue <pii> q;
    q.push({idx, sum});
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j <= k; ++j) vis[i][j] = false;
        mark[i] = false;
    }
    while(!q.empty()){
        int id = q.front().F, s = q.front().S;
        q.pop();

        if(vis[id][s]) continue;
        cout << id << sp << s << nl;
        vis[id][s] = true;
        mark[id] = true;

        for(int i = 1; i < id; ++i){
            int nxt_id = i;
            int nxt_s = s - a[i];
            if(nxt_s < 0) continue;
            if(!ok[nxt_id][s]) continue;
            q.push({nxt_id, nxt_s});
        }
    }

    for(int i = 1; i <= n; ++i) for(int j = 0; j <= k; ++j) dp[i][j] = 0;
    dp[0][0] = 1;
    cout << nl;
    FOR(i, n) if(mark[i]) cout << a[i] << sp;
    cout << nl;
    vector <int> arr; arr.PB(0);
    FOR(i, n) if(mark[i]) arr.PB(a[i]);
    for(int i = 1; i <= arr.size(); ++i){
        for(int j = 0; j <= k; ++j){
            dp[i][j] = dp[i-1][j];
            if(j - arr[i] >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j-arr[i]]);
            if(j == 14){
                if(dp[i][j] == 1) cout << "guys " << i << nl;
            }
        }
    }
    for(int j = 0; j <= k; ++j){
        if(dp[arr.size()][j] == 1) yes[j] = 1;
        if(j == 14 && yes[j]) cout << "this " << idx << sp << sum << nl;
    }
}

void solve(){
    dp[0][0] = 1;
    ok[0][0] = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j <= k; ++j){
            dp[i][j] = dp[i-1][j];
            if(j - a[i] >= 0){
                dp[i][j] = max(dp[i-1][j-a[i]], dp[i][j]);
                if(dp[i-1][j-a[i]] == 1) ok[i][j] = 1;
            }
        }
        if(ok[i][k]) trace(i, k - a[i]);
    }
    cout << nl;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j <= k; ++j) if(ok[i][j]) cout << i << sp << j << nl;
        cout << nl;
    }
    for(int j = 0; j <= k; ++j) if(yes[j]) cout << j << sp;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    read();
    solve();

    return 0;
}


