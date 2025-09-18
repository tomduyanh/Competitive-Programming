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

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

int n; ll dp[N];
string s;

struct Trie{
    struct Node{
        int child[26];
        int exist, cnt;
    } nodes[N];
    int cur;
    Trie() : cur(0) {
        memset(nodes[0].child, -1, sizeof(nodes[cur].child));
        nodes[0].exist = nodes[0].cnt = 0;
    };
    int new_node() {
        cur++;
        memset(nodes[cur].child, -1, sizeof(nodes[cur].child));
        nodes[cur].exist = nodes[cur].cnt = 0;
        return cur;
    }
    void add_string(string s) {
        int pos = 0;
        for (int i = 0; i < s.size(); ++i) {
            int c = s[i] - 'a';
            if (nodes[pos].child[c] == -1) nodes[pos].child[c] = new_node();
            pos = nodes[pos].child[c];
            nodes[pos].cnt++;
        }
        nodes[pos].exist++;
    }
    void solve(int posS){
        int posTrie = 0, pos = posS;
        for(int i = 1; posS >= 0 && i <= 100; --posS, ++i){
            int c = s[posS] - 'a';
            if(nodes[posTrie].child[c] == -1) return;
            posTrie = nodes[posTrie].child[c];
            if(nodes[posTrie].exist != 0) dp[pos] = (dp[pos] + (posS == 0 ? 1 : dp[posS - 1])) % MOD;
        }
    }
};

Trie trie;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    cin >> n;
    FOR(i, n){
        string x; cin >> x;
        reverse(all(x));
        trie.add_string(x);
    }
    cin >> s;

    n = s.size();

    for(int i = 0; i < n; ++i) trie.solve(i);
    cout << dp[n - 1];

    return 0;
}

