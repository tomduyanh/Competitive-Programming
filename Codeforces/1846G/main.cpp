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

const int N = 10;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int n, m;
int dp[1001][1 << N];
struct ARR{
    string x, y;
    int days, nxt_symp, med;
}a[1001];

int solve(){
    cin >> n >> m;
    string s; cin >> s;
    FOR(i, m){
        cin >> a[i].days >> a[i].x >> a[i].y;
        a[i].med = a[i].nxt_symp = 0;
    }

    int cur_symp = 0;
    FOR(i, n) if(s[i-1] == '1') cur_symp += (1 << (i - 1));
    FOR(i, m)
        FOR(j, n){
            if(a[i].x[j-1] == '1') a[i].med |= (1 << (j - 1));
            if(a[i].y[j-1] == '1') a[i].nxt_symp |= (1 << (j - 1));
        }

    for(int i = 0; i <= m; ++i) for(int j = 0; j < (1 << n); ++j) dp[i][j] = INF;

    priority_queue <pair<int,pair<int,int>>> pq; ///dp, mask, idx
    pq.push({0, {cur_symp, 0}});
    dp[0][cur_symp] = 0;
    while(!pq.empty()){
        int val = -pq.top().F, mask = pq.top().S.F, idx = pq.top().S.S; pq.pop();
        if(val != dp[idx][mask]) continue;
        FOR(i, m){
            int nxt_mask = mask, med = a[i].med, nxt_symp = a[i].nxt_symp, day = a[i].days;

            nxt_mask |= med;
            nxt_mask ^= med;
            nxt_mask |= nxt_symp;

            if(val + day < dp[i][nxt_mask]){
                dp[i][nxt_mask] =  val + day;
                pq.push({-dp[i][nxt_mask], {nxt_mask, i}});
            }
        }
    }
    int ans = INF;
    for(int i = 0; i <= m; ++i) ans = min(ans, dp[i][0]);
    if(ans != INF) return ans;
    return -1;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    int t; cin >> t;
    while(t--){
        cout << solve() << nl;
    }

    return 0;
}
