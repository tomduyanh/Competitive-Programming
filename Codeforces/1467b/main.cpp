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
int a[N], b[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    int t; cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; ++i){
            cin >> a[i];
            b[i] = b[i-1] = b[i+1] = 0;
        }
        int ans = 0;
        for(int i = 2; i < n; ++i){
            if(a[i-1] < a[i] && a[i] > a[i+1]) b[i] = 1; ///hill
            if(a[i-1] > a[i] && a[i] < a[i+1]) b[i] = 2; ///valley
            if(b[i]) ++ans;
        }
        int mx = 0;
        for(int i = 2; i < n; ++i){
            if(b[i] == 0)
                if((b[i-1] == 1 && b[i+1] == 2) || (b[i-1] == 2 && b[i+1] == 1)) mx = max(mx, 1);
            if(b[i] == 1){
                if(b[i-1] == 0 && b[i+1] == 0) mx = max(mx, 1);
                if((b[i-1] == 0 && b[i+1] == 2) || (b[i-1] == 2 && b[i+1] == 0)){
                    if(b[i-1] == 0){
                        if(i - 1 == 1) mx = max(mx, 2);
                        else if(a[i-2] < a[i-1]){
                            if(a[i-1] == a[i+1]) mx = max(mx, 2);
                            else mx = max(mx, 1);
                        }
                        else mx = max(mx, 2);
                    }
                    if(b[i+1] == 0){
                        if(i + 1 == n) mx = max(mx, 2);
                        else if(a[i+2] < a[i+1]){
                            if(a[i+1] == a[i-1]) mx = max(mx, 2);
                            else mx = max(mx, 1);
                        }
                        else mx = max(mx, 2);
                    }
                }
                if(b[i-1] == b[i+1] && b[i-1] == 2) mx = max(mx, 3);
            }
            if(b[i] == 2){
                if(b[i-1] == 0 && b[i+1] == 0) mx = max(mx, 1);
                if((b[i-1] == 0 && b[i+1] == 1) || (b[i-1] == 1 && b[i+1] == 0)){
                    if(b[i-1] == 0)
                }
                if(b[i-1] == b[i+1] && b[i-1] == 1) mx = max(mx, 3);
            }
        }
//        cout << nl;
        ans = ans - mx;
        cout << ans << nl;
    }

    return 0;
}

