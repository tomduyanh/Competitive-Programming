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

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int n, q;
int a[N];
ll lef[N], rig[N];
pll seg[N][2];
///seg[node][0] = lef
///seg[node][1] = rig

void read(){
    cin >> n >> q;
    FOR(i, n) cin >> a[i-1];
    FOR(j, n){
        int i = j - 1;
        lef[i] = a[i] + i;
        rig[n - i - 1] = a[n - i - 1] + i;
    }
}

void add(int node){
    int Lef = lef[node], Rig = rig[node];

}

void addLef(int node, ll val){
    node += n;
    segLef[node].F = val;
    segLef[node].S = node - n;
    for(node /= 2; node > 0; node /= 2){
        segLef[node].F = min(segLef[node*2].F, segLef[node*2+1].F);
        if(segLef[node*2].F >= segLef[node*2+1].F) segLef[node].S = segLef[node*2+1].S;
        else segLef[node].S = segLef[node*2].S;
    }
}

void addRig(int node, ll val){
    node += n;
    segRig[node].F = val;
    segRig[node].S = node - n;
    for(node /= 2; node > 0; node /= 2){
        segRig[node].F = min(segRig[node*2].F, segRig[node*2+1].F);
        if(segRig[node*2].F <= segRig[node*2+1].F) segRig[node].S = segRig[node*2].S;
        else segRig[node].S = segRig[node*2+1].S;
    }
}

void buildST(){
    memset(segLef, INF, sizeof(segLef));
    memset(segRig, INF, sizeof(segRig));
    FOR(i, n) add(i - 1);
}

int queryLef(int lo, int hi){
    int pos = -1; ll ans = INF;
    lo += n, hi += n;
    while(lo <= hi){
        if(lo % 2 == 1){
            if(segLef[lo].F < ans){
                ans = segLef[lo].F;
                pos = segLef[lo].S;
            }
            ++lo;
        }
        if(hi % 2 == 0){
            if(segLef[hi].F < ans){
                ans = segLef[hi].F;
                pos = segLef[hi].S;
            }
            --hi;
        }
        lo /= 2, hi /= 2;
    }
    return pos;
}

int queryRig(int lo, int hi){
    int pos = -1; ll ans = INF;
    lo += n, hi += n;
    while(lo <= hi){
        if(lo % 2 == 1){
            if(segRig[lo].F < ans){
                ans = segRig[lo].F;
                pos = segRig[lo].S;
            }
            ++lo;
        }
        if(hi % 2 == 0){
            if(segRig[hi].F < ans){
                ans = segRig[hi].F;
                pos = segRig[hi].S;
            }
            --hi;
        }
        lo /= 2, hi /= 2;
    }
    return pos;
}

void solve(){
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int k, x; cin >> k >> x;
            addLef(k - 1, x + k - 1);
            addRig(k - 1, x + n - k);
            a[k - 1] = x;
        }
        else{
            int k; cin >> k;
            int posLef = queryRig(0, k - 1), posRig = queryLef(k, n - 1);
            ll valLef = a[posLef] + abs(k - 1 - posLef), valRig = a[posRig] + abs(posRig - k + 1);
            cout << min(valLef, valRig) << nl;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    read();
    buildST();
    solve();

    return 0;
}

