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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    map <int, int> mp;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    sort(a+1, a+n+1);
    for(int i = 1; i <= n; ++i) {
        int x = a[i];
        if(mp[x-1] == 0 && x != 1) mp[x-1] = 1;
        else if(mp[x] == 0) mp[x] = 1;
        else if(mp[x+1] == 0) mp[x+1] = 1;
    }
    int ans = 0;
    for(int i = 1; i <= 150001; ++i) ans += mp[i];
    cout << ans;

    return 0;
}

