#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

void test(){
    vector <ll> fib(50);
    fib[0] = 0, fib[1] = 1;
    for(int i = 2; i < 50; i++) fib[i] = fib[i-1] + fib[i-2];
    for(int j = 1; j <= 20; j++){
        cout << j << " : ";
        for(int i = 1; i < 50; i++){
            if(fib[i] % j == 0) {
                // cout << "(" << i << "," << fib[i] << ") ";
                cout << i << " ";
            }
        }
        cout << "\n";
    }
    // so, g(n,k) = something * n;
    // something = first i where fib[i] % k == 0
}

// If Fi is divisible by k, then for every j, Fi*j is also divisible by k.
// From the property: gcd(Fn, Fm) = Fgcd(n, m)
// Let n = i * j and m = i, then gcd(n, m) = i
// So, gcd(Fn, Fi) = Fi
// Since Fi is divisible by k, and Fi divides Fn, Fn is also divisible by k
// Hence, Fi*j is divisible by k for all j

void solve() {
    ll n, k;
    cin >> n >> k;
    ll a = 0, b = 1, i = 1, next = 1;
    while(k > 1 && next){
        next = (a + b) % k;
        a = b; b = next; i++;
    }
    cout << ((i % mod) * (n % mod)) % mod << "\n";
}

// The Pisano period π(n) is the length of the cycle in the Fibonacci sequence modulo n.
// It satisfies π(n) ≤ 6n, with equality if and only if n = 2·5^k for some k ≥ 1.
// This bound arises from properties of Fibonacci numbers modulo prime powers and their periodicity.
// For more details, see: https://en.wikipedia.org/wiki/Pisano_period

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
// https://codeforces.com/contest/2033/problem/F