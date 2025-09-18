#include <bits/stdc++.h>
using namespace std;
int n, ans = 0, mx = 0;
string a[(int)1e6+1];
struct Trie{
    struct Node{
        int child[26],exist, cnt;
    }nodes[(int)1e6+1];
    int cur;
    Trie() : cur(0) {
        memset(nodes[0].child, -1, sizeof(nodes[cur].child));
        nodes[0].exist = nodes[0].cnt = 0;
    };
    int new_node() {
        ++ans;
        cur++;
        memset(nodes[cur].child, -1, sizeof(nodes[cur].child));
        nodes[cur].exist = nodes[cur].cnt = 0;
        return cur;
    }
    void add_string(string s) {
        int pos = 0; mx = max(mx, (int)s.size());
        for (int i = 0; i < s.size(); ++i) {
            int c = s[i] - 'a';
            if (nodes[pos].child[c] == -1) nodes[pos].child[c] = new_node();
            pos = nodes[pos].child[c];
            nodes[pos].cnt++;
        }
        nodes[pos].exist++;
    }
}trie;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i){
        string s; cin >> s;
        trie.add_string(s);
    }
    cout << ans * 2 - mx + n;
    return 0;
}
