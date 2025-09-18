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

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen(".INP", "r", stdin);
    freopen(".OUT", "w", stdout);
}

int n, q;
int tree[2*N];
map <int,int> mp;

void add(int k, int x){
    k += n; tree[k] = x;
    for(k /= 2; k > 0; k /= 2){
        tree[k] = min(tree[k*2], tree[k*2+1]);
    }
}

int query(int l, int r){
    l += n, r += n;
    int ans = (int)1e9+1;
    while(l <= r){
        if(l % 2 == 1) ans = min(ans, tree[l++]);
        if(r % 2 == 0) ans = min(ans, tree[r--]);
        l /= 2, r /= 2;
    }
    return ans;
}

int Count(int l, int r){
    l += n, r += n;
}

void solve(){
    cin >> n >> q;
    for(int i = 0; i <= 2*n; ++i) tree[i] = (int)1e9+1;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        add(i, x);
        ++mp[x];
    }
    while(q--){
        int type; cin >> type;
        if(type == 1) {
            int pos, val; cin >> pos >> val;
            --mp[tree[pos+n]];
            ++mp[val];
            add(pos, val);
        }
        if(type == 2){
            int l, r; cin >> l >> r;
            int ans = query(l, r);
            int cnt = Count(l, r);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    solve();

    return 0;
}
