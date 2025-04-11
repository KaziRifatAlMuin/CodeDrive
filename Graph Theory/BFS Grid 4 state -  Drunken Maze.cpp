#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9 + 7;

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

void solve(){
    int n, m, sr, sc, tr,tc;
    cin >> n >> m;
    char s[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> s[i][j];
            if(s[i][j] == 'S') sr = i, sc = j;
            else if(s[i][j] == 'T') tr = i,tc = j;
        }
    }
    int dist[n][m][4][4];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int d = 0; d < 4; d++){
                for(int c = 0; c < 4; c++){
                    dist[i][j][d][c] = inf;
                }
            }
        }
    }
    queue <tuple<int,int,int,int>> q;
    for(int d = 0; d < 4; d++){
        int r = sr + dr[d], c = sc + dc[d];
        if(r < 0 || r > n || c < 0 || c > m || s[r][c] == '#') continue;
        dist[r][c][d][1] = 1;
        q.push({r,c,d,1});
    }
    int ans = inf;
    while(!q.empty()){
        auto[r,c,dir,cnt] = q.front(); q.pop(); // dir direction for cnt consecutive
        int steps = dist[r][c][dir][cnt];
        if(r == tr && c == tc){ans = steps; break;}
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i], nc = c + dc[i];
            if(nr < 0 || nr > n || nc < 0 || nc > m || s[nr][nc] == '#') continue;
            int ncnt = (i == dir ? cnt + 1 : 1); // check consecutive
            if(ncnt > 3) continue;
            if(dist[nr][nc][i][ncnt] > steps + 1){
                dist[nr][nc][i][ncnt] = steps + 1; // relaxation like dijkstra
                q.push({nr, nc, i, ncnt});
            }
        }
    }
    if(ans == inf) ans = -1;
    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    // cin >> t;
    while(t--){
        solve();
    }
    cerr << "tTime : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/2041/problem/D