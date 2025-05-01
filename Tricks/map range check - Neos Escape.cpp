#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

void solve(){
    int n;
    cin >> n;
    vector <int> v(n);
    map <int, vector <int>> pos;
    vector <bool> done(n+3);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        pos[-v[i]].push_back(i+1);
    }
    ll bot = 0;
    for(auto [x, id] : pos){
        int m = id.size();
        for(int l = 0; l < m;){
            int r = l + 1;
            bool ok = done[id[l]];
            while(r < m && id[r] - id[r-1] == 1) ok |= done[id[r]], r++;
            if(!ok) bot++;
            for(int k = l; k < r; k++){
                int p = id[k];
                done[p-1] = done[p] = done[p+1] = true;
            }
            l = r;
        }
    }
    cout << bot << "\n";
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
// https://codeforces.com/contest/2108/problem/C