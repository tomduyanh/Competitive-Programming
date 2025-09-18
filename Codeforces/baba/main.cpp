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

void sol1(){
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        int pre = a[i], sum = a[i];
        for(int j = i + 1; j <= n; ++j){
            int cur = a[j] - pre;
            sum += a[j], sum %= 3;
            if(!cur && !sum){
                ++ans;
            }
            pre = cur;
        }
    }
    cout << ans;
}

bool compare(string x, string y){
    return x + y > y + x;
}

void sol2(string s){
    vector <pii> pairs;
    int mx_len = 0;
    for(int i = 1; i <= n; ++i){
        int pre = a[i], sum = a[i];
        for(int j = i + 1; j <= n; ++j){
            int cur = a[j] - pre;
            sum += a[j], sum %= 3;
            if(!cur && !sum){
                if(j - i + 1 > mx_len){
                    mx_len = j - i + 1;
                    pairs.clear();
                    pairs.PB({i, j});
                }
                else if(j - i + 1 == mx_len){
                    pairs.PB({i, j});
                }
            }
            pre = cur;
        }
    }
    vector <string> sub;
    for(auto it : pairs){
        int l = it.F, r = it.S;
        sub.PB(s.substr(l-1, r - l + 1));
    }
    if(sub.size() == 0){
        cout << -1;
        return;
    }
    sort(all(sub), compare);
    cout << sub[0];
}

int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    //freop();
    //srand(time(NULL));

    string s; cin >> s; n = s.size();
    FOR(i, n) a[i] = s[i-1] - '0';
    int type; cin >> type;
    if(type == 1) sol1();
    else sol2(s);

    return 0;
}


