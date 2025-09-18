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

int n, k;
int a[N], b[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n >> k;
    FOR(i, n){
        char x; cin >> x;
        a[i] = x - '0';
    }
    bool inc = false;
    for(int i = k; i > 0; --i){
        for(int j = 1; i + j * k <= n; ++j){
            if(a[i] < a[i + j * k]){
                inc = true;
                break;
            }
        }
        for(int j = 0; i + j * k <= n; ++j){
            b[i + j * k] = (inc ? a[i] + 1 : a[i]);
        }
        if(inc){
            for(int pos = i + 1; pos <= k; ++pos){
                for(int j = 0; i + j * k <= n; ++j) b[pos + j * k] = 0;
            }
            for(--i; i > 0; --i){
                for(int j = 0; i + j * k <= n; ++j){
                    b[i + j * k] = a[i];
                }
            }
        }
    }
    cout << n << nl;
    FOR(i, n) cout << b[i];

    return 0;
}
