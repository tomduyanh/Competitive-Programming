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
bool ok = false;

void sol2(int i){
    for(; i < n; ++i){
        if(a[i] == 3 || a[i] == 7){
            cout << "YES\n";
            cout << a[i] << 2;
            ok = true;
            return;
        }
        if(a[i] == 1 || a[i] == 5 || a[i] == 9){
            for(int j = i + 1; j < n; ++j){
                if(a[j] % 2){
                    cout << "YES\n";
                    cout << a[j] << a[i] << 2;
                    ok = true;
                    return;
                }
            }
        }
    }
}

void sol4(int i){
    for(; i < n; ++i){
        if(a[i] == 2 || a[i] == 6){
            cout << "YES\n";
            cout << a[i] << 4;
            ok = true;
            return;
        }
        if(a[i] == 8 || a[i] == 4 || a[i] == 0){
            for(int j = i + 1; j < n; ++j){
                if(a[j] % 2){
                    cout << "YES\n";
                    cout << a[j] << a[i] << 4;
                    ok = true;
                    return;
                }
            }
        }
    }
}

void sol6(int i){
    for(; i < n; ++i){
        if(a[i] == 1 || a[i] == 5 || a[i] == 9){
            cout << "YES\n";
            cout << a[i] << 6;
            ok = true;
            return;
        }
        if(a[i] == 3 || a[i] == 7){
            for(int j = i + 1; j < n; ++j){
                if(a[j] % 2){
                    cout << "YES\n";
                    cout << a[j] << a[i] << 6;
                    ok = true;
                    return;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    string s; cin >> s;
    n = s.size();
    for(int i = 0; i < n; ++i) a[i] = s[i] - '0';
    reverse(a, a+n);
    /*
    for(int i = 0; i < n; ++i) cout << a[i] << sp;
    cout << nl;
    */
    for(int i = 0; i < n; ++i){
        if(a[i] == 0 || a[i] == 8) {
            cout << "YES\n" << a[i];
            return 0;
        }
    }

    for(int i = 0; i < n; ++i){
        if(a[i] == 2) sol2(i+1);
        if(a[i] == 4) sol4(i+1);
        if(a[i] == 6) sol6(i+1);
        if(ok) return 0;
    }

    cout << "NO";

    return 0;
}
