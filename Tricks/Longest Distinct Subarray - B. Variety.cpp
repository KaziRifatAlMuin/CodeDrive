#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector <int> v(n), freq(n+5), len(n+1);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        freq[v[i]]++;
    }
    int ix, maxi = len[0] = (freq[v[0]] == 1);
    for(int i = 1; i < n; i++){
        if(freq[v[i]] == 1){
            len[i] = len[i-1] + 1;
            if(len[i] > maxi){
                maxi = len[i];
                ix = i;
            }        
        }
    }
    if(maxi == 0) cout << 0 << "\n";
    else cout << ix - maxi + 2 << " " << ix + 1 << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    while(t--){
        solve();
    }
    // cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/2064/problem/B