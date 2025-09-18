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

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int n;
int a[N];
ll s[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    int ans = 0;
    for(int i = 1; i <= n; ++i){
        s[i] = s[i-1];
        if(a[i] > 0){
            s[i] += a[i];
            ans++;
        }
    }

    for(int i = n; i > 0; --i){
        if(a[i] < 0 && s[i] + a[i] >= 0){
            ++ans;
            s[i-1] += a[i];
        }
        s[i-1] = min(s[i], s[i-1]);
    }
    cout << ans;

    return 0;
}
