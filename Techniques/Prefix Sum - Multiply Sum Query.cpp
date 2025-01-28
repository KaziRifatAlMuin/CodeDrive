#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int const mod = 1e9 + 7;

void solve() {
    int n, q;
    cin >> n >> q;
    vector <ll> v(n+2);
    vector <ll> row(n+2), rowsum(n+2), col(n+2), colsum(n+2);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    for(int i = n; i > 0; i--){
        row[i] = (row[i+1] + v[i-1]) % mod;
        col[i] = (v[i-1] * i) % mod;
    }

    for(int i = n; i > 0; i--){
        rowsum[i] = (rowsum[i+1] + row[i]) % mod;
        colsum[i] = (colsum[i+1] + col[i]) % mod;
    }

    // for(int i = 0; i <= n; i++){
    //     cout << row[i] << " ";
    // }
    // cout << "\n";

    // for(int i = 0; i <= n; i++){
    //     cout << rowsum[i] << " ";
    // }
    // cout << "\n";

    // for(int i = 0; i <= n; i++){
    //     cout << col[i] << " ";
    // }
    // cout << "\n";

    // for(int i = 0; i <= n ; i++){
    //     cout << colsum[i] << " ";
    // }
    // cout << "\n";


    while(q--){
        ll l, r;
        cin >> l >> r;
        ll total = rowsum[1];
        ll extrarow = (rowsum[1] - rowsum[l]);
        ll extracol = colsum[r+1];
        ll intersec = (l-1) * row[r+1];
        // cout << total << " " << extrarow << " " << extracol << " " << intersec << ": ";
        cout << ((total - extrarow - extracol + intersec) % mod + mod) % mod << "\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    // cin >> t;
    while(t--){
        solve();
    }
    // cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}

// https://maang.in/problems/Multiply-Sum-Query-36

/*
Input 1:

7 3
1 2 3 4 5 6 7
2 5
3 5
4 7

Input 2:

10 10
12 -23 -123 2345 2345 44 345 -93945 -5353 1
1 5
1 8
1 10
2 2
6 6
4 8
2 9
4 10
3 6
5 9


*/