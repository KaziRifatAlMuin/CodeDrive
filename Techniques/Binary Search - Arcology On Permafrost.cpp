#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector <ll> v(n);
    ll rem = m * k;
    ll low = 0, high = n ;
    vector <int> temp(n), ans(n);
    while(low <= high){
        bool ok = true; // TTTTTFFFFF
        vector <int> freq(n+1);
        ll mid = low + (high - low) / 2;
        ll mex = mid; // 0 to mex-1 must appears at least m+1 times
        for(int i = 0; i < n; i += max(k, mex)){
            for(int j = 0; j <= max(k, mex) && i+j < n; j++){
                temp[i+j] = j;
                freq[j]++;
            }
        }
        for(int i = 0; i < mex; i++){
            if(freq[i] < m + 1) ok = false;
        }
        if(ok) ans = temp, low = mid + 1;
        else high = mid - 1;
    }
    for(auto x : ans){
        cout << x << " ";
    }
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
// https://codeforces.com/contest/2084/problem/D