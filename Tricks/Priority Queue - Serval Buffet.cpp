#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, k; 
    cin >> n >> k;
    vector <int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    ll ans = 0, faka = k;
    priority_queue <int> q;
    for(int i = n - k - 1; i >= 0; i--){
        if(faka >= k){
            q.push(-v[i]);
            faka -= k;
            ans += v[i];
        }
        else{
            faka++;
            if(!q.empty()){
                ll choice = abs(q.top());
                if(v[i] > choice){
                    q.pop();
                    q.push(-v[i]);
                    ans = ans - choice + v[i];
                }
            }
        }
        // cout << i << " " << ans << "\n";
    }
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
// https://codeforces.com/contest/2085/problem/D