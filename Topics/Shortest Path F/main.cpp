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

int n, m, a, b;
ll dis[N][2];
vector <pii> adj1[N], adj2[N];

void read(){
    cin >> a >> b;
    cin >> n >> m;
    FOR(i, m){
        int x, y, w; cin >> x >> y >> w;
        adj1[x].PB({y, w});
        adj2[y].PB({x, w});
    }
}

void solve(){
    priority_queue <pair<int,pair<int,pair<int,int>>>> pq; ///all_time, node, day, cur_time
    pq.push({0, {a, {1, 0}}});
    FOR(i, n) dis[i][0] = dis[i][1] = INF;
    dis[a][1] = 0;
    while(!pq.empty()){
        int cur_dis = -pq.top().F, node = pq.top().S.F, day = pq.top().S.S.F, cur_time = pq.top().S.S.S; pq.pop();
        if(dis[node][1 - day] > (cur_dis + (12 - cur_time))){
            dis[node][1 - day] = (cur_dis + (12 - cur_time));
            pq.push({-(cur_dis + (12 - cur_time)), {node, {1 - day, 0}}});
        }
        if(day){
            for(auto it : adj1[node]){
                int nxt = it.F, w = it.S;
                if(cur_time + w > 12){
                    if(dis[nxt][day] > (cur_dis + (12 - cur_time)) + 12 + w){
                        dis[nxt][day] = (cur_dis + (12 - cur_time)) + 12 + w;
                        pq.push({-dis[nxt][day], {nxt, {day, 0}}});
                    }
                }
                else if(cur_dis + w < dis[nxt][day]){
                    dis[nxt][day] = cur_dis + w;
                    pq.push({-dis[nxt][day], {nxt, {day, cur_time + w} } });
                }
            }
        }
        else{
            for(auto it : adj2[node]){
                int nxt = it.F, w = it.S;
                if(cur_time + w > 12){
                    if(dis[nxt][day] > (cur_dis + (12 - cur_time)) + 12 + w){
                        dis[nxt][day] = (cur_dis + (12 - cur_time)) + 12 + w;
                        pq.push({-dis[nxt][day], {nxt, {day, 0}}});
                    }
                }
                else if(cur_dis + w < dis[nxt][day]){
                    dis[nxt][day] = cur_dis + w;
                    pq.push({-dis[nxt][day], {nxt, {day, cur_time + w} } });
                }
            }
        }
    }
    cout << min(dis[b][0], dis[b][1]);
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

