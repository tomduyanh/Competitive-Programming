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

struct Trie{
    struct Node{
        int cnt, child[26], exist;
    }nodes[N];
    int cur;
    Trie() : cur(0){
        memset(nodes[0].child, -1, sizeof(nodes[0].child));
        nodes[0].cnt = nodes[0].exist = 0;
    }
    int new_node(){
        cur++;
        memset(nodes[cur].child, -1, sizeof(nodes[cur].child));
        nodes[cur].cnt = nodes[cur].exist = 0;
        return cur;
    }
    void add_str(string s){
        int pos = 0;
        for(auto f : s){
            int c = f - 'a';
            if(nodes[pos].child[c] == -1) nodes[pos].child[c] = new_node();
            pos = nodes[pos].child[c];
            nodes[pos].cnt++;
        }
        nodes[pos].exist++;
    }
    bool Find(string s){
        int pos = 0;
        for(auto f : s){
            int c = f - 'a';
            if(nodes[pos].child[c] == -1) return false;
            pos = nodes[pos].child[c] ;
        }
        return (nodes[pos].exist != 0);
    }
}trie;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    int n;
    cin >> n;
    while(n--){
        string s; cin >> s;
        trie.add_str(s);
    }
    cin >> n;
    while(n--){
        string s; cin >> s;
        cout << trie.Find(s) << nl;
    }

    return 0;
}

