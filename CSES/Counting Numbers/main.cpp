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

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen(".INP", "r", stdin);
    freopen(".OUT", "w", stdout);
}

ll a, b;
ll dp[20][10][2][2];
vector <int> num;

ll DP(int id, int pre, int pos, int zero){
//    cout << id << sp <<  pre << sp << pos << sp << zero << nl;
    if(id == num.size()) return 1;
    if(dp[id][pre][pos][zero] != -1) return dp[id][pre][pos][zero];
    ll ans = 0;
    for(int digit = 0; digit <= (pos == 1 ? num[id] : 9); ++digit){
        if(!zero && digit == pre) continue;
        int nxtid = id + 1, nxtpre = digit, nxtpos = pos, nxtzero = zero;
        if(pos && digit < num[id]) nxtpos = 0;
        if(digit != 0) nxtzero = 0;
        ans = (ans + DP(nxtid, nxtpre, nxtpos, nxtzero));
    }
    return dp[id][pre][pos][zero] = ans;
}

ll solve(ll n){
    num.clear();
    for(; n > 0; n /= 10){
        num.PB(n % 10);
    }
    reverse(all(num));
    memset(dp, -1, sizeof(dp));
//    cout << nl << nl;
    return DP(0,0,1,1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> a >> b;
    if(a == 0) cout << solve(b);
    else cout << solve(b) - solve(a-1);

    return 0;
}

