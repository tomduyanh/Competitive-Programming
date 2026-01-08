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

bool check(vector<int> temp){
    int m = temp.size();
    vector <int> a(m+1), b(m+1);
    for(int i = 0; i <= m/2; ++i){
        if(temp[i] == 0){
            a[i] = 1, b[i] = 1;
        }
        else{
            a[i] = 1, b[i] = 2;
        }
        a[m-i-1] = b[i], b[m-i-1] = a[i];
    }
    for(int i = 0; i < m; ++i){
        if((a[i]%2) ^ b[i] != temp[i]) return false;
    }
    return true;
}

bool sol(){
    ll n; cin >> n;
    if(!n) return 1;
    vector <int> temp;
    for(int k = n, i = 0; k > 0; k /= 2, ++i){
        temp.PB(k % 2);
    }
    for(int i = 0; i + temp.size() <= 64; ++i){
        if(i) temp.PB(0);
        if(check(temp)) return true;
    }
    return false;
    /*
    for(auto it : temp) cout << it << sp;
    cout << nl;
    for(auto it : a) cout << it << sp;
    cout << nl;
    for(auto it : b) cout << it << sp;
    cout << nl;
    for(int i = 0; i < m; ++i){
        if((a[i]%2) ^ b[i] != temp[i]) return false;
    }
    return true;
    */
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    int t; cin >> t;
    while(t--) cout << (sol() ? "YES\n" : "NO\n");

    return 0;
}

