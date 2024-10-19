#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
    int n;
    cin >> n;
    vector <int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    vector <int> dp(n, -1), parent(n, -1);
    for(int i = 0; i < n; i++){
        vector <int> next = dp;
        for(int r = 0; r < n; r++){
            if(dp[r] != -1){
                int new_r = (r + v[i]) % n;
                if(next[new_r] == -1){
                    next[new_r] = i;
                    parent[new_r] = r;
                }
            }
        }
        int new_r = v[i] % n;
        if(next[new_r] == -1){
            next[new_r] = i;
            parent[new_r] = -1;
        }
        dp = next;
    }
    if(dp[0] == -1){
        cout << 0 << "\n";
        return;
    }
    vector <int> subset;
    int r = 0;
    while(dp[r] != -1){
        subset.push_back(v[dp[r]]);
        if(parent[r] == -1) break;
        r = parent[r];
    }
    cout << subset.size() << "\n";
    for(auto x : subset){
        cout << x << "\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    // cin >> t;
    while(t--){
        solve();
    }
    // cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}