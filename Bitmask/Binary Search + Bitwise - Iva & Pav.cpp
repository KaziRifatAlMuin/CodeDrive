#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define SetBit(x, k) (x |= (1ll << k))
#define ClearBit(x, k) (x &= ~(1ll << k))
#define CheckBit(x, k) ((x >> k) & 1ll)
#define to_Binary(n) bitset<sizeof(n) * 1>(n).to_string()

void solve() {
    ll n;
    cin >> n;
    vector <ll> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        // cout << to_Binary(v[i]) << "\n";
    }
    int q; cin >> q;
    vector <vector<ll>> pre(n+1, vector <ll> (32, 0));
    for(int j = 0; j < 32; j++){
        for(int i = 1; i <= n; i++){
            pre[i][j] = pre[i-1][j] + CheckBit(v[i-1], j);
        }
    }

    while(q--){
        int l, k;
        cin >> l >> k;
        if(k > v[l-1]) cout << -1 << " ";
        else{
            ll low = l+1, high = n, r = l;
            while(low <= high){
                ll mid = low + (high - low) / 2;
                bool ok = false; // TTTTTFFFFF
                ll p = 0; // stores bitwise and of the segment
                for(int j = 0; j < 32; j++){
                    if(CheckBit(v[l-1], j) && pre[mid][j] - pre[l][j] == (mid - l)) p += (1 << j); // that bit is set
                    // Checks till which index we have consecutive 1's
                }
                // cout << "[" << p << "," << mid << "] ";
                if(p >= k) ok = true;
                if(ok) low = mid + 1, r = mid;
                else high = mid - 1;
            }
            cout << r << " ";
        }
        // cout << "\n";
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
// https://codeforces.com/contest/1878/problem/E