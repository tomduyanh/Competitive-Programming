#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int,int> pii;
typedef pair <ll , ll> pll;

#define int long long
#define sp " "
#define nl "\n"
#define F first
#define S second
#define PB push_back
#define all(arr) arr.begin(), arr.end()

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen(".INP", "r", stdin);
    freopen(".OUT", "w", stdout);
}

int a[N], n;

void read(){
    cin >> n; n *= 2;
    for(int i = 1; i <= n; ++i) cin >> a[i];
}

void solve(){
    int ans = INF;
    sort(a+1, a+n+1);
    for(int i = 1; i < n; ++i){
        for(int j = i + 1; j <= n; ++j){
            vector <int> arr;
            for(int k = 1; k <= n; ++k){
                if(k == i || k == j) continue;
                arr.PB(a[k]);
            }
            int sum = 0;
            for(int k = 0; k < arr.size(); k += 2){
                sum += abs(arr[k] - arr[k+1]);
            }
            ans = min(ans, sum);
        }
    }
    cout << ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    read();
    solve();

    return 0;
}
