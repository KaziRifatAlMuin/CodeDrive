#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9 + 7;

// RULD
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, -1, 0, 1};

void solve(){
    int n;
    cin >> n;
    char s[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> s[i][j];
        }
    }

    bool visited[n][n][4];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int d = 0; d < 4; d++){
                visited[i][j][d] = false;
            }
        }
    }

    queue <tuple<ll,ll,ll,ll>> q;
    q.push({0, 0, 0, 0});
    visited[0][0][0] = true;

    // BFS
    while(!q.empty()){
        auto[r,c,face,time] = q.front(); q.pop();
        if(r == n-1 && c == n-1 && face == 0){
            cout << time << "\n";
            break;
        }
        int nr = r + dr[face], nc = c + dc[face];
        if(!visited[r][c][(face+1)%4]){
            q.push({r, c, (face+1)%4, time+1});
            visited[r][c][(face+1)%4] = true;
        }
        if(nr < 0 || nr >= n || nc < 0 || nc >= n || s[nr][nc] == '#' || visited[nr][nc][face]) continue;
        q.push({nr, nc, face, time+1});
        visited[nr][nc][face] = true;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
// https://vjudge.net/problem/Gym-100739C