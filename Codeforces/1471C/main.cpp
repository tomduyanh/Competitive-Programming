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
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int n, m;
int a[N], b[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 1; i <= n; ++i) cin >> a[i];
        for(int i = 1; i <= m; ++i) cin >> b[i];
        sort(a+1, a+n+1);
        ll ans = 0;
        map <int, bool> bought;
        int lo = 1;
        for(int i = n; i > 0; --i){
            int pos = a[i];
            if(b[lo] < b[pos] && !bought[lo]){
                ans += b[lo];
                bought[lo] = true;
                ++lo;
            }
            else{
                ans += b[pos];
            }
        }
        cout << ans << nl;
    }

    return 0;
}

