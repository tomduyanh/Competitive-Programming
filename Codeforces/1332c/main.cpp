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

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int a[N];
int res[N][30];
int par[N], sz[N];

int root(int node){
    while(node != par[node]) node = par[node];
    return node;
}

void unite(int x, int y){
    x = root(x), y = root(y);
    if(x == y) return;
    if(sz[x] < sz[y]) swap(x, y);
    par[y] = x;
}

int solve(int node){
    int sum = 0, mx = 0;
    for(int i = 1; i <= 28; ++i){
        sum += res[node][i];
        mx = max(mx, res[node][i]);
    }
    return sum - mx;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    int t; cin >> t;
    while(t--){
        int n, k; string s; cin >> n >> k >> s;
        int ans = 0;
        for(int i = 0; i < n; ++i){
            a[i+1] = s[i] - 'a' + 1;
            par[i+1] = i + 1;
            sz[i+1] = 1;
            for(int j = 1; j <= 28; ++j) res[i][j] = 0;
        }
        int cnt = 0;
        for(int i = 1; i <= (n - k); ++i){
            if(par[i] != i) continue;
            for(int j = 1; i + j * k <= n; ++j){
                par[i+j*k] = i;
                ++sz[i];
                ++cnt;
            }
        }
        for(int i = 1, j = n; i <= (int)n/2; ++i, --j){
            if((j - i) % k == 0) continue;
            unite(i, j);
        }
        for(int i = 1; i <= n; ++i){
            ++res[root(i)][a[i]];
        }
        for(int i = 1; i <= n; ++i){
            if(root(i) != i) continue;
            ans += solve(i);
        }
        cout << ans << nl;
    }

    return 0;
}
