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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    int r, g, b; cin >> r >> g >> b;
    int ans = 0;
//    r -= ans, g -= ans, b -= ans;
    vector <int> sus(3);
//    cout << r << sp << g << sp << b << nl;
    sus[0] = r, sus[1] = g, sus[2] = b;
    sort(all(sus));
//    cout << sus[0] << sp << sus[1] << sp << sus[2] << nl;
//    r = sus[1], g = sus[2];
//    int cnt = 0;
    while(sus[0] + sus[1] + sus[2] > 2 && sus[1] && sus[2]){
        int r = sus[0], g = sus[1], b = sus[2];
        int kk = min(g, b / 2);
        sus[1] -= kk;
        sus[2] -= kk * 2;
        sort(all(sus));
        cout << sus[0] << sp << sus[1] << sp << sus[2] << nl;
        ans += kk;
    }
    cout << ans;

    return 0;
}

