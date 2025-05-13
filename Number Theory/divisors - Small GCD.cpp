#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;

vector <int> divs[N];
vector <ll> cnt(N), tmp(N);

void pre(){
    for(int i = 1; i < N; i++){
        for(int j = i; j < N; j += i){
            divs[j].push_back(i);
        }
    }
    for(int i = 1; i < N; i++) sort(divs[i].rbegin(), divs[i].rend());
}

void solve()
{
    int n; cin >> n;
    vector <ll> v(n);
    for(ll i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    ll ans = 0, rem = n;
    for(int i = 0; i < N; i++) cnt[i] = 0;
    for(auto x : v){
        rem--;
        for(auto d : divs[x]){
            ll prev = cnt[d] - tmp[d]; // number of elements in prefix with gcd d
            for(auto d2 : divs[d]){
                tmp[d2] += prev; // subtract divisors of gcd to avoid overcounting
            }
            ans += (d * prev * rem); // d = gcd, prev * rem = # of triples        
        }
        for(auto d : divs[x]){
            cnt[d]++; // adding divisor count for prefix of next
            for(auto d2 : divs[d]) tmp[d2] = 0; // reseting tmp for next gcd candidate
        }

    }
    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    pre();
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/problemset/problem/1900/D