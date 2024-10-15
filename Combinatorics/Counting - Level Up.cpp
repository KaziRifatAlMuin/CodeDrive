#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
int const mod = 1e9 + 7;

ull power(ull a, ull b) {
    ull result = 1;
    a = a % mod;
    while (b > 0){
        if (b & 1) result = (__int128(result) * a) % mod;
        a = (__int128(a) * a) % mod;
        b >>= 1ull;
    }
    return result;
}

void solve()
{
    ull n, a, b, l;
    cin >> n >> a >> b >> l;
    ull ans;
    ull first, second, rest;
    rest = power(n-1, l-3);
    first = (((b - a) % mod) * ((l - b) % mod)) % mod;
    if(l - b < 2) second = 0;
    else second = ((((l - b) % mod) * ((l - b - 1) % mod)) % mod) / 2;
    ans = (first + second) % mod;
    ans = (ans * rest) % mod;
    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, cs = 1, st = clock();
    cin >> t;
    while(t--){
        cout << "Case " << cs++ << ": ";
        solve();
    }
    // cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://toph.co/p/level-up