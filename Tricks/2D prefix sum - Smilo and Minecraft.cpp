#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    string s[n];
    vector <vector<int>> mat(n, vector<int>(m)), pre(n+1, vector<int>(m+1));
    for(int i = 0; i < n; i++){
        cin >> s[i];
        for(int j = 0; j < m; j++){
            if(s[i][j] == 'g') mat[i][j] = 1;
            else mat[i][j] = 0;
        }
    }
    for(int r = 1; r <= n; r++){
        for(int c = 1; c <= m; c++){
            pre[r][c] = pre[r-1][c] + pre[r][c-1] - pre[r-1][c-1]; 
            pre[r][c] += mat[r-1][c-1];
        }
    }
    // for(int r = 1; r <= n; r++){
    //     for(int c = 1; c <= m; c++){
    //         cout << pre[r][c] << " ";
    //     }
    //     cout << "\n"; 
    // }

    // Lambda for rectangle sum (1-based indexing)
    auto rectangleSum = [&](int r1, int c1, int r2, int c2) -> int {
        return pre[r2][c2] - pre[r1-1][c2] - pre[r2][c1-1] + pre[r1-1][c1-1];
    };

    auto isValid = [&](int r, int c) -> bool {
        return r >= 0 && c >= 0 && r < n && c < m;
    };

    ll ans = 0, total = pre[n][m];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(s[i][j] != '.') continue;
            int r = i+1, c = j+1;
            int r1 = max(1, r - k);
            int c1 = max(1, c - k);
            int r2 = min(n, r + k);
            int c2 = min(m, c + k);
            int sum = rectangleSum(r1, c1, r2, c2);
            int collect = 0;
            for(int r = i - k, c = j - k; r <= i + k; r++){
                if(isValid(r,c) && s[r][c] == 'g') collect++;
            }
            for(int r = i - k, c = j + k; r <= i + k; r++){
                if(isValid(r,c) && s[r][c] == 'g') collect++;
            }
            for(int c = j - k + 1, r = i - k; c < j + k; c++){
                if(isValid(r,c) && s[r][c] == 'g') collect++;
            }
            for(int c = j - k + 1, r = i + k; c < j + k; c++){
                if(isValid(r,c) && s[r][c] == 'g') collect++;
            }
            // cout << r << " " << c << " : " << total << " " << sum << " " << collect << "\n";
            ans = max(ans, total - sum + collect);
        }
    }
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
// https://codeforces.com/contest/2113/problem/C