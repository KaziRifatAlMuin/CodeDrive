#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 1e5 + 7;
#define CheckBit(x, k) ((x >> k) & 1ll)
#define to_Binary(n) bitset<sizeof(n) * 1>(n).to_string()

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector <ll> v(m);
    for(int i = 0; i < m; i++) cin >> v[i];
    reverse(v.begin(), v.end());
    ll marked = 0;
    for(ll mask = 1; mask < 1ll << m; mask++){
        vector <ll> taken;
        for(int i = 0; i < 32; i++){
            if(CheckBit(mask, i)) taken.push_back(v[i]);
        }
        ll lcm = taken[0], ok = 1;
        for(int i = 1; i < taken.size(); i++){
            lcm = (lcm * taken[i]) / __gcd(lcm, taken[i]);
            if(lcm > n) {ok = 0; break;}
        }
        if(!ok) continue;
        if(taken.size() & 1) marked += (n / lcm);
        else marked -= (n / lcm);
        // cout << to_Binary(mask) << " " << n / lcm << " " <<  lcm << " " << marked << "\n";
    }
    cout << n - marked << "\n";
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
// https://lightoj.com/problem/helping-cicada