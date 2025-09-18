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

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int n;
pii cor[N];

bool cmp(pii a, pii b){
    return a.F < b.F || (a.F == b.F && a.S < b.S);
}

int cal(int x1, int y1, int x2, int y2, int x3, int y3){
    return (x2 - x1) * (y2 + y1) + (x3 - x2) * (y3 + y2) + (x1 - x3) * (y1 + y3);
}

void solve(){
    sort(cor+1, cor+n+1, cmp);
    stack <int> s1, s2;
    map <int, bool> vis;
    s1.push(1); vis[1] = true;
    s1.push(2); vis[2] = true;
    cout << nl;
    for(int i = 3; i <= n; ++i){
        int x1, x2, y1, y2;
        int hold2 = s1.top(); s1.pop();
        int hold1 = s1.top(); s1.pop();
        x1 = cor[hold1].F, y1 = cor[hold1].S, x2 = cor[hold2].F, y2 = cor[hold2].S;
        s1.push(hold1); s1.push(hold2);
        int x3 = cor[i].F, y3 = cor[i].S;
        if(cal(x1, y1, x2, y2, x3, y3) <= 0){
//            if(y1 == y2 && y2 == y3 && y3 == -4) cout << nl << cal(x1, y1, x2, y2, x3, y3) << nl << nl;
            vis[s1.top()] = false;
            s1.pop();
        }
        s1.push(i);
        vis[i] = true;
    }
    cout << nl << nl << cal(-1, -4, 1, -4, 3, -4) << nl << nl;
    s2.push(1);
    for(int i = 2; i <= n; ++i){
        if(vis[i]) continue;
        s2.push(i);
        break;
    }
    for(int i = s2.top() + 1; i <= n; ++i){
        if(vis[i]) continue;
        int x1, x2, y1, y2;
        int hold2 = s2.top(); s2.pop();
        int hold1 = s2.top(); s2.pop();
        x1 = cor[hold1].F, y1 = cor[hold1].S, x2 = cor[hold2].F, y2 = cor[hold2].S;
        s2.push(hold1); s2.push(hold2);
        int x3 = cor[i].F, y3 = cor[i].S;
        if(y1 == y2 && y2 == y3 && y3 == -4) cout << nl << cal(x1, y1, x2, y2, x3, y3) << nl << nl;
        if(cal(x1, y1, x2, y2, x3, y3) >= 0){
            if(y1 == y2 && y2 == y3 && y3 == -4) cout << nl << cal(x1, y1, x2, y2, x3, y3) << nl << nl;
            s2.pop();
        }
        s2.push(i);
    }
    s2.push(n);
    vector <int> check;
    while(!s1.empty()) {
        check.PB(s1.top());
        s1.pop();
    }
    reverse(all(check));
    for(auto it : check) cout << it << sp;
    cout << nl;
    check.clear();
    while(!s2.empty()){
        check.PB(s2.top());
        s2.pop();
    }
    reverse(all(check));
    for(auto it : check) cout << cor[it].F << sp << cor[it].S << nl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> cor[i].F >> cor[i].S;

    solve();

    return 0;
}
