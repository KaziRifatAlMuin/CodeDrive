#include <iostream>
#include <queue>
using namespace std;
typedef long long int ll;
int const N = 1e5 + 7;

bool vis[N];
int level[N];

int bfs(int n, int k) {
    if(n == k) return 0;
    queue<int> q; q.push(n);
    level[n] = 0; vis[n] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        int moves[] = {cur + 1, cur - 1, cur * 2};
        for(int i = 0; i < 3; ++i) {
            int next = moves[i];
            if(next >= 0 && next < N && !vis[next]) {
                q.push(next);
                level[next] = level[cur] + 1;
                vis[next] = true;
                if(next == k) return level[next];
            }
        }
    }
    return -1;
}

void solve() {
    int n, k;
    cin >> n >> k;
    cout << bfs(n,k) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) {
         solve();
    }
    return 0;
}
// https://vjudge.net/contest/663939#problem/N