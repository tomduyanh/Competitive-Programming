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

int n, k, x;
int a[N];

struct info { int l, r, type; };

using P = pair<int, info>;

struct cmp {
    bool operator()(const P& a, const P& b) const { return a.first < b.first; }
};


void solve(){
    cin >> n >> k >> x;
    FOR(i, n) cin >> a[i];
    sort(a+1,a+n+1);
    priority_queue<P, vector<P>, cmp> pq;
    FOR(i, n-1){
        int len = a[i+1] - a[i];
        pq.push({len, {a[i], a[i+1], 0}});
    }
    pq.push({a[1]*2, { 0, a[1], 1 } });
    pq.push({2*(x-a[n]), {a[n], x, 2} });
    vector <int> ans;
    map<int,bool> used;
    FOR(i, k){
        int len = pq.top().F;
        info ok = pq.top().S;
        pq.pop();
        if(ok.type == 0){
            int pos = (ok.l+ok.r)/2;
            if(used[pos]){
                --i;
                continue;
            }
            pq.push({2*(pos-ok.l), {ok.l, pos, 2 }});
            pq.push({2*(ok.r - pos), {pos, ok.r, 1 }});
            ans.PB(pos);
            used[pos] = true;
        }
        else if(ok.type == 1){
            if(used[ok.l]){
                --i;
                continue;
            }
            ans.PB(ok.l);
            pq.push({2*(ok.r - ok.l - 1), {ok.l + 1, ok.r, 1 }});
            used[ok.l] = true;
        }
        else{
            if(used[ok.r]){
                --i;
                continue;
            }
            ans.PB(ok.r);
            pq.push({2*(ok.r - ok.l - 1), {ok.l, ok.r-1, 2 }});
            used[ok.r] = true;
        }
    }
    for(auto it : ans) cout << it << sp;
    cout << nl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    int t; cin >> t;
    while(t--) solve();

    return 0;
}

