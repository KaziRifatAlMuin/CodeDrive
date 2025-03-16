#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 7;

vector <pair<int,int>> facts[N];

void pre(){
    for(int i = 1; i < N; i++){
        int x = i;
        for(int j = 2; (ll) j * j <= x; j++){
            if(x % j == 0){
                int p = 0;
                while(x % j == 0) x /= j, p++;
                facts[i].push_back({j, p});
            }
        }
        if(x > 1) facts[i].push_back({x, 1});
    }
}

void solve() {
    int n;
    cin >> n;
    vector <int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    map <int,int> cnt;
    for(auto x : v){
        for(auto [a,p] : facts[x]){
            if(cnt.find(a) == cnt.end()) cnt[a] = p;
            else cnt[a] += p;
        }
    }
    bool ok = true;
    for(auto [a, p] : cnt){
        if(p % n != 0) ok = false;
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";
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
// https://codeforces.com/problemset/problem/1881/D