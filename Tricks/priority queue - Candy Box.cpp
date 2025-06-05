#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    map <int,int> mp, noneed;
    vector <pair<ll,ll>> v;
    ll khabona = 0;
    for(int i = 0; i < n; i++){
        int type, f; 
        cin >> type >> f;
        mp[type]++;
        if(f == 1) noneed[type]++, khabona++;
    }
    ll khabo = n - khabona;
    for(auto [x, cnt] : mp) v.push_back({cnt, noneed[x]});
    sort(v.begin(), v.end());
    // for(auto [cnt, f0] : v) cout << "(" << cnt << "," << f0 << ")\n";
    priority_queue <pair<ll,ll>> candidates;
    ll ans = 0, disi = 0;
    auto [x, y] = v.back(); v.pop_back();
    ll last = x;
    candidates.push({y, x});
    while(1){
        while(!v.empty() && v.back().first >= last){
            auto [cnt, f0] = v.back();
            v.pop_back();
            candidates.push({f0, cnt});
        }
        if(last == 0 || candidates.empty()) break;
        auto [f0, cnt] = candidates.top();
        candidates.pop();
        ans += last;
        disi += min(last, f0);
        // cout << last << " " << f0 << " " << ans << "\n";
        if(!candidates.empty()){
            last = min(last-1, candidates.top().second);
        }
        else{
            if(v.empty()) last = last-1;
            else last = min(last-1, v.back().first);
        }
    }
    cout << ans << " " << disi << "\n";
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
// https://codeforces.com/contest/1183/problem/G