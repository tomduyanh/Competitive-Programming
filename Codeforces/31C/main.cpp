#include <bits/stdc++.h>
using namespace std;


#define PB push_back

struct pii{
    int F, S, id;
};

int n;
pii a[5001], temp[5001];

bool cmp(pii a, pii b){
    return a.F < b.F || (a.F == b.F && a.S > b.S);
}

bool check(){
    int mx = 0;
    for(int i = 1; i < n; ++i){
        if(temp[i].F < mx) return false;
        mx = max(mx, temp[i].S);
    }
    return true;
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i].F >> a[i].S;
        a[i].id = i;
    }
    sort(a+1,a+n+1,cmp);
    vector <int> ans;
    for(int j = 1; j <= n; ++j){
        int m = 0, mx = 0;
        for(int i = 1; i <= n; ++i){
            if(i == j) continue;
            ++m;
            temp[m].F = a[i].F;
            temp[m].S = a[i].S;
        }
        if(check()) ans.PB(a[j].id);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(auto i : ans) cout << i << " ";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
