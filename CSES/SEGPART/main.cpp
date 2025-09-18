#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int,int> pii;
typedef pair <ll , ll> pll;

#define int long long
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

int n, m;
int a[N], s[N];
int dp[N];
map <int, int> val;
int seg[4*N];

o moi vi tri i, tim j < i sao cho tong trong doan s[j->i] <= m && dp[j] la nho nhat
tao mang val[] voi val[s] la ket qua nho nhat co prefix sum la s
su dung segment tree tren doan -INF -> (s - a[i])
s co the lon -> compress
test :
3 1
1 -1 2
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }

    memset(val, INF, sizeof(val));
    memset(seg, INF, sizeof(seg));

    for(int i = 1; i <= n; ++i){

    }

    return 0;
}
