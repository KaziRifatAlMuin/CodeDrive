#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define setBit(x, k) (x |= (1ll << k))
#define clearBit(x, k) (x &= ~(1ll << k))
#define checkBit(x, k) ((x >> k) & 1ll)
#define toggleBit(n, i) (n ^ (1LL << i))
int const mod = 998244353;

void solve()
{
    int n;
    cin >> n;
    vector <int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    int bits[31][n+1];
    memset(bits, 0, sizeof(bits));
    for(int i = 0; i < 31; i++){
        for(int j = 1; j <= n; j++){
            bits[i][j] = bits[i][j-1] ^ checkBit(v[j-1], i);
        }
    }
    ll ans = 0;
    for(int i = 0; i < 31; i++){
        ll odd = 0, even = 0, oddSum = 0, evenSum = 0, total = 0;
        for(int j = n; j >= 0; j--){
            if(bits[i][j]){
                total = ((total + evenSum - even * j) % mod + mod) % mod;
                oddSum += j;
                odd++;
            }
            else{
                total = ((total + oddSum - odd * j) % mod + mod) % mod;
                evenSum += j;
                even++;
            }
        }
        ans = (ans + (total * (1ll << i)) % mod) % mod;
    }
    cout << ans << "\n";
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
// https://codeforces.com/contest/1879/problem/D