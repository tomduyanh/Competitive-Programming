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

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen(".INP", "r", stdin);
    freopen(".OUT", "w", stdout);
}

int n, x;
vector <int> adj[N];

void read() {
    cin >> n >> x;
    for(int i = 1; i < n; ++i) {
        int a, b; cin >> a >> b;
        adj[a].PB(b);
        adj[b].PB(a);
    }
}

int A[N], B[N];

void DFS(int node, int pre, int step, int arr[], int bruh) {
    arr[node] = step;
    bool f = false;
    for(auto nxt : adj[node]) {
        if((nxt == pre) || (A[nxt] <= step + 2 && bruh)) continue;
        DFS(nxt, node, step + 2, arr, bruh);
        if(bruh && B[nxt] != 1e9) f = true;
    }
    if((bruh && !f)) {
        B[node] = 1e9;
    }
}

void solve() {
    for(int i = 1; i <= n; ++i) B[i] = 1e9;
    DFS(1, 0, 0, A, 0);
    DFS(x, 0, -1, B, 1);
    ///*
    cout << nl;
    for(int i = 1; i <= n; ++i) {
        cout << i << sp << A[i] << nl;
    }
    cout << nl;
    for(int i = 1; i <= n; ++i) {
        cout << i << sp << B[i] << nl;
    }
    cout << nl;
    //*/
    int mx = 0;
    for(int i = 1; i <= n; ++i) {
        if(A[i] <= B[i]) {
            mx = max(mx, A[i]);
        }
    }
    cout << mx;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();

    read();
    solve();

    return 0;
}
