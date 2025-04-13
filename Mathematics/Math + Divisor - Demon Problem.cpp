#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

vector <int> divisors[N];

void getDivisors(){
    for(int i = 1; i < N; i++){
        for(int j = i; j < N; j += i){
            divisors[j].push_back(i);
        }
    }
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector <ll> a(n), b(m);
    ll sumA = 0, sumB = 0;
    for(ll i = 0; i < n; i++) cin >> a[i], sumA += a[i];
    for(ll i = 0; i < m; i++) cin >> b[i], sumB += b[i];
    // f(r,c) = sumAsumB - sumB * ar - sumA * bc + arbc
    // f(r,c) = (sumA - ar) * (sumB - bc)
    vector <bool> posispossible(N+2), negispossible(N+2);
    set <ll> optA, optB;
    for(int i = 0; i < n; i++) optA.insert(sumA - a[i]);
    for(int i = 0; i < m; i++) optB.insert(sumB - b[i]);
    getDivisors();
    for(int k = 1; k < N; k++){
        bool ok = false;
        for(auto x : divisors[k]){
            ll x1 = 0, x2 = 0, y1 = 0, y2 = 0;
            if(optA.count(x) == 1) x1 = x;
            if(optA.count(-x) == 1) x2 = -x;
            if(optB.count(k/x) == 1) y1 = k/x;
            if(optB.count(-k/x) == 1) y2 = -k/x;
            if(x1 * y1 == k || x1 * y2 == k || x2 * y1 == k || x2 * y2 == k) posispossible[k] = true;
            if(x1 * y1 == -k || x1 * y2 == -k || x2 * y1 == -k || x2 * y2 == -k) negispossible[k] = true;
        }
    }
    while(q--){
        ll x; cin >> x;
        if(x < 0 && negispossible[abs(x)] == true) cout << "YES\n";
        else if(x > 0 && posispossible[x] == true) cout << "YES\n";
        else cout << "NO\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    // cin >> t;
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/problemset/problem/2044/F