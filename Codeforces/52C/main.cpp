#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define sp " "
#define F first
#define S second
#define PB push_back
#define Pop pop_back
#define pll pair<ll,ll>
#define int long long
typedef long long ll;
const ll N = 1e6;
const ll MOD = 1e9+7;
const ll INF = 1e9;
struct Node{
    ll lazy, val;
}node[N*4];
void down(ll id){
    ll t = node[id].lazy;
    for(ll i = 0; i < 2; ++i){
        node[id*2+i].lazy += t;
        node[id*2+i].val += t;
    }
    node[id].lazy = 0;
}
void update(ll id, ll l, ll r, ll u, ll v, ll val){
    if(v < l || r < u) return;
    if(u <= l && r <= v){
        node[id].val += val;
        node[id].lazy += val;
        return;
    }
    ll mid = (l + r) / 2;
    down(id);
    update(id*2, l, mid, u, v, val);
    update(id*2+1, mid+1, r, u, v, val);
    node[id].val = min(node[id*2].val, node[id*2+1].val);
}
ll get(ll id, ll l, ll r, ll u, ll v){
    if(v < l || r < u) return INF;
    if(u <= l && r <= v) return node[id].val;
    ll mid = (l + r) / 2;
    down(id);
    return min(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}
int n, m;
struct query{
    int type, x, y, z;
}q[N];
void inp(){
    cin >> m;
    int cnt = 0;
    for(int i = 0; i <= m; ++i, ++cnt){
        string s; getline(cin, s);
        if(!cnt) continue;
        vector <int> num(4);
        int dem = 1;
        bool neg = false;
        for(int j = 0; j < s.size(); ++j){
//            cout << s[j] << sp;
            if(s[j] == ' ' && '0' <= s[j-1] && s[j-1] <= '9'){
                if(neg == true) num[dem] = -num[dem];
                neg = false;
                ++dem;
            }
            else if(s[j] == '-'){
                neg = true;
            }
            else if('0' <= s[j] && s[j] <= '9') num[dem] = num[dem] * 10 + (s[j] - '0');
        }
        if(neg) num[dem] = -num[dem];
        if(dem == 2){
            q[i].type = 2;
            q[i].x = num[1];
            q[i].y = num[2];
        }
        if(dem == 3){
            q[i].type = 1;
            q[i].x = num[1];
            q[i].y = num[2];
            q[i].z = num[3];
        }
//        cout << nl;
    }
}
void solve(){
    memset(node, INF, sizeof(node));
    ll n; cin >> n;
    for(int i = 1; i <= n; ++i){
        int x; cin >> x;
        update(1,1,n,i,i,x);
    }
    inp();
    for(int i = 1; i <= m; ++i){
        int type = q[i].type;
//        cout << i << sp << type << sp << q[i].x << sp << q[i].y << sp << q[i].z << nl;
        if(type == 2){
            ll u, v; u = q[i].x + 1, v = q[i].y + 1;
            if(u > v) cout << min(get(1, 1, n, u, n), get(1, 1, n, 1, v)) << nl;
            else cout << get(1, 1, n, u, v) << nl;
        }
        else{
            ll x, y, k; x = q[i].x + 1, y = q[i].y + 1, k = q[i].z;
//            cout << x << sp << y << sp << k << nl;
            if(x > y){
                update(1, 1, n, x, n, k);
                update(1, 1, n, 1, y, k);
            }
            else update(1,1,n,x,y,k);
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
