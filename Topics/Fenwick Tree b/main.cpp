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

int n, q;
int a[N], diff[N], bit[N];

int get(int p){
    int idx = p, ans = 0;
    while(idx > 0){
        ans += bit[idx];
        idx -= (idx & (-idx));
    }
    return ans;
}

void update(int u, int v) {
    int idx = u;
    while (idx <= n) {
        bit[idx] += v;
        idx += (idx & (-idx));
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n >> q;

    while(q--){
        int type; cin >> type;
        if(type == 1){
            int l, r, d; cin >> l >> r >> d;
            update(l, d);
            update(r + 1, -d);
        }
        else{
            int x; cin >> x;
            cout << get(x) << nl;
        }
    }

    return 0;
}

