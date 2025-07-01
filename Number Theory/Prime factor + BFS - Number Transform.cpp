#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1007, inf = 1e9;

vector <int> divs[N+2];
vector <vector<int>> dis;

void pre(){
    vector<bool> isPrime(N+10, true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; (ll) i * i < N; i++) {
        if(isPrime[i]) {
            for(int j = i * i; j < N; j += i)
                isPrime[j] = false;
        }
    }

    for(int i = 2; i < N; i++){
        if(isPrime[i]){
            for(int j = i+i; j < N; j+= i){
                divs[j].push_back(i);
            }
        }
    }

    dis.assign(N, vector<int> (N, inf));

    for(int i = 1; i < N; i++){
        vector <bool> visited(N+2, false);
        queue <pair<int,int>> q;
        q.push({i, 0});
        dis[i][i] = 0;
        while(!q.empty()){
            auto [cur, step] = q.front();
            q.pop();
            for(auto x : divs[cur]){
                if(cur + x < N && !visited[cur+x]){
                    visited[cur+x] = true;
                    q.push({cur+x, step+1});
                    dis[i][cur+x] = min(dis[i][cur+x], step+1);
                }
            }
        }
    }
}

void solve(){
    ll x, y;
    cin >> x >> y;
    if(dis[x][y] == inf) cout << -1 << "\n";
    else cout << dis[x][y] << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock(), cs = 1;
    cin >> t;
    pre();
    while(t--){
        cout << "Case " << cs++ << ": ";
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://lightoj.com/problem/number-transformation