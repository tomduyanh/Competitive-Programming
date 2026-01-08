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

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int n;
pii a[N];

void solve(){
    ll ans = 0;
    cin >> n;
    FOR(i, n){
        cin >> a[i].F >> a[i].S;
        ans += (a[i].S - a[i].F);
    }

    sort(a+1, a+n+1);

    priority_queue <pll> pq;
    FOR(i, n) pq.push({a[i].S, i});

    map<ll, bool> check;

    for(int i = 1; i <= n && !pq.empty(); ++i){

        int r = pq.top().F, id = pq.top().S; pq.pop();
        while(!pq.empty() && (id == i || check[id]) ){
            if(id == i){
                int tempr = r, tempid = id;
                r = pq.top().F, id = pq.top().S; pq.pop();
                pq.push({r, id});
            }
            else r = pq.top().F, id = pq.top().S; pq.pop();
        }
        if(id == i || check[id]) continue;
        check[id] = true;
        check[i]  = true;
        cout << i << sp << a[i].F << "\t" << id << sp << r << nl;
        ans += (r - a[i].F);
    }
    cout << ans << nl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
