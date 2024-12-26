#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
vector <vector<bool>> visited;
string s[2];
int n;

void dfs(int sr, int sc, int &cnt){
    for(int i = 0; i < 4; i++){
        int r = sr + dr[i];
        int c = sc + dc[i];
        if(r >= 0 && r <= 1 && c >= 0 && c < n && !visited[r][c] && s[r][c] == '.'){
            visited[r][c] = true;
            cnt++;
            dfs(r, c, cnt);
        }
    }
}

void solve() {
    cin >> n;
    cin >> s[0] >> s[1];
    bool ok = true;
    visited.assign(2, vector<bool>(n, 0));
    for(int i = 0; i < n - 1; i++){
        if(s[0][i] == s[1][i]) continue;
        if(s[0][i] == '.'){
            if(s[0][i+1] == '.') {s[0][i] = '#', s[0][i+1] = '#';}
            else ok = false;
        }
        else{
            if(s[1][i+1] == '.') {s[1][i] = '#', s[1][i+1] = '#';}
            else ok = false;
        }
    }

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j] && s[i][j] == '.'){
                int cnt = 1;
                visited[i][j] = true;
                dfs(i, j, cnt);
                if(cnt & 1) ok = false;
                // cout << i << " " << j << " " << cnt << "\n";
            }
            
        }
    }
    if(!ok) cout << "None\n";
    else{
        for(int i = 0; i < n - 1; i++){
            if(s[0][i] == '.' && s[1][i] == '.' && s[0][i+1] == '.' && s[1][i+1] == '.'){
                if((i > 0 && s[0][i-1] == s[1][i-1]) || i == 0){
                    cout << "Multiple\n";
                    return;
                }
            }
        }
        cout << "Unique\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
// https://codeforces.com/contest/2052/problem/F