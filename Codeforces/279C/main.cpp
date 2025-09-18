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

int n, m;
int a[N], cnt[N], idx[N];

void comp(){
    vector <int> na;
    for(int i = 1; i <= n; ++i){
        na.PB(a[i]);
        int hold = a[i];
        while(i <= n && a[i] == hold) ++i;
        --i;
    }
    int i = 1, j = 0;
    while(i <= n && j < na.size()){
        idx[i] = j + 1;
        if(a[i+1] != na[j]) ++j;
        ++i;
    }
    n = na.size();
    FOR(i, n) a[i] = na[i-1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n >> m;
    FOR(i, n) cin >> a[i];
    comp();
    FOR(i, n){
        cnt[i] = cnt[i-1];
        if(1 < i && i < n && a[i-1] < a[i] && a[i] > a[i+1]) ++cnt[i];
    }
    while(m--){
        int l, r; cin >> l >> r;
        l = idx[l], r = idx[r];
        int dem = 0;
        if(a[l] > a[l+1]) ++dem;
        if(a[r-1] < a[r]) ++dem;
        dem += cnt[r-1] - cnt[l];
        if(dem <= 1 || (r-l+1) == 1) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}

