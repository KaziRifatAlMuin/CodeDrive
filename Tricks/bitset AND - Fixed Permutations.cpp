#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 50007;

void solve(){
    int n, m;
    cin >> n >> m;
    vector <vector<int>> p(n+1, vector <int> (m+1));
    static bitset<N> jinish[11][11];
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= m; j++){
            jinish[i][j].reset(); // (N/64 = 782)
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> p[i][j];
            jinish[j][p[i][j]].set(i-1); // O(1)
        }
    } // O(m^2 * (N/64))

    for(int i = 1; i <= n; i++){
        int ans = 0;
        bitset<N> cur = jinish[p[i][1]][1]; // O(N/64)
        if(cur.any()) ans++;
        for(int j = 2; j <= m; j++){
            cur &= jinish[p[i][j]][j]; // O(N/64)
            if(cur.any()) ans++; // O(N/64)
            else break;
        } // O(m * (N/64))
        cout << ans << " ";
    } // O(n * m * (N/64)) = 5000 * 10 * 782
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
// https://codeforces.com/contest/1792/problem/D