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

const int N = 1e5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;
const int BL = sqrt(N);

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int n, m, q;
vector <pii> color[N + 5];
int par[N + 5], sz[N + 5], res[N + 5];
pii qu[N + 5];
map <pii, int> mp;

int root(int node){
    while(node != par[node]) node = par[node];
    return node;
}

void unite(int x, int y){
    x = root(x), y = root(y);
    if(x == y) return;
    if(sz[x] < sz[y]) swap(x, y);
    par[y] = x;
    sz[x] += sz[y];
}

void eli(vector <int> &node){
    sort(all(node));
    node.resize(unique(all(node)) - node.begin());
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n >> m;

    FOR(i, m){
        int x, y, c; cin >> x >> y >> c;
        color[c].PB({x, y});
    }
    cin >> q;
    FOR(i, q) cin >> qu[i].F >> qu[i].S;

    FOR(i, N) par[i] = i, sz[i] = 1;

    FOR(c, m){

        vector <int> node;
        for(auto it : color[c]){
            int x = it.F, y = it.S;
            node.PB(x), node.PB(y);
            unite(x, y);
        }

        eli(node);

        if(color[c].size() >= BL){
            for(int i = 1; i <= q; ++i){
                int x = qu[i].F, y = qu[i].S;
                if(root(x) == root(y)) ++res[i];
            }
        }
        else{
            for(auto node1 : node){
                for(auto node2 : node){
                    int ok1 = node1, ok2 = node2;
                    if(ok1 > ok2) swap(ok1, ok2);
                    if(root(ok1) == root(ok2)) ++mp[{ok1, ok2}];
                }
            }
        }

        for(auto it : node) par[it] = it, sz[it] = 1;
    }

    for(int i = 1; i <= q; ++i){
//        cout << res[i] << sp << mp[{qu[i].F, qu[i].S}] << nl;
        if(qu[i].F > qu[i].S) swap(qu[i].F, qu[i].S);
        cout << res[i] + mp[{qu[i].F, qu[i].S}] / 2 << nl;
    }

    return 0;
}

