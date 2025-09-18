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

const int N = 1e3 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int n, q, mxNode = 0;
int a[N][N];
ll segR[N][4*N], segC[4*N][4*N];
///segR[row][node]
///segC[node][node]

void read(){
    cin >> n >> q;
    FOR(i, n)
        FOR(j, n){
            char x; cin >> x;
            a[i][j] = (x == '.' ? 0 : 1);
        }
}

void buildR(int id, int l, int r, int row){
    mxNode = max(mxNode, id);
    if(l == r){
        segR[row][id] = a[row][l];
        return;
    }
    int mid = (l + r) / 2;
    buildR(id*2, l, mid, row);
    buildR(id*2+1, mid+1, r, row);
    segR[row][id] = segR[row][id*2] + segR[row][id*2+1];
}

void buildC(int id, int l, int r, int node){ ///l = lo, r = hi; row
    if(l == r){
        segC[node][id] = segR[l][node];
        return;
    }
    int mid = (l + r) / 2;
    buildC(id*2, l, mid, node);
    buildC(id*2+1, mid+1, r, node);
    segC[node][id] = segC[node][id*2] + segC[node][id*2+1];
}

void buildST(){
    FOR(i, n){
        buildR(1, 1, n, i);/// build tree in every row
    }
    FOR(i, mxNode){
        buildC(1, 1, n, i);///build tree in every column
    }
}

void updateC(int id, int l, int r, int x, int y, int node){
    if(x < l || r < x) return;
    if(l == x && r == x){
        segC[node][id] = segR[x][node];
        return;
    }
    int mid = (l + r) / 2;
    updateC(id*2, l, mid, x, y, node);
    updateC(id*2+1, mid+1, r, x, y, node);
    segC[node][id] = segC[node][id*2] + segC[node][id*2+1];
}

void updateR(int id, int l, int r, int x, int y){
//    cout << id << nl;
    if(y < l || r < y) return;
    if(l == y && r == y){
        segR[x][id] = 1 - segR[x][id];
        updateC(1, 1, n, x, y, id);
        return;
    }
    int mid = (l + r) / 2;
    updateR(id*2, l, mid, x, y);
    updateR(id*2+1, mid+1, r, x, y);
    segR[x][id] = segR[x][id*2] + segR[x][id*2+1];
    updateC(1, 1, n, x, y, id);
}

int queryC(int id, int l, int r, int x1, int y1, int x2, int y2, int node){
    if(r < x1 || x2 < l) return 0;
    if(x1 <= l && r <= x2){
        return segC[node][id];
    }
    int mid = (l + r) / 2;
    return queryC(id*2, l, mid, x1, y1, x2, y2, node) + queryC(id*2+1, mid+1, r, x1, y1, x2, y2, node);
}

int queryR(int id, int l, int r, int x1, int y1, int x2, int y2){
    if(r < y1 || y2 < l) return 0;
    if(y1 <= l && r <= y2){
        return queryC(1, 1, n, x1, y1, x2, y2, id);
    }
    int mid = (l + r) / 2;
    return queryR(id*2, l, mid, x1, y1, x2, y2) + queryR(id*2+1, mid+1, r, x1, y1, x2, y2);
}

void solve(){
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int x, y; cin >> x >> y;
            updateR(1, 1, n, x, y);
        }
        if(t == 2){
            int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
            cout << queryR(1, 1, n, x1, y1, x2, y2) << nl;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    read();
    buildST();
    solve();

    return 0;
}

