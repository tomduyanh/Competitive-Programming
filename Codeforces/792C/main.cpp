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
    freopen(".INP", "r", stdin);
    freopen(".OUT", "w", stdout);
}

int n;
int a[N];

void read() {
    string s; cin >> s;
    n = s.size();
    for(int i = 0; i < n; ++i) a[i+1] = s[i] - '0';
}

void sol(int val) {
    int pos = 0; bool zero = true, ok = false, wth = false;
    for(int i = 1; i <= n; ++i)
        if(!a[i]) {
            ok = true;
            break;
        }
    for(int i = n; i > 0; --i) {
        if(a[i] % 3 == val) {
            pos = i;
            break;
        }
    }
    vector <int> ans;
    if(!pos) {
        wth = true;
        ans.PB(-1);
    }
    for(int i = 1; i <= n && !wth; ++i) {
        if(i == pos) continue;
        if(a[i]) zero = false;
        if(!zero) ans.PB(a[i]);
    }
    if(pos && !wth){
        if(ans.size() == 0) {
            if(!ok) ans.PB(-1);
            else ans.PB(0);
        }
    }
    int pos1 = 0;
    pos = 0, zero = true, val = 3 - val;
    vector <int> ans1;
    for(int i = n; i > 0; --i) {
        if(a[i] % 3 == val) {
            if(!pos) pos = i;
            else {
                pos1 = i;
                break;
            }
        }
    }
    bool bruh = false;
    if((!pos1 || !pos) || (n == 2 && pos1 && pos)){
        ans1.PB(-1);
        bruh = true;
    }
    for(int i = 1; i <= n && !bruh; ++i) {
        if(i == pos1 || i == pos) continue;
        if(a[i]) zero = false;
        if(!zero) ans1.PB(a[i]);
    }
    if(pos1 && pos && !bruh) {
        if(ans1.size() == 0) {
            if(!ok) ans1.PB(-1);
            else ans1.PB(0);
        }
    }
    if(ans[0] == -1 && ans1[0] == ans[0]) {
        cout << -1;
        return;
    }
    if((ans.size() > ans1.size()) || ans1[0] == -1)
        for(auto it : ans) cout << it;
    else
        for(auto it : ans1) cout << it;
    return;
}

void solve() {
    int sum = 0;
    for(int i = 1; i <= n; ++i) sum += a[i];
    if(sum % 3 == 0) {
        for(int i = 1; i <= n; ++i) cout << a[i];
        return;
    }
    if(sum % 3 == 1)  sol(1);
    else sol(2);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();

    read();
    solve();

    return 0;
}
