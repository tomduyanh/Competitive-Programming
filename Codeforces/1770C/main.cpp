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
int a[N];

bool solve(){
    cin >> n;
    FOR(i, n) cin >> a[i];
    FOR(i, n) FOR(j, n) if(i != j && a[i] == a[j]) return false;
    int cnto = 0, cnte = 0;
    FOR(i, n)
        if(a[i] % 2 == 0) ++cnte;
        else ++cnto;
    if(cnto >= 2 && cnte >= 2) return false;
    return true;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    int t; cin >> t;
    while(t--){
        if(solve()) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}

