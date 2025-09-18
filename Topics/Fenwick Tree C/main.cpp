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

int n, v = 0;
int a[N], bit[N];

void read(){
    cin >> n;
    FOR(i, n) cin >> a[i];
}

void comp(){
    map <int, int> mp;
    FOR(i, n) ++mp[a[i]];
    for(auto it : mp) mp[it.F] = ++v;
    FOR(i, n) a[i] = mp[a[i]];
}

int get(int p){
    int idx = p, ans = 0;
    while(idx > 0){
        ans += bit[idx];
        idx -= (idx & (-idx));
    }
    return ans;
}

void upd(int u, int v){
    int idx = u;
    while(idx <= n){
        bit[idx] += v;
        idx += (idx & (-idx));
    }
}

void solv(){
    ll ans = 0;
    for(int i = n; i > 0; --i){
        ans += get(a[i] - 1);
        upd(a[i], 1);
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    read();
    comp();
    solv();

    return 0;
}

