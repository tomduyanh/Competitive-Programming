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

bool found = false;

void DFS(int n, int a, int b, map <ll, bool> valid){
    if(n <= 0) return;
    if(valid[n] == true) found = true;
    if(found) return;
    vis[n] = 1;
    return
    if(n % a == 0 && a != 1){
        DFS(n / a, a, b, vis);
    }
    DFS(n - b, a, b, vis);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    int t; cin >> t;
    while(t--){
        int n, a, b; cin >> n >> a >> b;
        if(b == 1){
            cout << "Yes\n";
            continue;
        }

    }
    return 0;
}
