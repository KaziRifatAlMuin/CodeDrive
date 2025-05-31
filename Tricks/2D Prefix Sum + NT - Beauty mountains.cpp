#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector <vector<int>> mat(n, vector<int>(m)), pre(n+1, vector<int>(m+1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }
    string s[n];
    ll a = 0, b = 0;
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int r = 1; r <= n; r++){
        for(int c = 1; c <= m; c++){
            pre[r][c] = pre[r-1][c] + pre[r][c-1] - pre[r-1][c-1]; 
            pre[r][c] += (s[r-1][c-1] == '0' ? 1 : -1);
            if(s[r-1][c-1] == '0') a += mat[r-1][c-1];
            else b += mat[r-1][c-1];
        }
    }
    // for(int r = 1; r <= n; r++){
    //     for(int c = 1; c <= m; c++){
    //         cout << pre[r][c] << " ";
    //     }
    //     cout << "\n"; 
    // }
    vector <int> diff;
    ll g = 0;
    for(int r = 1; r <= n; r++){
        for(int c = 1; c <= m; c++){
            int rr = r + k - 1, cc = c + k - 1;
            if(rr <= n && cc <= m){
                ll subsum = pre[rr][cc] - pre[rr][c-1] - pre[r-1][cc] + pre[r-1][c-1];
                diff.push_back(abs(subsum));
                if(subsum != 0) g = __gcd(g, abs(subsum));
                // cout << rr << " " << cc << " = " << subsum << "\n";
            }
        }
    }
    ll d = abs(a - b);
    if(g == 0){
        if(d == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    else{
        if(d % g == 0) cout << "YES\n";
        else cout << "NO\n";
    }
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
// https://codeforces.com/problemset/problem/1982/D