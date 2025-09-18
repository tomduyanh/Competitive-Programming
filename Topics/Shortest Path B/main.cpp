#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl "\n"
#define sp " "
#define F first
#define S second
#define PB push_back
#define Pop pop_back
#define pll pair<ll,ll>
typedef long long ll;
const int N = 1e3+5;
const int MOD = 1e9+7;
int n, m, k;
vector <pll> adj[N+1];
void read(){
    cin >> n >> m >> k;
    for(int i = 1; i <= m; ++i){
        int a, b, w; cin >> a >> b >> w;
        adj[a].PB({b,w});
    }
}
priority_queue<pll, vector<pll>, greater<pll>> pq;
priority_queue<ll> best[N+1];
//map <int, map <int, int>> val;
void sol(){
    pq.push({0, 1});
    best[1].push(0);
//    ++val[1][0];
    while(!pq.empty()){
        int a = pq.top().S;
        ll dis = pq.top().F;
        pq.pop();
        if(dis > best[a].top()) continue;
        for(auto &i : adj[a]){
            int b = i.F, w = i.S;
//            if(val[b][dis + w] > 0) continue;
//            if(best[b].size() < k){
                best[b].push(dis + w);
                pq.push({dis + w, b});
//                ++val[b][dis + w];
//            }
//            else if(dis + w < best[b].top()){
//                best[b].pop();
//                best[b].push(dis + w);
//                pq.push({dis + w, b});
//                val[b][dis + w];
//            }
        }
    }
    if(best[n].size() == 0){
        cout << -1;
        return;
    }
    map <int, int> mp;
    vector <ll> ans;
    int sus = best[n].top(), cur = sus;
    while(!best[n].empty()){
        if( mp[best[n].top()] == 0 ) ans.PB(best[n].top());
        ++mp[best[n].top()];
        best[n].pop();
    }
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < min(k, (ll)ans.size()); ++i) cout << ans[i] << sp;
    for(int i = min(k, (ll)ans.size()); i < k; ++i){
        cur += sus * 2;
        cout << cur << sp;
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    read();
    sol();
    return 0;
}
