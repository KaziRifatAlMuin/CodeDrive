#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;

void solve(){
    int n; cin >> n;
    vector <int> odd, even, ans;
    for(int i = 1; i <= n; i++){
        int a; cin >> a;
        if(i & 1) odd.push_back(a);
        else even.push_back(a);
    }

    ll inv_odd = 0, inv_even = 0; // Counting number of inversions
    pbds <int> setodd, seteven;
    for(int i = odd.size() - 1; i >= 0; i--){
        inv_odd += setodd.order_of_key(odd[i]); // inversions or smaller elements in right
        setodd.insert(odd[i]);
    }
    for(int i = even.size() - 1; i >= 0; i--){
        inv_even += seteven.order_of_key(even[i]); // inversions or smaller elements in right
        seteven.insert(even[i]);
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());

    for(int i = 1, j = 0, k = 0; i <= n; i++){
        if(i & 1) ans.push_back(odd[j++]);
        else ans.push_back(even[k++]);
    }
    if(inv_odd % 2 != inv_even % 2) swap(ans[n-1], ans[n-3]);
    for(auto x : ans) cout << x << " ";
    cout << "\n";
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
// https://codeforces.com/contest/2102/problem/D