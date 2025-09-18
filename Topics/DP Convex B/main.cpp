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

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    freopen("FILE.INP", "r", stdin);
    freopen("FILE.OUT", "w", stdout);
}

int n, m;
double h[N+1];
pll line[N+1];

bool compare(pii a, pii b){
    return a.F < b.F || (a.F == b.F && a.S > b.S);
}

void read(){
    cin >> n;
    FOR(i, n){
        cin >> line[i].F >> line[i].S;
        line[i].F = -line[i].F; line[i].S = -line[i].S;
    }
    sort(line+1, line+n+1, compare);
}

void comp(){
    vector <pii> ok;
    FOR(i, n) if(i == 1 || line[i].F != line[i-1].F) ok.PB({line[i].F, line[i].S});
    n = ok.size();
    FOR(i, n) line[i].F = ok[i-1].F, line[i].S = ok[i-1].S;
}

bool ok(pii line1, pii line2, pii line3){
    return (line1.S - line3.S) * (line3.F - line2.F) < (line2.S - line3.S) * (line3.F - line1.F);
}

double intersect(pii line1, pii line2){
    return (double)(line2.S - line1.S) / (line1.F - line2.F);
}

void build(){
    vector <pii> lines;
    lines.PB(line[1]);
    if(n > 1) lines.PB(line[2]);
    for(int i = 3; i <= n; ++i){

        lines.PB(line[i]);

        while(lines.size() > 2){
            pii line1, line2, line3;

            line3 = lines[lines.size()-1]; lines.pop_back();
            line2 = lines[lines.size()-1]; lines.pop_back();
            line1 = lines[lines.size()-1]; lines.pop_back();

            lines.PB(line1);

            if(ok(line1, line2, line3)){
                //cout << "w";
                lines.PB(line2);
                lines.PB(line3);
                break;
            }
            lines.PB(line3);
        }

    }
    n = 0;
    for(auto it : lines){
        line[++n] = it;
    }

    h[1] = -INF;
    FOR(i, n - 1) h[i+1] = intersect(line[i], line[i+1]);
//    FOR(i, n) coCut << line[i].F << sp << line[i].S << sp << h[i] << nl;
//    cout << nl;
}

int get(int id, int x){
    return - line[id].F * x - line[id].S;
}

void solve(){
    cin >> m;
    while(m--){
        int x; cin >> x;// x = -x;
        int lo = 1, hi = n, pos = 1;
        while(lo <= hi){
            int mid = (lo + hi) / 2;

            if(x >= h[mid]){
                pos = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;

        }
//        cout << pos << sp << x << "\t";
        cout << get(pos, x) << nl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    read();
    comp();
    build();
    solve();

    return 0;
}
