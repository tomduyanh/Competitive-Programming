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
const int INF = 1e9;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int n, m;
struct Cor{
    int F, S;
    int id;
}cor[N];
vector <int> lower, upper;

bool compareX(Cor a, Cor b){
    return a.F < b.F || (a.F == b.F && a.S < b.S);
}

bool compareY(Cor a, Cor b){
    return a.F < b.F || (a.F == b.F && a.S > b.S);
}

bool compareID(Cor a, Cor b){
    return a.id < b.id;
}

int cal(int x1, int y1, int x2, int y2, int x3, int y3){
    int sum = (x2 - x1) * (y2 + y1) + (x3 - x2) * (y3 + y2) + (x1 - x3) * (y1 + y3);
    return sum;
}

void buildUpper(){
    sort(cor + 1, cor + n + 1, compareX);

    upper.PB(1);
    upper.PB(2);
    bool alr = false;
    int ex = 0, eid = 0;

    FOR(i, n)
        if(cor[i].F > ex){
            ex = cor[i].F;
            eid = i;
        }

    for(int i = 3; i <= n; ++i){
        int sz = upper.size();
        int x1 = cor[upper[sz - 2]].F, y1 = cor[upper[sz - 2]].S;
        int x2 = cor[upper[sz - 1]].F, y2 = cor[upper[sz - 1]].S;
        int x3 = cor[i].F, y3 = cor[i].S;

        int s = cal (x1, y1, x2, y2, x3, y3);

        while(s < 0 && upper.size() >= 2){
            upper.pop_back(); sz = upper.size();

            if(sz < 2) break;
            x1 = cor[upper[sz - 2]].F, y1 = cor[upper[sz - 2]].S;
            x2 = cor[upper[sz - 1]].F, y2 = cor[upper[sz - 1]].S;

            s = cal(x1, y1, x2, y2, x3, y3);
        }
        upper.PB(i);
    }
    for(int i = 0; i < upper.size(); ++i){
        if(upper[i] == eid) alr = true;
        upper[i] = cor[upper[i]].id;
    }
    if(!alr){
        upper.PB(cor[eid].id);
    }
}

void buildLower(){
    sort(cor + 1, cor + n + 1, compareY);

    lower.PB(1);
    lower.PB(2);
    bool alr = false;
    int ex = 0, eid = 0;

    FOR(i, n)
        if(cor[i].F > ex){
            ex = cor[i].F;
            eid = i;
        }

    for(int i = 3; i <= n; ++i){
        int sz = lower.size();
        int x1 = cor[lower[sz - 2]].F, y1 = cor[lower[sz - 2]].S;
        int x2 = cor[lower[sz - 1]].F, y2 = cor[lower[sz - 1]].S;
        int x3 = cor[i].F, y3 = cor[i].S;

        int s = cal(x1, y1, x2, y2, x3, y3);

        while(s > 0 && lower.size() >= 2){
            lower.pop_back(); sz = lower.size();

            if(sz < 2) break;
            x1 = cor[lower[sz - 2]].F, y1 = cor[lower[sz - 2]].S;
            x2 = cor[lower[sz - 1]].F, y2 = cor[lower[sz - 1]].S;

            s = cal(x1, y1, x2, y2, x3, y3);
        }
        lower.PB(i);
    }
    for(int i = 0; i < lower.size(); ++i){
        if(lower[i] == eid) alr = true;
        lower[i] = cor[lower[i]].id;
    }
    if(!alr){
        lower.PB(cor[eid].id);
    }
}

void debug(){
    sort(cor + 1, cor + n + 1, compareID);
    cout << "upper :\n";
    for(auto it : upper) cout << cor[it].F << sp << cor[it].S << nl;
    cout << "lower : \n";
    for(auto it : lower) cout << cor[it].F << sp << cor[it].S << nl;
}

int bsup(int val){
    int pos = -1;
    int lo = 0, hi = upper.size() - 1;

    while(lo <= hi){
        int mid = (lo + hi) / 2;
        int upx = cor[upper[mid]].F;

        if(upx <= val){
            pos = mid;
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }

    return pos;
}

int bslo(int val){
    int pos = -1;
    int lo = 0, hi = lower.size() - 1;

    while(lo <= hi){
        int mid = (lo + hi) / 2;
        int lox = cor[lower[mid]].F;

        if(lox <= val){
            pos = mid;
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }

    return pos;
}

string ans[3] = {"INSIDE\n", "OUTSIDE\n", "BOUNDARY\n"};

int checkIn(int x, int y){
    int id1Up = bsup(x), id1Lo = bslo(x), id2Up = id1Up + 1, id2Lo = id1Lo + 1;
    if(id1Up == -1 || id1Lo == -1) return 1;
    int x1, y1, x2, y2, s1, s2;
    /*
    cout << id1Up << sp << id1Lo << nl;
    cout << upper[id1Up + 1] << sp << upper[id1Up] << "\t" << cor[upper[id1Up - 1]].F << sp << cor[upper[id1Up]].F << nl;
    cout << lower[id1Lo + 1] << sp << lower[id1Lo] << "\t" << cor[lower[id1Lo - 1]].F << sp << cor[lower[id1Lo]].F << nl;
    cout << nl;
    */
    if((id1Up > 0 && cor[upper[id1Up - 1]].F == cor[upper[id1Up]].F && cor[upper[id1Up]].F == x) || (id1Lo > 0 && cor[lower[id1Lo - 1]].F == cor[lower[id1Lo]].F && cor[lower[id1Lo]].F == x)){
        id2Up = id1Up - 1, id2Lo = id1Lo - 1;
        x1 = cor[upper[id1Up]].F, y1 = cor[upper[id1Up]].S;
        x2 = cor[upper[id2Up]].F, y2 = cor[upper[id2Up]].S;
        s1 = cal(x1, y1, x, y, x2, y2);
        x1 = cor[lower[id1Lo]].F, y1 = cor[lower[id1Lo]].S;
        x2 = cor[lower[id2Lo]].F, y2 = cor[lower[id2Lo]].S;
        s2 = cal(x1, y1, x, y, x2, y2);
    }
    else if((id1Up < upper.size() - 1 && cor[upper[id1Up + 1]].F == cor[upper[id1Up]].F && cor[upper[id1Up]].F == x) || (id1Lo < lower.size() - 1 && cor[lower[id1Lo + 1]].F == cor[lower[id1Lo]].F && cor[lower[id1Lo]].F == x)){
        id2Up = id1Up + 1, id2Lo = id1Lo + 1;
        x1 = cor[upper[id1Up]].F, y1 = cor[upper[id1Up]].S;
        x2 = cor[upper[id2Up]].F, y2 = cor[upper[id2Up]].S;
        s1 = cal(x1, y1, x, y, x2, y2);
        x1 = cor[lower[id1Lo]].F, y1 = cor[lower[id1Lo]].S;
        x2 = cor[lower[id2Lo]].F, y2 = cor[lower[id2Lo]].S;
        s2 = cal(x1, y1, x, y, x2, y2);
    }
    else if(( id1Up == upper.size() - 1) || (id1Lo == lower.size() - 1)){
        if(( id1Up == upper.size() && cor[upper[id1Up]].S == y) || (id1Lo == lower.size() && cor[lower[id1Lo]].S == y)) return 0;
        return 1;
    }
    else{
        x1 = cor[upper[id1Up]].F, y1 = cor[upper[id1Up]].S;
        x2 = cor[upper[id2Up]].F, y2 = cor[upper[id2Up]].S;
        s1 = cal(x1, y1, x, y, x2, y2);

        x1 = cor[lower[id1Lo]].F, y1 = cor[lower[id1Lo]].S;
        x2 = cor[lower[id2Lo]].F, y2 = cor[lower[id2Lo]].S;
        s2 = cal(x1, y1, x, y, x2, y2);
    }

    if(s1 * s2  < 0) return 0;
    if(s1 * s2 == 0) return 2;
    return 1;
}

void solve(){
    sort(cor + 1, cor + n + 1, compareID);
    while(m--){
        int x, y; cin >> x >> y;
        cout << ans[checkIn(x, y)];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freop();
    //srand(time(NULL));

    cin >> n >> m;
    FOR(i, n){
        cin >> cor[i].F >> cor[i].S;
        cor[i].id = i;
    }

    buildUpper();
    buildLower();
//    debug();
//    cout << "w\n";
    solve();

    return 0;
}

