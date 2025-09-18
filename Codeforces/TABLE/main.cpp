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

const int N = 4e2 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen("TABLE.INP", "r", stdin);
    freopen("TABLE.OUT", "w", stdout);
}

int n, m;
int a[N][N], s[N][N];

void read(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j){
            char x; cin >> x;
            a[i][j] = (x == '.' ? 1 : 0);
        }
}

void solve(){
    for(int j = 1; j <= m; ++j)
        for(int i = 1; i <= n; ++i)
            if(a[i][j])
                s[i][j] = s[i-1][j] + a[i][j];
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(!a[i][j]) continue;
            int len = 1;
            for(int k = j - 1; k > 0; --k)
                if(s[i][k] < s[i][j]) break;
                else ++len;
            for(int k = j + 1; k <= m; ++k)
                if(s[i][k] < s[i][j]) break;
                else ++len;
            ans = max(ans, (len + s[i][j]) * 2 - 1);
        }
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freop();
    //srand(time(NULL));

    read();
    solve();

    return 0;
}

