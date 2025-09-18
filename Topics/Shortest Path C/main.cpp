#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define nl "\n"
#define sp " "
#define F first
#define S second
#define PB push_back
#define Pop pop_back
#define pll pair<ll,ll>
typedef long long ll;
const int N = 1e6;
const int MOD = 1e9+7;
int n, m, k;
vector <pll> adj[N+1];
void read(){
    cin >> n >> m >> k;
    for(int i = 1; i <= m; ++i){
        int a, b, w; cin >> a >> b >> w;
        adj[a].PB({b,w});
        adj[b].PB({a,w});
    }
}
priority_queue<pll, vector<pll>, greater<pll>> pq;
priority_queue<ll> best[N+1];
unordered_set <int> check[N];
int Find(){
    vector <int> dis(n + 5);
    priority_queue <pll> pq1;
    pq1.push({n, 0});
    while(!pq1.empty()){
        int node = pq1.top().S; pq1.pop();
        for(auto it : adj[node]){
            int nxt = it.F, w = it.S;
            if(dis[nxt] > dis[node] + w){
                dis[nxt] = dis[node] + w;
                pq1.push({-dis[nxt], nxt});
            }
        }
    }
    return dis[1];
}
bool contains(int val, int sus){
    return check[sus].find(val) != check[sus].end();
}
void sol(){
    pq.push({0, 1});
    best[1].push(0);
//    mp[1][0] = 1;
    while(!pq.empty()){
        int a = pq.top().S;
        ll dis = pq.top().F;
        pq.pop();
        if(dis > best[a].top()) continue;
        for(auto &i : adj[a]){
            int b = i.F, w = i.S;
//            if(mp[b][dis + w] > 0) continue;
            if(contains(dis+w, b)) continue;
            if(best[b].size() < k){
                best[b].push(dis + w);
//                ++mp[b][dis + w];
                pq.push({dis + w, b});
                check[b].insert(dis + w);
            }
            else if(dis + w < best[b].top()){
                best[b].pop();
                best[b].push(dis + w);
//                ++mp[b][dis + w];
                pq.push({dis + w, b});
                check[b].insert(dis + w);
            }
        }
    }
    vector <ll> ans;
    while(!best[n].empty()){
        ans.PB(best[n].top());
        best[n].pop();
    }
    reverse(ans.begin(), ans.end());
    for(auto it : ans) cout << it << sp;
//    int bruh = Find();
    if(ans.size() == 0){
        cout << -1;
        return;
    }
    for(int i = ans.size(), j = 1; i < k; ++i){
        cout << ans[0] + j * (ans[0] + ans[0]) << sp;
        ++j;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    read();
    sol();
    return 0;
}
