#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const mod = 1e9 + 7;
#define CheckBit(x, k) ((x >> k) & 1ll)

bool NimGame(vector <ll> v){
    ll nimsum = 0;
    for(auto x : v) nimsum ^= x;
    return nimsum != 0; // Alice win, If last pick win
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector <ll> v(m), h(n), jinish(n);
    for(int i = 0; i < n; i++) cin >> h[i];
    for(int i = 0; i < m; i++) cin >> v[i];
    reverse(v.begin(), v.end());
    for(int j = 0; j < n; j++) {
        ll marked = 0;
        for(ll mask = 1; mask < 1ll << m; mask++){
            vector <ll> taken;
            for(int i = 0; i < 32; i++){
                if(CheckBit(mask, i)) taken.push_back(v[i]);
            }
            ll lcm = taken[0], ok = 1;
            for(int i = 1; i < taken.size(); i++){
                lcm = (lcm * taken[i]) / __gcd(lcm, taken[i]);
            }
            if(taken.size() & 1) marked += (h[j] / lcm);
            else marked -= (h[j] / lcm);
        }
        jinish[j] = marked + 1;
    }
    if(NimGame(jinish)) cout << "Alice\n";
    else cout << "Bob\n";
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
// https://toph.co/p/towers-of-doom