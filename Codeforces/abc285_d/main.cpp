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
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int n;
pair <string, string> inp[N];
map <string, int> name;
vector <int> adj[2*N];
int status[2*N] = {0};
bool ans = true;

void DFS(int node){
    if(status[node] == 1) ans = false;
    if(!ans || status[node] == 2) return;
    status[node] = 1;
    for(auto nxt : adj[node]){
        DFS(nxt);
    }
    status[node] = 2;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> inp[i].F >> inp[i].S;
        name[inp[i].F] = 1;
        name[inp[i].S] = 1;
    }

    int cnt = 0;
    for(auto it : name) name[it.F] = ++cnt;

    for(int i = 1;  i <= n; ++i){
        int x = name[inp[i].F], y = name[inp[i].S];
        adj[x].PB(y);
    }

    for(int i = 1; i <= n; ++i){
        if(status[i] == 2) continue;
        DFS(i);
    }

    if(ans) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}

