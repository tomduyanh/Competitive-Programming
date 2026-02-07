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
#define FORR(i, n) for(int i = n; i > 0; --i)

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

bool cmp(int a, int b){return a > b;}

int n, a[N];
void solve(){
    cin >> n;
    FOR(i, n) cin >> a[i];
    sort(a+1, a+n+1, cmp);
    int last_odd = -1;
    vector <int> evens;
    FOR(i, n){
        if(!(a[i] % 2)) evens.PB(a[i]);
        if(last_odd == -1 && a[i] % 2) last_odd = a[i];
    }
    cout << last_odd << sp;
    int even_id = 0;
    int prev2_ans = -1;
    int prev_ans = last_odd;
    for(int i = 2; i <= n; ++i){
        if(even_id < evens.size()){
            last_odd += evens[even_id];
            prev2_ans = prev_ans;
            prev_ans = last_odd;
        }
        else{
            last_odd = max(prev2_ans, 0);
            prev2_ans = prev_ans;
            prev_ans = last_odd;
        }
        cout << last_odd << sp;// << prev_ans << sp << prev2_ans << nl;
    }
    cout << nl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    int t; cin >> t;
    while(t--) solve();

    return 0;
}

