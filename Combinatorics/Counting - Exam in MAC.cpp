#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, c, x;
    cin >> n >> c;
    ll plus = 0, minus = 0, both = 0, odd = 0, even = 0;
    for(int i = 0; i < n; i++){
        cin >> x;
        plus += (x/2 + 1); // 4 -> (0,4), (1,3), (2,2)
        minus += (c - x + 1); // 2 -> (0,2), (1,3), ... (c-x,c)
        both += (x & 1 ? ++odd : ++even); // for odd previous odds, for even previous evens (inclusive)
    }
    cout << (c+1) * (c+2) / 2 - (plus + minus - both) << "\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock()-st)/CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/problemset/problem/1935/D