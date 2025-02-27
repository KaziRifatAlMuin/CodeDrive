#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector <ll> v(n);
    string s; cin >> s;
    for(int i = 0; i < n; i++) cin >> v[i];
    ll high = 1e12, low = 0, mid, ans = 0; // min of max = Binary Search
    while(high >= low){ // FFFFTTTT
        mid = (low + high) / 2;
        bool ok = true, blue = false;
        int block = 0;
        for(int i = 0; i < n; i++){
            if(v[i] <= mid) continue;
            else if(s[i] == 'B'){
                if(!blue) blue = true, block++;
            }
            else blue = false;
        }
        if(block > k) ok = false;
        if(ok){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
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
// https://codeforces.com/contest/2070/problem/C