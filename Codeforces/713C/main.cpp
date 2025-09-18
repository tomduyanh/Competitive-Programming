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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    int n, a;
    cin >> n >> a;
    priority_queue <int> pq;
    pq.push(a);
    ll ans = 0;
    for(int i = 1; i < n; ++i){
        cin >> a;
//        a -= i;
        pq.push(a);
        if(pq.top() > a){
            ans += pq.top() - a;
            pq.pop();
            pq.push(a);
        }
    }
    cout << ans;

    return 0;
}

