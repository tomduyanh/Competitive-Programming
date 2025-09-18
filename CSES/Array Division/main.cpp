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

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int n, k, a[N];
priority_queue <ll> pq;

bool compare(int a, int b){ return a > b; }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n >> k;
    FOR(i, n) cin >> a[i];
    sort(a+1, a+n+1, compare);
    FOR(i, k) pq.push(-a[i]);
    for(int i = k - 1; i > 0; --i){
        ll val = -pq.top(); pq.pop();
        val += a[i];
        pq.push(-val);
    }
    ll ans = -INF;
    while(!pq.empty()){
        ans = max(ans, -pq.top());
        pq.pop();
    }
    cout << ans;

    return 0;
}

