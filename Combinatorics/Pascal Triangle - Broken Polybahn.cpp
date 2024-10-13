#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const mod = 1e9 + 7;
int const N = 2e5 + 7;

ll power(ll a, ll b) {
    ll result = 1;
    a = a % mod;
    while (b > 0){
        if (b & 1) result = (result * a) % mod;
        a = (a * a) % mod;
        b >>= 1ll;
    }
    return result;
}

void solve()
{
    ll n;
    cin >> n;
    ll ans = 0;
    map <ll, ll> deg;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }
    for(int i = 1; i <= n; i++){
        if(deg[i] > 1){
            ans = (((ans + power(2, deg[i]) - deg[i] - 1) % mod) + mod) % mod;
        }
    }
    cout << (ans + n - 1) % mod << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
// https://codeforces.com/gym/105167/problem/B