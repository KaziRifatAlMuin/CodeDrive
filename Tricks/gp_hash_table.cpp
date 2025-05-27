#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef long long ll;
const int N = 1e6 + 7;

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

gp_hash_table<int, bool, custom_hash> visited;



void solve(){
    ll x, y, k;
    cin >> x >> y >> k;
    if(x == y){
        cout << 0 << "\n";
        return;
    }
    queue<pair<ll,ll>> q;
    visited.clear();
    q.push({x, 0});
    while(!q.empty()){
        auto[cur, step] = q.front(); 
        q.pop();
        for(ll a = 1; a <= k; a++){
            ll mul = cur * a;
            if(mul < N && !visited[mul]){
                ll next = cur * a;
                if(next == y){
                    cout << step + 1 << "\n";
                    return;
                }
                visited[next] = true;
                q.push({next, step+1});
            }
            if(cur % a == 0 && !visited[cur/a]){
                ll next = cur / a;
                if(next == y){
                    cout << step + 1 << "\n";
                    return;
                }
                visited[next] = true;
                q.push({next, step+1});
            }
        }
    }
    cout << -1 << "\n";
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
