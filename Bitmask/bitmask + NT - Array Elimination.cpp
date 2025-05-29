#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector <int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    vector <int> cnt(32);
    int gcd = 0;
    for(int j = 0; j < 31; j++){
        for(int i = 0; i < n; i++){
            cnt[j] += ((v[i] >> j) & 1ll);
        }
        gcd = __gcd(gcd, cnt[j]);
    }
    for(int i = 1; i <= n; i++){
        if(gcd % i == 0) cout << i << " ";
    }
    cout << "\n";
}

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
https://codeforces.com/problemset/problem/1601/A