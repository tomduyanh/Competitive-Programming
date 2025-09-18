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

const int N = 3e5 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int n, tr = 0;
ll dp[N];

int bs(int val){
    int lo = 1, hi = 300000, pos = 300000;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(dp[mid] >= val){
            hi = mid - 1;
            pos = mid;
        }
        else lo = mid + 1;
    }
    return pos;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    FOR(i, 300000){
        tr = tr * 2 + i;
        dp[i] = dp[i-1] + tr;
        if(dp[i] < 0) break;
        cout << i << nl;
    }

    int t; cin >> t;
    while(t--){
        int x; cin >> x;
        cout << bs(x) << nl;
    }

    return 0;
}

