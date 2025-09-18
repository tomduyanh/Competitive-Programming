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
    freopen("CONVEXHULL.INP", "r", stdin);
    freopen("CONVEXHULL.OUT", "w", stdout);
}

int n, sz = 0;
struct cor{
    int x, y;
}a[N], b[N];
vector <int> up, down;
bool vis[N] = {false};

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
    /*
    cout << nl;
    for(auto it : up) cout << a[it].x << sp << a[it].y << nl;;
    cout << nl;
    for(auto it : down) cout << a[it].x << sp << a[it].y << nl;
    cout << nl;
    */
    vis[1] = true;
    for(auto it : down){
        if(vis[it]) continue;
        ++sz;
        b[sz].x = a[it].x, b[sz].y = a[it].y;
        vis[it] = true;
    }
    reverse(all(up)); vis[1] = false;
    for(auto it : up){
        if(vis[it]) continue;
        ++sz;
        b[sz].x = a[it].x, b[sz].y = a[it].y;
        vis[it] = true;
    }

}

void Solve(){
    double area = 0;
    for(int i = 1; i <= sz; ++i) area += (b[i].x - b[i%sz+1].x) * (b[i].y + b[i%sz+1].y);
    if(area < 0) area = -area;
    int mny = INF, mnxy = INF, lo = 1;
    for(int i = 1; i <= sz; ++i){
        b[i+sz].x = b[i].x; b[i+sz].y = b[i].y;
        mny = min(mny, b[i].y);
    }
    for(int i = 1; i <= sz; ++i)
        if(b[i].y == mny && b[i].x < mnxy){
            lo = i;
            mnxy = b[i].x;
        }
    area = area/2;
    cout << sz << nl;
    cout << fixed << setprecision(1) << area << nl;
    for(int i = lo; i <= sz+lo-1; ++i) cout << b[i].x << sp << b[i].y << nl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freop();
    //srand(time(NULL));

    ConvexHull();
    Solve();

    return 0;
}


