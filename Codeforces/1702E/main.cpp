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

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen(".INP", "r", stdin);
    freopen(".OUT", "w", stdout);
}

int n;
int sz[N], par[N];
//int Set[3][N];
map <int,int> mp;

void reset() {
    mp.clear();
    for(int i = 1; i <= n + 2; ++i) {
        par[i] = i;
        sz[i] = 1;
//        Set[1][i] = Set[2][i] = 0;
    }
    for(int i = 1; i <= 2; ++i){
        ++sz[n+i];
    }
}

int root(int node){
    while(node != par[node]) node = par[node];
    return node;
}

void Unite(int a, int b){
    if(sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
}

bool sol(){
    bool ans = true;
    cin >> n;
    reset();
    int A = n+1, B = n+2;
    cout << nl;
    for(int i = 1; i <= n; ++i){
        int a, b; cin >> a >> b;
        ++mp[a], ++mp[b];
        if((mp[a] > 2 || mp[b] > 2) || (a == b)){
            ans = false;
        }
        if(!ans) continue;
        //cout << i << sp;
        int ra = root(a), rb = root(b);
        //cout << ra << sp << rb << nl;
        if(ra > n && rb > n){
            if(ra != rb){
                ans = false;
            }
            else{
                if(ra == A) Unite(a, B), Unite(b, B);
                else Unite(a, A), Unite(b, A);
            }
        }
        else if(ra <= n && rb <= n){
            Unite(a, A);
            Unite(b, A);
        }
        else if(ra <= n || rb <= n){
            if(max(ra, rb) == A) Unite(a, B), Unite(b, B);
            else if(max(ra, rb) == B) Unite(a, A), Unite(b, A);
        }
        //cout << root(a) << sp << root(b) << nl;
        //cout << nl;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();

    int t; cin >> t;
    while(t--) cout << (sol() ? "Yes\n" : "No\n");

    return 0;
}
