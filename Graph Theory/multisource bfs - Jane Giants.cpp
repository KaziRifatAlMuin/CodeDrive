#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int n, m, ans = 0;

vector<pair<int,int>> fire;
vector<vector<int>> firetime;
vector<vector<bool>> visited;
vector<vector<char>> s;

bool isvalid(int x, int y, int timer){
    if(x < 0 || y < 0 || x >= n || y >= m) return false;
    if(firetime[x][y] <= timer) return false;
    return true;
}

bool isfree(int x, int y, int timer){
    if(!isvalid(x, y, timer)) return false;
    if(x == 0 || y == 0 || x == n - 1 || y == m - 1) return true;
    return false;
}

void firebfs(){
    queue <tuple<int,int,int>> q;
    for(auto [x,y] : fire){
        q.push({x, y, 0});
    }
    while(!q.empty()){
        auto[r, c, timer] = q.front();
        timer++; q.pop();
        for(int i = 0; i < 4; i++){
            int rr = r + dr[i];
            int cc = c + dc[i];
            if(isvalid(rr, cc, timer)){
                firetime[rr][cc] = timer;
                q.push({rr, cc, timer});
            }
        }
    }
}


bool escapebfs(int sr, int sc){
    queue <tuple<int,int,int>> q;
    q.push({sr, sc, 0});
    visited[sr][sc] = true;
    while(!q.empty()){
        auto[r, c, timer] = q.front();
        timer++; q.pop();
        for(int i = 0; i < 4; i++){
            int rr = r + dr[i];
            int cc = c + dc[i];
            if(isfree(rr, cc, timer)){
                ans = timer;
                return true;
            }
            if(isvalid(rr, cc, timer) && !visited[rr][cc]){
                visited[rr][cc] = true;
                q.push({rr, cc, timer});
            }
        }
    }
    return false;
}

void solve(){
    int sr, sc;
    cin >> n >> m;
    s.assign(n, vector<char>(m,' '));
    visited.assign(n, vector<bool>(m,false));
    firetime.assign(n, vector<int>(m,0));
    fire.clear();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> s[i][j];
            if(s[i][j] == 'J') sr = i, sc = j;
            else if(s[i][j] == '#') continue;
            else if(s[i][j] == 'F') fire.push_back({i, j});
            else firetime[i][j] = INT_MAX;
        }
    }
    firebfs();
    if(sr == 0 || sr == n - 1 || sc == 0 || sc == m-1) cout << 1 << "\n";
    else if(!escapebfs(sr, sc)) cout << "IMPOSSIBLE\n";
    else cout << ans + 1 << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock(), cs = 1;
    cin >> t;
    while(t--){
        cout << "Case " << cs++ << ": ";
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://lightoj.com/problem/jane-and-the-frost-giants