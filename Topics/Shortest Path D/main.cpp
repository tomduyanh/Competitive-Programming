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
#define FORR(i, n) for(int i = n; i > 0; --i)

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int n, m;
struct dulieu{
    int y, w, l;
};
ll dis[N][2];
vector <dulieu> adj[N];

void read(){
    cin >> n;
    int x;
    while(cin >> x){
        int y, w1, w2, l; char ll; cin >> y >> w1 >> w2 >> ll;
        if(ll == 'G') l = 0;
        else l = 1;
        adj[x].PB({y, w1, l});
        adj[y].PB({x, w2, 1 - l});
    }
}

void solve(){
    priority_queue <pair<int, pair<int,int>>> pq;
    pq.push({0, {n, 2}});
    FOR(i, n) dis[i][0] = dis[i][1] = INF;
    dis[n][0] = dis[n][1] = 0;
    while(!pq.empty()){
        int node = pq.top().S.F, status = pq.top().S.S; pq.pop();
        for(auto it : adj[node]){
            int nxt = it.y, w = it.w, sta = it.l;
            if(status != 2 && status != sta) continue;
            if(dis[node][sta] + w < dis[nxt][1 - sta]){
                dis[nxt][1 - sta] = dis[node][sta] + w;
                pq.push({0, {nxt, 1 - sta}});
            }
        }
    }
    cout << min(dis[1][0], dis[1][1]);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    read();
    solve();

    return 0;
}

