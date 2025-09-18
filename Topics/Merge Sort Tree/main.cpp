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

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int n;
int a[N];
vector <int> seg[4*N];

void build(int id, int l, int r){
    if(l == r){
        seg[id] = vector <int> (1, a[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    merge(seg[id*2].begin(), seg[id*2].end(), seg[id*2+1].begin(), seg[id*2+1].end(), back_inserter(seg[id]));
}

int query(int id, int l, int r, int u, int v){

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    build(1, 1, n);

    return 0;
}
