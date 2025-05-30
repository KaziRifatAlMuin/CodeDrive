#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector <pair<int,int>> v;
    while(n--){
        int k; cin >> k;
        int maxi = 0;
        for(int i = 0; i < k; i++){
            int a; cin >> a;
            maxi = max(maxi, a - i);
        }
        v.push_back({maxi, k});
    }
    sort(v.begin(), v.end());
    n = v.size();
    int low = 1, high = 1e9 + 7, ans = 0;
    while(low <= high){ // FFFFTTTT
        int mid = low + (high - low) / 2;
        bool ok = true;
        int hero = mid;
        for(auto [a, k] : v){
            if(a >= hero) ok = false;
            hero += k;
        }
        if(ok) ans = mid, high = mid - 1;
        else low = mid + 1;
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
// https://codeforces.com/problemset/problem/1561/C