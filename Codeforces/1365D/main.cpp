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

const int N = 50 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen(".INP", "r", stdin);
    freopen(".OUT", "w", stdout);
}

int n, m;
char a[N][N];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

bool valid(int x, int y){
    return 1 <= x && x <= n && 1 <= y && y <= m;
}

int cnt = 0;
bool vis[N][N];

void DFS(int x, int y){
    if(vis[x][y] || a[x][y] == '#' || cnt == -1) return;
    if(a[x][y] == 'G') ++cnt;
    if(a[x][y] == 'B'){
        cnt = -1;
        return;
    }
    vis[x][y] = true;
    for(int i = 0; i < 4 && cnt != -1; ++i){
        int u = x + dx[i], v = y + dy[i];
        if(valid(u, v) && a[u][v] != '#') DFS(u, v);
    }
}

void reset(){
    cnt = 0;
    memset(vis, false, sizeof(vis));
}

bool solve(){
    reset();
    cin >> n >> m;
    int good = 0; bool bad = false;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j){
            cin >> a[i][j];
            if(a[i][j] == 'G') good++;
            if(a[i][j] == 'B') bad = true;
        }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(a[i][j] == 'B'){
                for(int k = 0; k < 4; ++k){
                    int x = i + dx[k], y = j + dy[k];
                    if(!valid(x, y)) continue;
                    if(a[x][y] == '.') a[x][y] = '#';
                }
            }
        }
    }
    if(good == 0) return true;
    DFS(n, m);
    if(cnt < good) return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();

    int t; cin >> t;
    while(t--) cout << (solve() ? "Yes\n" : "No\n");

    return 0;
}
