#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define SetBit(x, k) ((x) |= (1ll << (k)))
#define ClearBit(x, k) ((x) &= ~(1ll << (k)))
#define CheckBit(x, k) (((x) >> (k)) & 1)
#define to_Binary(n) bitset<sizeof(n) * 2>(n).to_string()
inline ll rangeAND(ll L, ll R) {int shift = 0; for(; L < R; shift++, L >>= 1, R >>= 1); return L << shift;}

void solve(){
    ll n, x;
    cin >> n >> x;
    bool ok = true;
    int lim = 0, flag = 0;
    for(int i = 0; i <= 62; i++){
        if(CheckBit(n, i) == 0 && CheckBit(x, i) == 1) ok = false;
    }
    if(!ok) cout << -1 << "\n";
    else{
        ll low = n, high = 5e18, ans = -1;
        // >>>>>>>=====<<<<<<<<
        while(low <= high){
            ll mid = low + (high - low) / 2;
            if(rangeAND(n, mid) > x) low = mid + 1;
            else  if(rangeAND(n, mid) < x) high = mid - 1;
            else ans = mid, high = mid - 1;
        }
        cout << ans << "\n";
    }
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
// https://codeforces.com/contest/1775/problem/C