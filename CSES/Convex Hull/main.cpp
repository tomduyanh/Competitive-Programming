#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int,int> pii;
typedef pair <ll , ll> pll;

#define int long long
#define sp " "
#define nl "\n"
#define F first
#define S second
#define PB push_back
#define all(arr) arr.begin(), arr.end()
#define FOR(i, n) for(int i = 1; i <= n; ++i)

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int n;
struct cor{
    int x, y;
}a[N];
vector <int> up, down;

bool compareX(cor a, cor b){
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

int Area(int x1, int y1, int x2, int y2, int x3,int y3)
{
    int sum = (x2 - x1) * (y2 + y1) + (x3 - x2) * (y2 + y3) + (x1 - x3) * (y3 + y1);
    return sum;
}

void ConvexHull(){
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i].x >> a[i].y;
    sort(a+1, a+n+1, compareX);

    up.PB(1), up.PB(2);
    down.PB(1), down.PB(2);

    for(int i = 3; i <= n; ++i){
        up.PB(i);
        int szup = up.size();
        int x1 = a[up[szup-3]].x, y1 = a[up[szup-3]].y, x2 = a[up[szup-2]].x, y2 = a[up[szup-2]].y, x3 = a[up[szup-1]].x, y3 = a[up[szup-1]].y;
        int ar = Area(x1, y1, x2, y2, x3, y3);
        while(szup > 2 && ar <= 0){
            int hold = up[szup-1];
            up.pop_back(); up.pop_back(); up.PB(hold);
            szup--;
            if(szup <= 2) break;
            x1 = a[up[szup-3]].x, y1 = a[up[szup-3]].y, x2 = a[up[szup-2]].x, y2 = a[up[szup-2]].y, x3 = a[up[szup-1]].x, y3 = a[up[szup-1]].y;
            ar = Area(x1, y1, x2, y2, x3, y3);
        }
    }

    for(int i = 3; i <= n; ++i){
        down.PB(i);
        int szdown = down.size();
        int x1 = a[down[szdown-3]].x, y1 = a[down[szdown-3]].y, x2 = a[down[szdown-2]].x, y2 = a[down[szdown-2]].y, x3 = a[down[szdown-1]].x, y3 = a[down[szdown-1]].y;
        int ar = Area(x1, y1, x2, y2, x3, y3);
        while(szdown > 2 && ar >= 0){
            int hold = down[szdown-1];
            down.pop_back(); down.pop_back(); down.PB(hold);
            szdown--;
            if(szdown <= 2) break;
            x1 = a[down[szdown-3]].x, y1 = a[down[szdown-3]].y, x2 = a[down[szdown-2]].x, y2 = a[down[szdown-2]].y, x3 = a[down[szdown-1]].x, y3 = a[down[szdown-1]].y;
            ar = Area(x1, y1, x2, y2, x3, y3);
        }
    }

    map <int, int> mp;

    for(auto it : up) ++mp[it];
    for(auto it : down) ++mp[it];

    int sz = 0;
    for(auto it : mp) ++sz;
    cout << sz << nl;
    for(auto it : mp) cout << a[it.F].x << sp << a[it.F].y << nl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    ConvexHull();

    return 0;
}


