#include <bits/stdc++.h>
using namespace std;

#define int long long
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
#define FORR(i, n) for(int i = n; i > 0; --i)

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int get(int lo, int hi){
    return (rand() % (hi - lo + 1) + lo);
}

struct Num{
    int x, y, w;
}arr[N];
int n;
bool compare(Num a, Num b) {return a.x < b.x;}

int trau(){
    int ans = 0;
    sort(arr+1,arr+n+1,compare);
    for(int sub = 1; sub < (1 << n); ++sub){
        int cost = 0, pre = 0;
        for(int i = 0; i < n; ++i){
            if(sub & (1 << i)){
                cost += (arr[i+1].x - pre) * arr[i+1].y - arr[i+1].w;
                pre = arr[i+1].x;
            }
        }
        if(cost == 7731) cout << sub << nl;
        ans = max(ans, cost);
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    srand(time(NULL));

    n = 25;
    int prea = 1, preb = 126;
    cout << n << nl;
    for(int i = 1, j = n; i <= n; ++i, --j){
        int a = get(prea+1, i*5), b = get(j*5, preb-1), c = get(1, 100);
        prea = a, preb = b;
        cout << a << sp << b << sp << c << nl;
        arr[i].x = a, arr[i].y = b, arr[i].w = c;
    }
    cout << trau();

    return 0;
}

