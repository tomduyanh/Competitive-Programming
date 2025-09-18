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

int n; string s;
int z[N];

void zFunc(){
    int l = 0, r = 0;
    for(int i = 1; i < n; ++i){
        if(i < r) z[i] = min(z[i - l], r - i + 1);
        while(i + z[i] < n && s[i + z[i]] == s[z[i]]) ++z[i];
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

    cin >> s; n = s.size();
    zFunc();
    vector <int> ans;
    for(int i = n - 1; i >= 0; --i){
        if(i + z[i] == n) ans.PB(z[i]);
    }
    for(auto it : ans) cout << it << sp;

    return 0;
}

