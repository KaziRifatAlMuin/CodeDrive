#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int N = 1e7 + 5;
int spf[N];

void sieve() {
    for(int i = 1; i < N; i++) spf[i] = i; // smallest prime factor
    for(int i = 2; i * i < N; i++) {
        if(spf[i] == i) { // i is a prime, not marked by its smaller
            for(int j = i * i; j < N; j += i) {
                if(spf[j] == j) spf[j] = i; // not marked yet, so i will be spf
            }
        }
    }
}

vector<pair<int, int>> factor(int n) {
    vector<pair<int, int>> res;
    while(n > 1) {
        int p = spf[n], cnt = 0;
        while (n % p == 0) n /= p, cnt++;
        res.push_back({p, cnt});
    }
    return res;
}

void solve() {
    vector<pair<int, int>> v = factor(282390);
    for(auto [x, y] : v){
        cout << x << " " << y << "\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    // cin >> t;
    sieve();
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}