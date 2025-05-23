#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Trie {

public:

    //N is number of possible characters in a string
    const static int N = 4;

    //baseChar defines the base character for possible characters
    //like '0' for '0','1','2'... as possible characters in string 
    const static char baseChar = 'A';

    int index(char c){
        if(c == 'A') return 0;
        if(c == 'C') return 1;
        if(c == 'G') return 2;
        return 3; // T
    }

    struct TrieNode
    {
        int next[N];
        //if isEnd is set to true , a string ended here
        bool isEnd;
        //freq is how many times this prefix occurs
        int freq;

        TrieNode()
        {
            for(int i=0;i<N;i++)
                next[i] = -1;
            isEnd = false;
            freq = 0;
        }
    };

    //the implementation is via vector and each position in this vector
    //is similar as new pointer in pointer type implementation
    vector <TrieNode> tree;

    //Base Constructor
    Trie ()
    {
        tree.push_back(TrieNode());
    }

    //inserting a string in trie
    void insert(const string &s)
    {
        int p = 0;
        tree[p].freq++;
        for(int i=0;i<s.size();i++)
        {
            int id = index(s[i]);
            if(tree[p].next[id] == -1)
            {
                tree.push_back(TrieNode());
                tree[p].next[id] = tree.size() - 1;
            }
            p = tree[p].next[id];
            tree[p].freq++;
        }
        tree[p].isEnd = true;
    }

    //check if a string exists as prefix
    bool checkPrefix(const string &s)
    {
        int p = 0;
        for(int i=0;i<s.size();i++)
        {
            if(tree[p].next[s[i]-baseChar] == -1)
                return false;

            p = tree[p].next[s[i]-baseChar];
        }
        return true;
    }

    //check is string exists
    bool checkString(const string &s)
    {
        int p = 0;
        for(int i=0;i<s.size();i++)
        {
            if(tree[p].next[s[i]-baseChar] == -1)
                return false;

            p = tree[p].next[s[i]-baseChar];
        }

        return tree[p].isEnd;
    }

    ll getcount(int node){
        return tree[node].freq;
    }

    int getChild(int node, int i) {
        return tree[node].next[i];
    }
};

ll ans = 0;
Trie trie;

void dfs(ll node, ll len){
    ans = max(ans, trie.getcount(node) * len);
    for(int i = 0; i < 4; i++){
        int child = trie.getChild(node, i);
        if(child != -1) dfs(child, len + 1);
    }
}

void solve()
{
    trie = Trie();
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        trie.insert(s);
    }
    ans = 0;
    dfs(0, 0);
    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock(), cs = 1;
    cin >> t;
    while(t--){
        cout << "Case " << cs++ << ": ";
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://lightoj.com/problem/dna-prefix