#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n; cin >> n;
    vector <ll> u(n), s(n), sum(n+1);
    vector <vector <ll>> team(n+2), pre(n+2);
    vector <ll> uni;
    for(int i = 0; i < n; i++) cin >> u[i], uni.push_back(u[i]);
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < n; i++){
        team[u[i]].push_back(s[i]);
    }
    sort(uni.begin(), uni.end());
    uni.erase(unique(uni.begin(), uni.end()), uni.end());
    ll maxi = 0;
    for(auto i : uni){
        sort(team[i].rbegin(), team[i].rend());
        maxi = max(maxi, (ll)team[i].size());
    }
    for(auto i : uni){
        for(ll j = 0; j < team[i].size(); j++){
            if(j == 0) pre[i].push_back(team[i][j]);
            else pre[i].push_back(pre[i][j-1] + team[i][j]);
        }
    }
    vector <ll> ans(n+1);
    for(int i = 1; i <= n; i++){
        // calculating for each k in inner loop avoids TLE
        // cause sum of all team[i].size() = n
        for(int k = 1; k <= team[i].size(); k++){
            ll lim = (team[i].size() / k) * k;
            if(lim > 0) ans[k] += pre[i][lim-1];
        }
    }
    for(int k = 1; k <= n; k++) cout << ans[k] << " ";
    cout << "\n";
}
    
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    while(t--){
        solve();
    }
    cerr << "tTime : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/1519/problem/C