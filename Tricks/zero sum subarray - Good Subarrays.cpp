#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    map <ll, ll> mp;
    string s; 
    cin >> s;
    ll sum = 0, ans = 0;
    mp[0] = 1;
    for(auto c : s){
        int x = c - '0';
        x--; // converting zero sub sum
        sum += x; // sum till i position
        ans += mp[sum]; // if same sum received before, that many times more it contributes 
        mp[sum]++;
    }
    // _ _ 6 _ _ 6 _ 6 _ _ _ 6 _ _ : contribution = 0 + 1 + 2 + 3 = 6
    cout << ans << "\n";
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