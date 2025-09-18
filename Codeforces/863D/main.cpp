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

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int n, q, m;
int a[N], b[N];
struct queries{
    int type, l, r;
}Q[N];

void Reverse(){
    vector <int> x, y, z;
    FOR(i, q) x.PB(Q[i].type), y.PB(Q[i].l), z.PB(Q[i].r);
    reverse(all(x)), reverse(all(y)), reverse(all(z));
    FOR(i, q) Q[i].type = x[i-1], Q[i].l = y[i-1], Q[i].r = z[i-1];
}

void read(){
    cin >> n >> q >> m;
    FOR(i, n) cin >> a[i];
    FOR(i, q) cin >> Q[i].type >> Q[i].l >> Q[i].r;
    FOR(i, m) cin >> b[i];
    Reverse();
}

void solve(){
    FOR(i, q){
        int l = Q[i].l, r = Q[i].r, type = Q[i].type;
        FOR(i, m){
            if(l <= b[i] && b[i] <= r){
                if(type == 1) b[i] = (b[i] == l ? b[i] = r : b[i] = b[i] - 1);
                else b[i] = r - b[i] + l;
            }
        }
    }
    FOR(i, m) cout << a[b[i]] << sp;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    read();
    solve();

    return 0;
}

