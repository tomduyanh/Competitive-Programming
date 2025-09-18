#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, a[N], s[N];
void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }
    int i = m - 1;
    while(i > 0){

    }
}
int main(){
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
