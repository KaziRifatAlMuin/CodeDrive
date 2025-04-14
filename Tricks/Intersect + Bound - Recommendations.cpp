#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;
    vector <array<int,3>> v;
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        v.push_back({l, r, i});
    }
    sort(v.begin(), v.end());
    multiset <int> st;
    vector <int> ans(n,0);
    vector <bool> check(n,false);
    for(int i = 0; i < n; i++){
        auto [l, r, ix] = v[i];
        if(!check[i]){
            st.insert(r); check[i] = true;
            for(int j = i + 1; j < n; j++){
                if(v[j][0] == v[i][0]){
                    st.insert(v[j][1]); 
                    check[j] = true;
                }
                else break;
            }
        }
        auto it = next(st.lower_bound(r));
        if(it != st.end()) ans[ix] += (*it - r);
    }

    sort(v.begin(), v.end(), [&](array<int, 3> a1, array<int, 3> a2) {
        return a1[1] > a2[1]; // sort as bigger R first
    });

    st.clear();
    check.assign(n, false);
    for(int i = 0; i < n; i++){
        auto [l, r, ix] = v[i];
        if(!check[i]){
            st.insert(l); check[i] = true;
            for(int j = i + 1; j < n; j++){
                if(v[j][1] == v[i][1]){
                    st.insert(v[j][0]); 
                    check[j] = true;
                }
                else break;
            }
        }
        auto it = prev(st.upper_bound(l));
        if(it != st.begin()){
            --it;
            ans[ix] += (l - *it);
        }
    }
    for(int i = 0; i < n; i++) cout << ans[i] << "\n";
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
// https://codeforces.com/problemset/problem/2042/D