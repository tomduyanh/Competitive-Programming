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

int n, m, t, xx = 0, yy = 0, cnt = 0;
int ww[201][201][201];
string s;
vector <int> adj[N];
pii pos[N];
int val[1000][1000]; ll dis[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> m >> t >> n >> s;
    int x = 100, y = 100;
    val[x][y] = 1;
    for(auto it : s){
        if(it == 'U') ++y;
        if(it == 'D') --y;
        if(it == 'L') --x;
        if(it == 'R') ++x;
        ++val[x][y];
    }
    for(int i = 0; i <= 200; ++i){
        for(int j = 0; j <= 200; ++j){
            if(val[i][j]){
                val[i][j] = ++cnt;
                pos[cnt] = {i, j};
            }
        }
    }
    xx = x, yy = y;
    x = 100, y = 100;
    for(int i = 0; i < n; ++i){
        char it = s[i];
        int prex = x, prey = y;
        if(it == 'U') ++y;
        if(it == 'D') --y;
        if(it == 'L') --x;
        if(it == 'R') ++x;
        int v = val[x][y], prev = val[prex][prey], w = m;
        if(i && s[i] != s[i-1]) w += t;
        adj[prev].PB(v);
    }
    FOR(i, 100) dis[i] = INF;
    dis[val[100][100]] = 0;
    priority_queue < pair<int, pair<int,int> > > pq;
    pq.push({0, {val[100][100], 0}});
    int k = 0;
    while(!pq.empty()){
        int val = -pq.top().F, node = pq.top().S.F, prenode = pq.top().S.S; pq.pop();
        int ynode = pos[node].S, yprenode = pos[prenode].S;
        bool UDpre = false;
        if(prenode && abs(ynode - yprenode) > 0) UDpre = true;
        for(auto nxt : adj[node]){
            int ynxt = pos[nxt].S;
            bool UDcur = false;
            if(abs(ynxt - ynode) > 0) UDcur = true;
            if(!prenode){
                if(val + m < dis[nxt]){
                    dis[nxt] = val + m;
                    pq.push({-dis[nxt], {nxt, node}});
                }
            }
            else{
                if(val + m + (UDcur != UDpre ? t : 0) < dis[nxt]){
                    dis[nxt] = val + m + (UDcur != UDpre ? t : 0);
                    pq.push({-dis[nxt], {nxt, node}});
                }
            }
        }
    }
    cout << dis[val[xx][yy]];

    return 0;
}

