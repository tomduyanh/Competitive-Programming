#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int,int> pii;
typedef pair <ll , ll> pll;

#define int long long
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

int k[N];

int upper(int lo, int hi, int val){
    int ans = k[lo];
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(k[mid] <= val){
            ans = k[mid];
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    return ans;
}

int lower(int lo, int hi, int val){
    int ans = k[lo];
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(k[mid] >= val){
            ans = k[mid];
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    return ans;
}

void sol(){
    int n, m; cin >> n >> m;
    FOR(i, n){
        cin >> k[i];
    }
    sort(k + 1, k + n + 1);
    FOR(i, m){
        int a, b, c; cin >> a >> b >> c;
        int k1 = upper(1, n, b), k2 = lower(1, n, b);
        if((b - k1) * (b - k1) - 4 * a * c < 0){
            cout << "YES\n" << k1 << nl;
        }
        else if((b - k2) * (b - k2) - 4 * a * c < 0) cout << "YES\n" << k2 << nl;
        else cout << "NO\n";
    }
    cout << nl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    int t; cin >> t;
    while(t--) sol();

    return 0;
}

