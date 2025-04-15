#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4e4 + 7, mod = 1e9 + 7;

vector <int> dp;

bool check(string s){
    string r = s;
    reverse(r.begin(), r.end());
    return s == r;
}

void pre(){
    vector <int> v;
    dp.assign(N+1, 0);
    for(int i = 1; i < N; i++){
        if(check(to_string(i))) v.push_back(i);
    }
    dp[0] = 1;
    for(auto x : v){ // unbounded knapsack: ascending
        for(int i = x; i <= N; i++){
            dp[i] = (dp[i] + dp[i-x]) % mod;
        }
    }
}

void solve(){
    int n;
    cin >> n;
    cout << dp[n] << "\n";
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
// https://codeforces.com/problemset/problem/1673/C