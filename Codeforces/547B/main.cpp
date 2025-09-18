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

int n;
int a[N];
int lef[N], rig[N];

void read(){
    cin >> n;
    FOR(i, n) cin >> a[i];
}

void getleft(){
    stack <int> st;
    map <int, int> pos;
    for(int i = 1; i <= n; ++i){
        while(!st.empty() && st.top() >= a[i]) st.pop();
        if(st.empty()) lef[i] = 1;
        else lef[i] = pos[st.top()] + 1;
        pos[a[i]] = i;
        st.push(a[i]);
    }
}

void getright(){
    stack <int> st;
    map <int, int> pos;
    for(int i = n; i > 0; --i){
        while(!st.empty() && st.top() >= a[i]) st.pop();
        if(st.empty()) rig[i] = n;
        else rig[i] = pos[st.top()] - 1;
        pos[a[i]] = i;
        st.push(a[i]);
    }
}

bool compare(pii a, pii b){return a.S < b.S;}

void solve(){
    vector <pii> arr;
    vector <int> mx(n+1), ans(n+1);
    for(int i = 1; i <= n; ++i) arr.PB({a[i], rig[i]-lef[i]+1});
    sort(all(arr), compare);
    mx[n-1] = arr[n-1].F;
    for(int i = n - 2; i >= 0; --i) mx[i] = max(mx[i+1], arr[i].F);
    int j = 0;
    for(int i = 1; i <= n; ++i){
        while(arr[j].S < i) ++j;
        ans[i] = mx[j];
    }
    for(int i = 1; i <= n; ++i) cout << ans[i] << sp;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    read();
    getleft();
    getright();
    solve();

    return 0;
}

