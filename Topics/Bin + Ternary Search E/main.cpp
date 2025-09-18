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

int n, k, a[N];
int pre[N]; pii mx[N]; bool ok[N];

void debug(){
    cout << nl;
    FOR(i, 2*n*k) cout << a[i] << sp;
    cout << nl;
    FOR(i, 2*n*k) cout << mx[i].F << sp;
    cout << nl;
    FOR(i, 2*n*k) cout << mx[i].S << sp;
    cout << nl;
    FOR(i, 2*n*k) cout << ok[i]  << sp;
    cout << nl;

}

bool valid(int val){
    FOR(i, 2*n*k) mx[i].F = mx[i].S = ok[i] = 0;

    for(int i = 2; i <= 2*n*k; ++i){

        mx[i].F = mx[i-1].F;
        mx[i].S = mx[i-1].S;
        if(ok[i-1]){
            mx[i].S = i-1;
        }

        if(a[i] - a[i-1] <= val && ((mx[i-2].F + 1 > mx[i-1].F) || (mx[i-2].F + 1 == mx[i-1].F && mx[i-2].S < mx[i].S))){
            mx[i].F = mx[i-2].F + 1;
            mx[i].S = mx[i-2].S;
            if(ok[i-2]) mx[i].S = i-2;
            ok[i] = true;
        }

    }

    debug();

    int pos = -1;
    FOR(i, 2*n*k)
        if(mx[i].F >= n){
            pos = i;
            break;
        }
    if(pos == -1) return false;

    cout << "w " << pos << sp << mx[pos].S << nl;
    int cur = 2*n*k - pos - 2*(k-1);
    if(cur < 0) return false;
//    cout << pos << sp << cur << nl;
    while(mx[pos].S != 0){
        cur = cur + pos - mx[pos].S - 2 - 2*(k-1);
        cout << mx[pos].S << sp << pos << sp << cur << nl;
        if(cur < 0) return false;
        pos = mx[pos].S;
    }

    return true;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n >> k;
    FOR(i, 2*n*k) cin >> a[i];
    sort(a+1, a+2*n*k+1);

    cout << valid(0) << nl;

/*
    int lo = 0, hi = (int)(1e9), ans = 0;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(valid(mid)){
            ans=mid;
            hi=mid-1;
        }
        else lo=mid+1;
    }
    cout<<ans;
//*/

    return 0;
}

