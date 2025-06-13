#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k;

struct state{
    ll idx, time, dir;
    state() {}
    state(ll a, ll b, ll c){
        idx = a, time = b, dir = c;
    }
};

void solve(){
    cin >> n >> k;
    vector <ll> p(n), d(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < n; i++) cin >> d[i];

    vector<vector<vector<state>>> next(n, vector<vector<state>>(k, vector<state>(2, {-1, -1, -1})));
    for(int i = 0; i < n; i++){
        for(int t = 0; t < k; t++){
            for(int dir = 0; dir < 2; dir++){
                if((dir == 0) ^ (d[i] == t)){
                    // exactly one true, then go in +ve direction
                    if(i != n-1) next[i][t][dir] = state(i+1, (p[i+1] - p[i] + t) % k, 0); // 0 = +ve
                }
                else{
                    // both true/false, then go in -ve direction
                    if(i != 0) next[i][t][dir] = state(i-1, (p[i] - p[i-1] + t) % k, 1); // 1 = -ve
                }
            }
        }
    }

    vector<vector<vector<bool>>> ans(n, vector<vector<bool>>(k, vector<bool>(2, false)));
    vector<vector<vector<vector<state>>>> adj(n, vector<vector<vector<state>>>(k, vector<vector<state>>(2)));

    for(int i = 0; i < n; i++){
        for(int t = 0; t < k; t++){
            for(int dir = 0; dir < 2; dir++){
                if(next[i][t][dir].idx != -1){
                    auto [idx, time, direction] = next[i][t][dir];
                    adj[idx][time][direction].push_back({i, t, dir});
                }
            }
        }
    }

    queue<state> q;

    for(int i = 0; i < n; i++){
        for(int t = 0; t < k; t++){
            for(int dir = 0; dir < 2; dir++){
                if(next[i][t][dir].idx == -1){
                    q.push(state(i, t, dir));
                    ans[i][t][dir] = true;
                }
            }
        }
    }

    while (q.size())
    {
        auto v = q.front();
        q.pop();
        for (auto x : adj[v.idx][v.time][v.dir])
        {
            if (ans[x.idx][x.time][x.dir] == false)
            {
                ans[x.idx][x.time][x.dir] = true;
                q.push(state(x.idx, x.time, x.dir));
            }
        }
    }

    ll qq;
    cin >> qq;
    while(qq--){
        ll pos;
        cin >> pos;
        auto it = lower_bound(p.begin(), p.end(), pos);
        if(it == p.end())
        {
            cout << "YES\n";
            continue;
        }
        else
        {
            if (ans[it - p.begin()][(*it - pos) % k][0]) cout << "YES\n";
            else cout << "NO\n";
        }
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
// https://codeforces.com/contest/2118/problem/D1