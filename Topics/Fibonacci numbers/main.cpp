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
int a[N], b[N], c[N];

bool valid(){
    for(int i = 1; i <= n; ++i)
        if((c[i] == 1 && c[i] == 1) || (c[i] == 2)) return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];
    reverse(a+1, a+n+1), reverse(b+1, b+n+1);
    for(int i = 1; i <= n; ++i) c[i] = a[i] + b[i];
    for(int i = 1; i <= n; ++i) cout << c[i] << sp;
    cout << nl;
    int mx = n, cnt = 0;
    while(! valid()){
        for(int i = n; i > 0; --i){
            if(c[i] == 2) c[i-2]++, c[i+1]++, c[i] = 0, mx = max(mx, i+1);
            if(c[i] == 1 && c[i-1] == 1) c[i+1]++, c[i] = 0, mx = max(mx, i+1);
        }
        ++cnt;
        if(cnt > 6) break;
        for(int i = 1; i <= mx; ++i) cout << c[i] << sp;
        cout << nl;
    }
    for(int i = 1; i <= mx; ++i) cout << c[i] << sp;

    return 0;
}
