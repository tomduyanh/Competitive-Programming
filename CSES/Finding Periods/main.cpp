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
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

string s;
int n, nn = 0, z[2*N];

void Z(){
    nn = s.size();
    s = s + '*' + s;
    int l = 1, r = 1;
    n = s.size();
    FOR(i, n - 1){
        if(i <= r) z[i] = min(z[i - l], r - i + 1);
        while(i + z[i] < n && s[z[i]] == s[z[i] + i]) ++z[i];
        if(i + z[i] - 1 > r){
            r = i + z[i] - 1;
            l = i;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> s;
    Z();
    vector <int> ans;
    for(int i = nn + 2, j = 1; i <= n; ++i, ++j){
        if(i - 1 + z[i - 1] == n) ans.PB(j);
    }
    for(int i = 1; i < ans.size(); ++i) cout << ans[i]  - 1<< sp;
    cout << nn;

    return 0;
}

