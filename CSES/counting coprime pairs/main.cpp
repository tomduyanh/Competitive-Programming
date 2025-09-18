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

int n, a[N];
int p[N], cnt[N];

void sieve(){
    FOR(i, N-5) p[i] = i;
    for(int i = 2; i * i <= N-5; ++i) if(p[i] == i) for(int j = i; i * j <= N-5; ++j) p[i*j] = i;
}

void read(){
    cin >> n;
    FOR(i, n) cin >> a[i];
}

void solve(){
    ll ans = 0;
    for(int i = 1; i <= n; ++i){
        vector <int> div; map <int, int> ok;
        while(a[i] > 1){
            if(!ok[p[a[i]]]) div.PB(p[a[i]]);
            ok[p[a[i]]] = 1;
            a[i] /= p[a[i]];
        }
        sort(all(div));
        for(int sub = 0; sub < (1 << div.size()); ++sub){
            int num = 1, dem = 0;
            for(int j = 0; j < div.size(); ++j) if(sub & (1 << j)) num *= div[j], ++dem;
            if(num == 1) continue;
            if(dem & 1) ans += cnt[num];
            else ans -= cnt[num];
            ++cnt[num];
        }
    }
    cout << (ll)n*(n-1)/2 - ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    sieve();
    read();
    solve();

    return 0;
}

