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

const int N = 5e3 + 1;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen("ITABLE.INP", "r", stdin);
    freopen("ITABLE.OUT", "w", stdout);
}

int n, t, q;
int arr1[2][N][N], cnt1[2][N][N]; int a[N][N];
int arr2[2][N][N], cnt2[2][N][N];
///cnt1[i][0] = row
///cnt1[i][1] = column

void read(){
    cin >> n >> t;
    FOR(i, t){
        int k, rc, x, y; cin >> k >> rc >> x >> y;
        int mid = (x + y) / 2;
        if(k == 1){ ///row
            ///tang dan
            arr1[k-1][rc][x] -= (x - 1);
            arr1[k-1][rc][mid+1] += (x - 1);
            cnt1[k-1][rc][x] += 1;
            cnt1[k-1][rc][mid+1] -= 1;
            ///giam dan
            arr2[k-1][rc][y] -= (n - y);
            arr2[k-1][rc][mid] += (n - y);
            cnt2[k-1][rc][y] += 1;
            cnt2[k-1][rc][mid] -= 1;
        }
        else{ ///col
            ///tang dan
            arr1[k-1][x][rc] -= (x - 1);
            arr1[k-1][mid+1][rc] += (x - 1);
            cnt1[k-1][x][rc] += 1;
            cnt1[k-1][mid+1][rc] -= 1;
            ///giam dan
            arr2[k-1][y][rc] -= (n - y);
            arr2[k-1][mid][rc] += (n - y);
            cnt2[k-1][y][rc] += 1;
            cnt2[k-1][mid][rc] -= 1;
        }
    }
}

void construct(){
    ///solve for row
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            arr1[0][i][j] += arr1[0][i][j-1];
            cnt1[0][i][j] += cnt1[0][i][j-1];
            arr1[1][i][j] += arr1[1][i-1][j];
            cnt1[1][i][j] += cnt1[1][i-1][j];
            a[i][j] += (ll)arr1[1][i][j] + (ll)i * cnt1[1][i][j] + (ll)arr1[0][i][j] + (ll)j * cnt1[0][i][j];
        }
    }
    ///solve for col
    for(int j = n; j >= 1; --j){
        for(int i = n; i >= 1; --i){
            arr2[1][i][j] += arr2[1][i+1][j];
            cnt2[1][i][j] += cnt2[1][i+1][j];
            arr2[0][i][j] += arr2[0][i][j+1];
            cnt2[0][i][j] += cnt2[0][i][j+1];
            a[i][j] += (ll)arr2[0][i][j] + (ll)(n - j + 1) * cnt2[0][i][j] + (ll)arr2[1][i][j] + (ll)(n - i + 1) * cnt2[1][i][j];
        }
    }
}

void solve(){
    cin >> q;
    while(q--){
        int x, y; cin >> x >> y;
        cout << a[x][y] << nl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   freop();
    //srand(time(NULL));

    read();
    construct();
    solve();

    return 0;
}

