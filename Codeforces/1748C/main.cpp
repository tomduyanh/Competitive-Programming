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

int n;
int a[N], s[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    int t; cin >> t;
    while(t--){
        cin >> n;
        int ans = 0;
        vector <int> range; range.PB(0);
        FOR(i, n){
            cin >> a[i];
            s[i] = s[i-1] + a[i];
            if(a[i] == 0) range.PB(i);
        }
        range.PB(n+1);
        for(auto it : range) cout << it << sp;
        cout << nl;
        vector <int> mx_range;
        for(int i = 0; i < range.size() - 1; ++i){
            map <int, int> mp;
            int mx = 0, br = 1;
            for(int j = range[i] + 1; j < range[i + 1]; ++j) ++mp[s[j]];
            for(auto it : mp){
                if(it.S > mx){
                    mx = it.S;
                    br = it.F;
                }
                else if(it.S == mx) br = min(br, it.F);
            }
            if(range[i+1] - range[i] == 1) mx_range.PB()
            mx_range.PB(mx);
            if(br == 0) ans += mx;
        }
        for(auto it : mx_range) cout << it << sp;
        cout << nl;
    }

    return 0;
}

