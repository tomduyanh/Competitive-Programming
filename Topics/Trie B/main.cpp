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

const int N = 9e6 + 5;
const int LG = 31;
const int MOD = 1e9 + 7;
const ll INF = 1e18;

void freop(){
    if(fopen("FILE.INP", "r")){
        freopen("FILE.INP", "r", stdin);
        freopen("FILE.OUT", "w", stdout);
    }
}

struct Trie{
    struct Node{
        int child[2];
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

    void add_number(int x) {
        int pos = 0;
        for (int i = LG; i >= 0; i--) {
            int c = (x >> i) & 1;
            if (nodes[pos].child[c] == -1) nodes[pos].child[c] = new_node();
            pos = nodes[pos].child[c];
            nodes[pos].cnt++;
        }
        nodes[pos].exist++;
    }

    ll Find(int k){
        int pos = 0, sum = 0;
        ll ans = 0;
        for(int i = LG; i > 0; --i){
            if(nodes[pos].child[0] != -1 && nodes[pos].child[1] != -1){
                int nxt1 = nodes[pos].child[1], nxt0 = nodes[pos].child[0];
                if(k <= nodes[nxt0].cnt + sum) pos = nxt0;
                else{
                    pos = nxt1;
                    ans += (1 << i);
                    sum += nodes[nxt0].cnt;
                }
            }
            else{
                if(nodes[pos].child[0] != -1) pos = nodes[pos].child[0];
                else{
                    pos = nodes[pos].child[1];
                    ans += (1 << i);
                }
            }
        }
        return ans;
    }
};

Trie trie;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freop();
    //srand(time(NULL));

    int n; cin >> n;
    while(n--){
        int type, x; cin >> type >> x;
        if(type == 1) trie.add_number(x);
        else cout << trie.Find(x) << nl;
    }

    return 0;
}

