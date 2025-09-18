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

const int MaxN = 1 + 1e3;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

int n, m;
int a[MaxN][MaxN];
int visit[MaxN][MaxN], d[MaxN][MaxN];
pair <int, int> pre[MaxN][MaxN];
vector<pair<int, int>> ans;

void bfs(int x, int y){
    int res = 0;
    queue<pair<int, int>> q;
    q.push({x, y}); // Đưa ô x,y vào hàng đợi.
    visit[x][y] = 1; // Đánh dấu đã đi qua.
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        res++;
        for(int i = 0 ; i < 4 ; ++i){
            int i1 = x + dx[i];
            int j1 = y + dy[i];
            if(i1 > 0 && i1 <= n && j1 > 0 && j1 <= m && a[i1][j1] == 0 && !visit[i1][j1]){
                q.push({i1, j1});
                d[i1][j1] = d[x][y]+1;
                visit[i1][j1] = 1;
                pre[i1][j1] = {x, y};
                ans.push_back(make_pair(i1,j1));
            }
        }
    }
}

void trace(int u, int v){
    if (!visit[u][v]) cout << "No path!";
    else {
        vector<pair<int,int>> path;
        while(!(u == 0 && v == 0)){
            path.push_back({u, v});
            int u = u, v = v;
            u = pre[u][v].first, v = pre[u][v].second;
        }
        reverse(path.begin(), path.end());

        cout << "Path:\n";
        for (auto v : path) cout << v.first << ' ' << v.second << '\n';
    }
}

int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n >> m;
    FOR(i, n) FOR(j, m) cin >> a[i][j];
    bfs(1, 2);
    trace(n, m);

    return 0;
}


