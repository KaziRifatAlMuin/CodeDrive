#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int const mod = 1e9 + 7;

ll power(ll a, ll b) {
    ll result = 1;
    a = a % mod;
    while (b > 0){
        if (b & 1) result = (result * a) % mod;
        a = (a * a) % mod;
        b >>= 1ll;
    }
    return result;
}

ll inv(ll x){ return power(x, mod - 2);}

vector <vector<ll>> dp;
string s;


ll run(int idx, int carry){
    if(idx == 0) return 0;
    if(idx == 1) return carry;
    if(dp[idx][carry] != -1) return dp[idx][carry];
    ll op1, op2;
    if(carry == 0){
        if(s[idx] == '0'){
            op1 = 1 + run(idx - 1, 0);
            op2 = 1 + run(idx - 1, 0);
        }
        else{
            op1 = 1 + run(idx - 1, 0);
            op2 = 1 + run(idx - 1, 1);
        }
    }
    else{
        if(s[idx] == '0'){
            op1 = 1 + run(idx - 1, 0);
            op2 = 1 + run(idx - 1, 1);
        }
        else{
            op1 = 1 + run(idx - 1, 1);
            op2 = 1 + run(idx - 1, 1);
        }
    }
    return dp[idx][carry] = (((op1 + op2) % mod) * inv(2)) % mod;
}

void solve() {
    int n;
    cin >> n;
    dp.assign(n+1, vector<ll>(2, -1));
    cin >> s;
    s = '0' + s;
    cout << run(n, 0) << "\n";
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
// https://codeforces.com/contest/2082/problem/C