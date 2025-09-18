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

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int n, a[N];
int nxt[N], pre[N];
ll s[N], seg[4*N][2];
///seg[i][0] = max
///seg[i][1] = min

void build(int id, int lo, int hi, int state){
    if(lo == hi){
        seg[id][state] = s[lo];
        return;
    }
    int mid = (lo + hi) / 2;
    build(id*2, lo, mid, state);
    build(id*2+1, mid+1, hi, state);
    if(state == 0) seg[id][state] = max(seg[id*2][state], seg[id*2+1][state]);
    if(state == 1) seg[id][state] = min(seg[id*2][state], seg[id*2+1][state]);
}

ll get(int id, int l, int r, int u, int v, int state){
    if(v < l || r < u){
        if(state == 0) return -INF;
        if(state == 1) return INF;
    }
    if(u <= l && r <= v) return seg[id][state];
    int mid = (l + r) / 2;
    if(state == 0) return max(get(id*2, l, mid, u, v, state), get(id*2+1, mid+1, r, u, v, state));
    if(state == 1) return min(get(id*2, l, mid, u, v, state), get(id*2+1, mid+1, r, u, v, state));
}

void nextGreater(){
	stack<int> st;
	for (int i = 1; i <= n; ++i) {
		while(!st.empty() && a[st.top()] < a[i]) {
			nxt[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
}

void prevGreater(){
    stack <int> st;
	for (int i = n; i > 0; i--) {
		while (!st.empty() && a[st.top()] < a[i]) {
			pre[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
}

bool solve(){
    cin >> n;
    a[1] = 0; n += 2;
    for(int i = 1; i <= n; ++i){
        if(2 <= i && i <= n - 1) cin >> a[i];
        s[i] = s[i-1] + a[i];
        pre[i] = 0;
        nxt[i] = n + 1;
    }
//    cout << nl;
    for(int i = 1; i <= 4*n; ++i){
        seg[i][0] = -INF;
        seg[i][1] =  INF;
    }
    build(1, 1, n, 0);
    build(1, 1, n, 1);
    nextGreater();
    prevGreater();
    /*
    for(int i = 1; i <= n; ++i){
        cout << pre[i] << sp << nxt[i] << nl;
    }
    cout << nl;
    */
    for(int i = 1; i <= n; ++i){
        ll sumL = get(1, 0, n, pre[i] + 1, i - 1, 1);
        ll sumR = get(1, 0, n, i - 1, nxt[i] - 1, 0);
        cout << pre[i] << sp << nxt[i] << nl;
        cout << sumL << sp << sumR << nl;
        sumL = s[i-1] - sumL;
        sumR = sumR - s[i];
        if(i - 1 - (pre[i] + 1) <= 0) sumL = 0;
        if(nxt[i] - 1 - (i - 1) <= 0) sumR = 0;

        cout << sumL << sp << sumR << nl;
        cout << nl;
        if(max(sumL, sumR) > 0){
            return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    int t; cin >> t;
    while(t--) cout << (solve() ? "YES\n" : "NO\n");

    return 0;
}
