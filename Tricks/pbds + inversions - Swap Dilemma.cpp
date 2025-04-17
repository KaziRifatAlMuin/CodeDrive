#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// greater for descending, less_equal for muiltiset
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector <int> a(n), b(n);
    set <int> seta, setb;
    for(int i = 0; i < n; i++) cin >> a[i], seta.insert(a[i]);
    for(int i = 0; i < n; i++) cin >> b[i], setb.insert(b[i]);
    ll inv_a = 0, inv_b = 0; // Counting number of inversions
    pbds <int> setA, setB;
    for(int i = n - 1; i >= 0; i--){
        inv_a += setA.order_of_key(a[i]); // inversions or smaller elements in right less than a[i]
        setA.insert(a[i]);
    }
    for(int i = n - 1; i >= 0; i--){
        inv_b += setB.order_of_key(b[i]); // inversions or smaller elements in right less than b[i]
        setB.insert(b[i]);
    }
    if(seta == setb && abs(inv_a - inv_b) % 2 == 0) cout << "YES\n";
    else cout << "NO\n";
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
// https://codeforces.com/contest/1983/problem/D