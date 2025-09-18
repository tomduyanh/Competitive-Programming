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
const int base =  101;
const ll INF = 1e18;
const ll MM = 1ll * MOD * MOD;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int n;
ll p[N], rp[N], h[N], rh[N];
string s;

int getHash(int u, int v){
    return (h[v] - h[u - 1] * p[v - u + 1] + MM) % MOD;
}

int getHashR(int u, int v){
    return (rh[u] - rh[v + 1] * rp[v - u + 1] + MM) % MOD;
}

bool compare(pii a, pii b){
    return a.S < b.S;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));


    cin >> s; n = s.size();
    s = " " + s;

    p[0] = 1;
    FOR(i, n){
        p[i] = (p[i-1] * base) % MOD;
        h[i] = ((h[i-1] * base) + (s[i] - 'a' + 1)) % MOD;
    }
    FORR(i, n){
        rp[i] = (rp[i+1] * base) % MOD;
        rh[i] = ((rh[i+1] * base) + (s[i] - 'a' + 1)) % MOD;
    }

    vector <pii> pos;
    for(int i = 1; i <= n; ++i){
        int len = min(i, n - i + 1);
//        cout << i - len + 1 << sp << i + len - 1 << nl;
        if(getHash(i - len + 1, i) == getHashR(i, i + len - 1)){
            pos.PB({i, n - len});
        }
    }

    sort(all(pos), compare);
    vector <char> ans;
    int i, j; i = j = pos[0].F;
    while(true){
        cout << i << sp << j << nl;
        if(1 <= i){
            ans.PB(s[i]);
        }
        else if(j <= n){
            ans.PB(s[j]);
        }
        if(1 <= i) --i;
        if(j <= n) ++j;
        if(i < 1 && j > n) break;
    }
    for(auto it : ans) cout << it;

    return 0;
}
