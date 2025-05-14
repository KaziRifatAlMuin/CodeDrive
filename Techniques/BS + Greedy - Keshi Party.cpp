#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n; cin >> n;
    vector <int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
    int low = 0, high = n, ans = 0;
    while(low <= high){
        int mid = low + (high - low) / 2;
        int take = 0, poor = 0, rich = mid - 1;
        for(int i = 0; i < n; i++){
            if(poor <= b[i] && rich <= a[i]) poor++, rich--, take++;
        } // TTTTTFFFFF
        if(take >= mid) ans = mid, low = mid + 1;
        else high = mid - 1;
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
    cerr << "tTime : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/problemset/problem/1610/C