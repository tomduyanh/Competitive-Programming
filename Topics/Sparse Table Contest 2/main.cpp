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

const int N = 1e5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int n, k;
int lg[N + 1];
int a[N + 1];
int st[21][N + 1];

void read(){
    cin >> n >> k;
    FOR(i, n) cin >> a[i];
}

void preCom(){
    for(int i = 2; i <= N; ++i) lg[i] = lg[i / 2] + 1;
    for(int i = 1; i <= n; ++i) st[0][i] = a[i];
    for(int j = 1; j <= 20; ++j){
        for(int i = 1; i + (1 << j) <= n + 1; ++i){
            st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
        }
    }
}

int getMax(int lo, int hi){
    int LG = lg[hi - lo + 1];
    return max( st[LG][lo] , st[LG][hi - (1 << LG) + 1] );
}

void solve(){
    for(int i = 1; i <= n; ++i){
        int ans = 0;
        int lo = 1, hi = i, posl = i;
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            int val = getMax(mid, i);
            if(val <= a[i] + k){
                posl = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        lo = i, hi = n;
        int posr = i;
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            int val = getMax(i, mid);
            if(val <= a[i] + k){
                posr = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        ans = posr - posl + 1;
        cout << ans  << sp;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    read();
    preCom();
    solve();

    return 0;
}


