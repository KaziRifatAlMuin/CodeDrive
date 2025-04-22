#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// We use a binary trie (prefix tree) of up to 30 bits per number (since a_i ≤ 10^9 < 2^30).
// Each node has two children (bit 0 and bit 1) and a count of how many numbers pass through it.
const int N = 200000 * 31; // worst‐case number of trie nodes
int trie[N][2];   // trie[node][0 or 1] = child index (0 if none)
int cnt[N];       // cnt[node] = how many inserted numbers go through this node
int tot;          // total nodes allocated so far

int newNode() {
    ++tot;
    trie[tot][0] = trie[tot][1] = 0; // 0 means empty
    cnt[tot] = 0;
    return tot;
}

// Initialize the trie by resetting node count and creating the root at index 1.
void initTrie() {
    tot = 0;
    newNode();  // this makes node 1 our root
}

// Insert or remove one occurrence of integer x into the trie.
// If delta = +1, we insert; if delta = -1, we remove.
void addNumber(int x, int delta) {
    int node = 1;                   // start at root
    for(int bit = 29; bit >= 0; --bit) {
        int b = (x >> bit) & 1;     // extract the current bit (0 or 1)
        if(!trie[node][b]) {
            trie[node][b] = newNode();
        }
        node = trie[node][b];       // move into the child
        cnt[node] += delta;         // update the count along this path
    }
}

// Query the maximum XOR we can get by pairing x with any number currently in the trie.
// We greedily try to go down the opposite bit at each level to maximize XOR.
int maxXorWith(int x) {
    int node = 1;
    int answer = 0;
    for(int bit = 29; bit >= 0; --bit) {
        int b = (x >> bit) & 1;
        int want = b ^ 1; // to get opposite bit
        if(trie[node][want] != 0 && cnt[ trie[node][want] ] > 0) {
            // We can go that way, and we set the corresponding bit in the answer.
            answer |= (1 << bit);
            node = trie[node][want];
        }
        else {
            // Otherwise, we must go down the same bit branch.
            node = trie[node][b];
        }
    }
    return answer;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    initTrie();
    int ans = n + 1;   // store the minimum beautiful‐subarray length found
    int left = 0;      // sliding‐window left index

    // Expand the window's right end from 0 to n−1
    for(int right = 0; right < n; right++) {
        addNumber(a[right], +1); // Add the new element a[right] into the trie
        // While the current window [left..right] has some pair with XOR ≥ k,
        // try to shrink from the left to find the minimal window ending at 'right'.
        while(left <= right && maxXorWith(a[right]) >= k) {
            ans = min(ans, right - left + 1);
            addNumber(a[left], -1); // Remove a[left] and move left boundary forward
            left++;
        }
    }
    if(ans > n) ans = -1;
    cout << ans << "\n";
} 

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/2093/problem/G