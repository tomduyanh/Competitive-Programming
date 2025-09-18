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
ll s[N];

bool solve(){
    cin >> n;
    FOR(i, n) cin >> a[i];
    if(n == 1 && a[1] != 1) return false;
    sort(a+1,a+n+1);
    s[0] = 0;
    FOR(i, n) s[i] = s[i-1] + a[i];
    for(int i = 2; i <= n; ++i){
        if(a[i] > s[i-1]) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    int t; cin >> t;
    while(t--){
        if(solve()) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}

