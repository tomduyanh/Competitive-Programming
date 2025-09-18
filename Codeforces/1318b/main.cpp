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

const int N = 4e3 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int n, m;
int a[N], s[N];
bool dp[N];

void sol(){
    cin >> n;
    n *= 2, m = 0;

    FOR(i, n){
        cin >> a[i];
        s[i] = 0;
    }

    for(int i = n, pre = n; i > 0; --i){
        bool ok = 1;
        for(int j = 1; j <= i; ++j) if(a[j] > a[i]) ok = 0;
        if(!ok) continue;
        s[++m] = pre - i + 1;
        pre = i - 1;
    }

    FOR(i, n) dp[i] = 0;
    dp[0] = 1;
    FOR(i, m) FORR(j, n) if(j - s[i] >= 0) dp[j] = dp[j] | (dp[j - s[i]]);
    if(dp[n/2]) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    int q; cin >> q;
    while(q--) sol();

    return 0;
}


