#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

// Fenwrick Tree or Binary Indexed Tree (BIT)
vector <ll> bit; // 1 based index
int n;

void add(int ix, int x){
    for(int i = ix; i <= n; i += (i & -i)) bit[i] += x;
}

ll getsum(int ix){
    ll sum = 0;
    for(int i = ix; i > 0; i -= (i & -i)) sum += bit[i];
    return sum;
}

void solve(){
    int q;
    cin >> n >> q;
    vector <int> v(n);
    bit.assign(n+1, 0);
    for(int i = 0; i < n; i++) cin >> v[i], add(i+1, v[i]);
    while(q--){
        int opt; cin >> opt;
        if(opt == 1){
            int i, x;
            cin >> i >> x;
            add(i+1, x - v[i]); // 0-based to 1-based
            v[i] = x;
        }
        else{
            int l, r;
            cin >> l >> r;
            ++l;
            cout << getsum(r) - getsum(l-1) << "\n";
        }
    }
}
    

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    // cin >> t;
    while(t--){
        solve();
    }
    cerr << "tTime : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/A