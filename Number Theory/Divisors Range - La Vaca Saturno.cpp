#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;

vector <int> divisors[N], pos[N];

void getDivisors(){
    for(int i = 1; i < N; i++){
        for(int j = i; j < N; j += i){
            divisors[j].push_back(i);
        }
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector <int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        pos[v[i]].push_back(i+1);
    } 
    while(q--){
        int k, l, r;
        cin >> k >> l >> r;
        ll ans = 0;
        while(k > 1 && l <= r){
            int next = r + 1, div = 0;
            for(auto x : divisors[k]){
                if(pos[x].empty()) continue;
                auto it = lower_bound(pos[x].begin(), pos[x].end(), l);
                if(it == pos[x].end() || *it > r) continue;
                if(*it < next) next = *it, div = x;
            }
            if(div == 0) break;
            ans += (ll) (next - l) * k;
            while(k % div == 0) k /= div;
            l = next;
        }
        if(l <= r) ans += ll(r - l + 1) * k;
        cout << ans << "\n";
    }
    for(int i = 0; i < n; i++) pos[v[i]].clear();
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    getDivisors();
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/2094/problem/H