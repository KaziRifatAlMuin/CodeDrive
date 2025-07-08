#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// define 3 bit xor : ai ^ bi = (ai + bi) % 3
// So, a ^ b ^ c == 0 if all same, or all distinct (0+1+2)
// Otherwise not zero, 001, 011, 002, 022
// According to problem, we need xor zero
// inverse: to make 0, 0' = 0, 1' = 2, 2' = 1

vector <int> xorr(vector <int> &a, vector <int> &b){
    vector <int> ans;
    for(int i = 0; i < a.size(); i++){
        ans.push_back((a[i] + b[i]) % 3);
    }
    return ans;
}

vector <int> inv_xorr(vector <int> &a){
    vector <int> ans;
    for(int i = 0; i < a.size(); i++){
        ans.push_back((3 - a[i]) % 3);
    }
    return ans;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector <vector<int>> v(n, vector <int>(k));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            cin >> v[i][j];
        }
    }
    map <vector<int>, int> mp;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            mp[xorr(v[i], v[j])]++;
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll cnt = mp[inv_xorr(v[i])];
        ans += (cnt * (cnt-1) / 2);
    }
    cout << ans << "\n";       
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
// https://codeforces.com/problemset/problem/1735/D