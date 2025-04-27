#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// greater for descending, less_equal for muiltiset
typedef long long ll;


void solve(){
    int n; 
    cin >> n;
    vector <int> v(n), temp;
    map <int, int> mp, cnt;
    pbds <int> oset;
    bool ok = false;
    for(int i = 0; i < n; i++){
        cin >> v[i]; cnt[v[i]]++;
        oset.insert(v[i]);
    }
    for(auto [x,y] : cnt){
        if(y >= 4) ok = true;
        if(y >= 2) temp.push_back(x);
    }
    for(int i = 1; i < temp.size(); i++){
        if(oset.order_of_key(temp[i]) - oset.order_of_key(temp[i-1]) == temp[i] - temp[i-1]) ok = true;
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
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
// https://codeforces.com/contest/2098/problem/C